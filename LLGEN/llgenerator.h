
#ifndef __LLGENERATOR_H__
#define __LLGENERATOR_H__

#include <string>
#include <map>
#include <set>
#include <vector>

namespace ll
{
	class SymbolMap : public std::map<std::string, SymbolMap>
	{
	};

	typedef SymbolMap::value_type SymbolNode;

	class ProductionMap : public std::map<std::string, SymbolMap>
	{
	};

	typedef ProductionMap::value_type ProductionNode;

	typedef std::set<std::string> StringSet;

	class Grammar
	{
	public:
		StringSet tokenSet;

		ProductionMap productionMap;
	};

	typedef std::vector<std::string> StringList;

	void insert_selection_set(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar);
}

#endif // __LLGENERATOR_H__
