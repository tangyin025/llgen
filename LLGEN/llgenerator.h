
#ifndef __LLGENERATOR_H__
#define __LLGENERATOR_H__

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <map>
#include <set>

#define T_EMPTY ""
#define S_EMPTY "<<empty>>"

namespace ll
{
	// //////////////////////////////////////////////////////////////////////////////////
	// AstToken
	// //////////////////////////////////////////////////////////////////////////////////

	class AstToken
	{
	protected:
		int m_type;

		std::string m_text;

		int m_line;

		int m_column;

	public:
		AstToken(int type, const std::string & text, int line, int column)
			: m_type(type)
			, m_text(text)
			, m_line(line)
			, m_column(column)
		{
		}

		int getType(void) const
		{
			return m_type;
		}

		const std::string & getText(void) const
		{
			return m_text;
		}

		int getLine(void) const
		{
			return m_line;
		}

		int getColumn(void) const
		{
			return m_column;
		}
	};

	typedef std::vector<AstToken> AstTokenList;

	// //////////////////////////////////////////////////////////////////////////////////
	// AstNode
	// //////////////////////////////////////////////////////////////////////////////////

	class AstNode;

	typedef boost::shared_ptr<AstNode> AstNodePtr;

	typedef std::vector<AstNodePtr> AstNodePtrList;

	class AstNode
	{
	protected:
		std::string m_text;

		const AstToken * m_ptoken;

	public:
		AstNodePtrList m_childs;

	public:
		AstNode(const std::string & text, const AstToken * ptoken = NULL)
			: m_text(text)
			, m_ptoken(ptoken)
		{
		}

		const std::string & getText(void) const
		{
			return m_text;
		}

		const AstToken * getTokenP(void) const
		{
			return m_ptoken;
		}

		void pushChild(AstNodePtr child)
		{
			m_childs.push_back(child);
		}

		void pushChildList(AstNodePtrList::const_iterator child_iter_begin, AstNodePtrList::const_iterator child_iter_end)
		{
			m_childs.insert(m_childs.end(), child_iter_begin, child_iter_end);
		}
	};

	// //////////////////////////////////////////////////////////////////////////////////
	// output_ast_node
	// //////////////////////////////////////////////////////////////////////////////////

	void output_ast_node(std::ostream & ostr, AstNodePtr node, int indent = 0);

	// //////////////////////////////////////////////////////////////////////////////////
	// token_type_to_str
	// //////////////////////////////////////////////////////////////////////////////////

	std::string token_type_to_str(int token);

	// //////////////////////////////////////////////////////////////////////////////////
	// set_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	void set_last_error(const std::string & msg, const AstToken * ptoken);

	// //////////////////////////////////////////////////////////////////////////////////
	// set_last_error_except_existed
	// //////////////////////////////////////////////////////////////////////////////////

	void set_last_error_except_existed(const std::string & msg, const AstToken * ptoken);

	// //////////////////////////////////////////////////////////////////////////////////
	// clear_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	void clear_last_error(void);

	// //////////////////////////////////////////////////////////////////////////////////
	// report_last_error
	// //////////////////////////////////////////////////////////////////////////////////

	void report_last_error(std::ostream & ostr);

	// //////////////////////////////////////////////////////////////////////////////////
	// SymbolMap
	// //////////////////////////////////////////////////////////////////////////////////

	class SymbolMap : public std::map<std::string, SymbolMap>
	{
	};

	typedef SymbolMap::value_type SymbolNode;

	// //////////////////////////////////////////////////////////////////////////////////
	// ProductionMap
	// //////////////////////////////////////////////////////////////////////////////////

	class ProductionMap : public std::map<std::string, SymbolMap>
	{
	};

	typedef ProductionMap::value_type ProductionNode;

	typedef std::set<std::string> StringSet;

	// //////////////////////////////////////////////////////////////////////////////////
	// Grammar
	// //////////////////////////////////////////////////////////////////////////////////

	class Grammar
	{
	public:
		StringSet tokenSet;

		ProductionMap productionMap;
	};

	// //////////////////////////////////////////////////////////////////////////////////
	// insert_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void insert_selection_set(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar);

	void insert_selection_set(StringSet & selectionSet, SymbolMap::const_iterator symbolNodeBegin, SymbolMap::const_iterator symbolNodeEnd, const Grammar & grammar);

	// //////////////////////////////////////////////////////////////////////////////////
	// output_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void output_selection_set(std::ostream & ostr, const StringSet & selectionSet, int indent);

	// //////////////////////////////////////////////////////////////////////////////////
	// find_left_recursion
	// //////////////////////////////////////////////////////////////////////////////////

	typedef std::vector<std::string> StringList;

	bool find_left_recursion(StringList & returnPath, const Grammar & grammar, const std::string & symbol);

	// //////////////////////////////////////////////////////////////////////////////////
	// report_left_recursion_path
	// //////////////////////////////////////////////////////////////////////////////////

	void report_left_recursion_path(std::ostream & ostr, const StringList & recursionPath);

	// //////////////////////////////////////////////////////////////////////////////////
	// convert_ast_tree_to_ll_grammar
	// //////////////////////////////////////////////////////////////////////////////////

	void convert_ast_tree_to_ll_grammar(Grammar & grammar, AstNodePtr astRoot);
}

#endif // __LLGENERATOR_H__
