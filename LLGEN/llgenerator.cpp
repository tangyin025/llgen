
#include <assert.h>
#include <limits.h>
#include <sstream>
#include <boost/regex.hpp>
#include "llgenerator.h"
#include "parser.h"

namespace ll
{
	// //////////////////////////////////////////////////////////////////////////////////
	// output_ast_node
	// //////////////////////////////////////////////////////////////////////////////////

	void static output_indent(std::ostream & ostr, int indent)
	{
		for(int i = 0; i < indent; i++)
		{
			ostr << "    ";
		}
	}

	void output_ast_node(std::ostream & ostr, AstNodePtr node, int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << node->getText() << std::endl;

		AstNodePtrList::const_iterator node_iter = node->m_childs.begin();
		for(; node_iter != node->m_childs.end(); node_iter++)
		{
			output_ast_node(ostr, *node_iter, indent + 1);
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// token_type_to_str
	// //////////////////////////////////////////////////////////////////////////////////

	std::string token_type_to_str(int token)
	{
		switch(token)
		{
		case PERCENTPERCENT:
			return "%%";
		case PERCENTTOKEN:
			return "%token";
		case PERCENTOTHER:
			return "%other";
		case IDENTIFIER:
			return "IDENTIFIER";
		case CHARACTER:
			return "CHARACTER";
		default:
			break;
		}

		std::ostringstream osstr;
		if(token >= CHAR_MIN && token <= CHAR_MAX)
		{
			osstr << (char)token;
			return osstr.str();
		}

		osstr << "unknown token: " << token;
		return osstr.str();
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// set_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	static std::string g_err_msg;

	static const AstToken * g_err_ptoken = NULL;

	void set_last_error(const std::string & msg, const AstToken * ptoken)
	{
		assert(NULL != ptoken);

		assert(NULL == g_err_ptoken);

		g_err_msg = msg;

		g_err_ptoken = ptoken;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// set_last_error_except_existed
	// //////////////////////////////////////////////////////////////////////////////////

	void set_last_error_except_existed(const std::string & msg, const AstToken * ptoken)
	{
		if(NULL == g_err_ptoken)
		{
			set_last_error(msg, ptoken);
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// clear_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	void clear_last_error(void)
	{
		g_err_ptoken = NULL;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// report_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	void report_last_error(std::ostream & ostr)
	{
		assert(NULL != g_err_ptoken);

		ostr << g_err_msg << ": " << g_err_ptoken->getLine() << ", " << g_err_ptoken->getColumn() << ", '" << g_err_ptoken->getText() << "'" << std::endl;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// insert_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

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

	void insert_selection_set(StringSet & selectionSet, SymbolMap::const_iterator symbolNodeBegin, SymbolMap::const_iterator symbolNodeEnd, const Grammar & grammar)
	{
		securityStack.clear();

		SymbolMap::const_iterator sym_node_iter = symbolNodeBegin;
		for(; sym_node_iter != symbolNodeEnd; sym_node_iter++)
		{
			insert_selection_set_inside(selectionSet, *sym_node_iter, grammar);
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// output_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void output_selection_set(std::ostream & ostr, const StringSet & selectionSet, int indent)
	{
		StringSet::const_iterator sym_iter = selectionSet.begin();
		for(; sym_iter != selectionSet.end(); sym_iter++)
		{
			output_indent(ostr, indent);
			ostr << (T_EMPTY == *sym_iter ? S_EMPTY : *sym_iter) << std::endl;
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// find_left_recursion
	// //////////////////////////////////////////////////////////////////////////////////

	bool find_left_recursion(StringList & returnPath, const Grammar & grammar, const std::string & symbol)
	{
		if(grammar.tokenSet.end() != grammar.tokenSet.find(symbol)
			|| is_character_symbol(symbol)
			|| is_empty_symbol(symbol))
		{
			return false;
		}

		if(returnPath.end() != std::find(returnPath.begin(), returnPath.end(), symbol))
		{
			if(symbol == returnPath.front())
			{
				returnPath.push_back(symbol);
				return true;
			}

			// NOTE: do not check sub left-recursion
			return false;
		}

		assert(grammar.productionMap.end() != grammar.productionMap.find(symbol));

		returnPath.push_back(symbol);

		const ProductionNode & productionNode = *grammar.productionMap.find(symbol);
		SymbolMap::const_iterator sym_node_iter = productionNode.second.begin();
		for(; sym_node_iter != productionNode.second.end(); sym_node_iter++)
		{
			StringList localPath(returnPath.begin(), returnPath.end());
			if(find_left_recursion(localPath, grammar, sym_node_iter->first))
			{
				returnPath = localPath;
				return true;
			}
		}
		return false;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// report_left_recursion_path
	// //////////////////////////////////////////////////////////////////////////////////

	void report_left_recursion_path(std::ostream & ostr, const StringList & recursionPath)
	{
		assert(recursionPath.size() >= 1);

		StringList::const_iterator sym_iter = recursionPath.begin();
		ostr << *sym_iter << std::endl;
		sym_iter++;

		for(; sym_iter != recursionPath.end(); sym_iter++)
		{
			ostr << " -> " << *sym_iter << std::endl;
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// convert_ast_tree_to_ll_grammar
	// //////////////////////////////////////////////////////////////////////////////////

	static void insert_symbol_node(SymbolMap & symbolMap, AstNodePtrList::const_iterator astNodeBegin, AstNodePtrList::const_iterator astNodeEnd)
	{
		AstNodePtrList::const_iterator ast_node_iter = astNodeBegin;
		SymbolMap * psymbolMap = &symbolMap;
		for(; ast_node_iter != astNodeEnd; ast_node_iter++)
		{
			if(psymbolMap->end() == psymbolMap->find((*ast_node_iter)->getText()))
			{
				psymbolMap->insert(SymbolNode((*ast_node_iter)->getText(), SymbolMap()));
			}

			psymbolMap = &psymbolMap->find((*ast_node_iter)->getText())->second;
		}
	}

	void convert_ast_tree_to_ll_grammar(Grammar & grammar, const AstNodePtr astRoot)
	{
		assert("root" == astRoot->getText());

		assert(2 == astRoot->m_childs.size());

		AstNodePtr astTokens = astRoot->m_childs[0];

		assert("tokens" == astTokens->getText());

		AstNodePtrList::const_iterator ast_node_iter = astTokens->m_childs.begin();
		for(; ast_node_iter != astTokens->m_childs.end(); ast_node_iter++)
		{
			grammar.tokenSet.insert((*ast_node_iter)->getText());
		}

		AstNodePtr astProductions = astRoot->m_childs[1];

		assert("productions" == astProductions->getText());

		ast_node_iter = astProductions->m_childs.begin();
		for(; ast_node_iter != astProductions->m_childs.end(); ast_node_iter++)
		{
			if(grammar.productionMap.end() == grammar.productionMap.find((*ast_node_iter)->getText()))
			{
				grammar.productionMap.insert(ProductionNode((*ast_node_iter)->getText(), SymbolMap()));
			}

			AstNodePtrList::const_iterator ast_symbols_iter = (*ast_node_iter)->m_childs.begin();
			for(; ast_symbols_iter != (*ast_node_iter)->m_childs.end(); ast_symbols_iter++)
			{
				assert("symbols" == (*ast_symbols_iter)->getText());

				if(!(*ast_symbols_iter)->m_childs.empty())
				{
					insert_symbol_node(
						grammar.productionMap.find((*ast_node_iter)->getText())->second, (*ast_symbols_iter)->m_childs.begin(), (*ast_symbols_iter)->m_childs.end());
				}
				else
				{
					grammar.productionMap.find((*ast_node_iter)->getText())->second.insert(SymbolNode(T_EMPTY, SymbolMap()));
				}
			}
		}
	}
}
