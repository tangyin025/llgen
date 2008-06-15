
#include <assert.h>
#include <boost/regex.hpp>
#include "llgenerator.h"

#define T_EMPTY ""

namespace ll
{
	static const boost::regex s_reg_CHAR("'([^']|(\\.))*'", boost::regex::perl | boost::regex::icase);

	static bool is_character_symbol(const std::string & symbol)
	{
		return boost::regex_match(symbol, s_reg_CHAR);
	}

	static bool is_empty_symbol(const std::string & symbol)
	{
		return T_EMPTY == symbol;
	}

	static StringSet securityStack;

	static void insert_selection_set_inside(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar)
	{
		if(grammar.tokenSet.end() != grammar.tokenSet.find(symbolNode.first)
			|| is_character_symbol(symbolNode.first)
			|| is_empty_symbol(symbolNode.first))
		{
			selectionSet.insert(symbolNode.first);
			return;
		}

		assert(grammar.productionMap.end() != grammar.productionMap.find(symbolNode.first));

		StringSet localSet;
		if(securityStack.end() == securityStack.find(symbolNode.first))
		{
			securityStack.insert(symbolNode.first);

			const ProductionNode & productionNode = *grammar.productionMap.find(symbolNode.first);
			SymbolMap::const_iterator sym_node_iter = productionNode.second.begin();
			for(; sym_node_iter != productionNode.second.end(); sym_node_iter++)
			{
				insert_selection_set_inside(localSet, *sym_node_iter, grammar);
			}

			if(localSet.end() == localSet.find(T_EMPTY))
			{
				selectionSet.insert(localSet.begin(), localSet.end());
				return;
			}

			localSet.erase(T_EMPTY);
		}

		SymbolMap::const_iterator sym_node_iter = symbolNode.second.begin();
		for(; sym_node_iter != symbolNode.second.end(); sym_node_iter++)
		{
			insert_selection_set_inside(localSet, *sym_node_iter, grammar);
		}
		selectionSet.insert(localSet.begin(), localSet.end());
	}

	void insert_selection_set(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar)
	{
		securityStack.clear();

		insert_selection_set_inside(selectionSet, symbolNode, grammar);
	}
}
