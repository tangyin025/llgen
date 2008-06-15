
#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include <string>
#include <map>
#include <set>
#include <vector>

#define T_EMPTY ""

namespace ll
{
	class SymbolMap : public std::map<std::string, SymbolMap>
	{
	};

	typedef std::set<std::string> StringSet;

	class Grammar
	{
	public:
		StringSet tokenSet;

		SymbolMap symbolMap;
	};

	typedef std::vector<std::string> StringList;

	void insert_selection_set(StringSet & selectionSet, const StringList & previousSelectionList, const SymbolMap & symbolMap, const Grammar & grammar);
}

#endif // __GENERATOR_H__
