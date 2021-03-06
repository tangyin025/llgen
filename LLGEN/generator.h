
#ifndef __GENERATOR_H__
#define __GENERATOR_H__

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
	// insert_first_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void insert_first_selection_set(
		StringSet & selectionSet,
		StringSet & securityStack,
		const std::string & symbolName,
		const Grammar & grammar);

	void insert_first_selection_set(
		StringSet & selectionSet,
		StringSet & securityStack,
		const SymbolNode & symbolNode,
		const Grammar & grammar);

	void insert_first_selection_set(
		StringSet & selectionSet,
		StringSet & securityStack,
		SymbolMap::const_iterator symbol_node_begin,
		SymbolMap::const_iterator symbol_node_end,
		const Grammar & grammar);

	//// //////////////////////////////////////////////////////////////////////////////////
	//// insert_last_selection_set
	//// //////////////////////////////////////////////////////////////////////////////////

	//void insert_last_selection_set(
	//	StringSet & selectionSet,
	//	StringSet & securityStack,
	//	const std::string & symbolName,
	//	const Grammar & grammar);

	//void insert_last_selection_set(
	//	StringSet & selectionSet,
	//	StringSet & securityStack,
	//	const SymbolNode & symbolNode,
	//	const Grammar & grammar);

	//void insert_last_selection_set(
	//	StringSet & selectionSet,
	//	StringSet & securityStack,
	//	SymbolMap::const_iterator symbol_node_begin,
	//	SymbolMap::const_iterator symbol_node_end,
	//	const Grammar & grammar);

	//// //////////////////////////////////////////////////////////////////////////////////
	//// insert_selection_set
	//// //////////////////////////////////////////////////////////////////////////////////

	//void insert_selection_set(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar);

	//void insert_selection_set(StringSet & selectionSet, SymbolMap::const_iterator symbolNodeBegin, SymbolMap::const_iterator symbolNodeEnd, const Grammar & grammar);

	//void insert_first_selection_set(StringSet & selectionSet, const std::string & symbol, const Grammar & grammar);

	// //////////////////////////////////////////////////////////////////////////////////
	// output_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void output_selection_set(std::ostream & ostr, const StringSet & selectionSet, int indent);

	// //////////////////////////////////////////////////////////////////////////////////
	// report_left_recursion
	// //////////////////////////////////////////////////////////////////////////////////

	void report_left_recursion(std::ostream & ostr, const Grammar & grammar);

	// //////////////////////////////////////////////////////////////////////////////////
	// report_empty_conflict
	// //////////////////////////////////////////////////////////////////////////////////

	void report_empty_conflict(std::ostream & ostr, const Grammar & grammar);

	// //////////////////////////////////////////////////////////////////////////////////
	// convert_ast_tree_to_ll_grammar
	// //////////////////////////////////////////////////////////////////////////////////

	bool convert_ast_tree_to_ll_grammar(Grammar & grammar, const AstNodePtr astRoot, std::ostream & error_report_ostr);

	// //////////////////////////////////////////////////////////////////////////////////
	// SelectionBranch
	// //////////////////////////////////////////////////////////////////////////////////

	typedef std::vector<const SymbolNode *> SymbolNodePList;

	class SelectionBranch
	{
	public:
		StringSet selectionSet;

		SymbolNodePList branches;
	};

	typedef std::vector<SelectionBranch> SelectionBranchList;

	// //////////////////////////////////////////////////////////////////////////////////
	// insert_selection_branch
	// //////////////////////////////////////////////////////////////////////////////////

	void insert_selection_branch(SelectionBranchList & selectionBranchList, const StringSet & selectionSet, const SymbolNode & symbolNode);

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_production_func
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_symbol_node_simple(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolNode & symbolNode,
		const Grammar & grammar,
		const int indent,
		const int deepth);

	void output_parser_symbol_node_plist(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolNodePList::const_iterator psym_node_begin,
		const SymbolNodePList::const_iterator psym_node_end,
		const Grammar & grammar,
		const int indent,
		const int deepth);

	void output_parser_symbol_node_case(
		std::ostream & ostr,
		const StringSet::const_iterator selection_set_begin,
		const StringSet::const_iterator selection_set_end,
		const int indent);

	bool have_empty_selection(
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end);

	void output_parser_symbol_node_switch(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end,
		const Grammar & grammar,
		const int indent,
		const int deepth);

	bool find_multi_branch(
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end);

	void output_parser_symbol_node_layer(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolMap::const_iterator sym_node_begin,
		const SymbolMap::const_iterator sym_node_end,
		const Grammar & grammar,
		const int indent,
		const int deepth = 1);

	void output_parser_production_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const ProductionNode & production,
		const Grammar & grammar,
		const int indent = 0);

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_cpp_source
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_shift_EMPTY_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const int indent = 0);

	void output_parser_shift_token_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const int indent = 0);

	void output_parser_production_comment(
		std::ostream & ostr,
		const AstNodePtr astProduction,
		const int indent = 0);

	void output_parser_cpp_source(
		std::ostream & ostr,
		const std::string & function_prefix,
		const std::string & header_file,
		const AstNodePtr astRoot,
		const Grammar & grammar);

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_cpp_header
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_cpp_header_guard_begin(
		std::ostream & ostr,
		const std::string & definite_header,
		const Grammar & grammar,
		const int indent = 0);

	void output_parser_cpp_header_guard_end(
		std::ostream & ostr,
		const std::string & definite_header,
		const Grammar & grammar,
		const int indent = 0);

	void output_parser_token_definition(
		std::ostream & ostr,
		const std::string & token_name,
		const size_t token_value,
		const int indent = 0);

	void output_parser_token_definition_list(
		std::ostream & ostr,
		AstNodePtrList::const_iterator ast_token_begin,
		AstNodePtrList::const_iterator ast_token_end,
		const int indent = 0);

	void output_parser_typedef_definition(
		std::ostream & ostr,
		const std::string & old_type_name,
		const std::string & new_type_name,
		const int indent = 0);

	void output_parser_production_func_definition(
		std::ostream & ostr,
		const std::string & function_prefix,
		const ProductionNode & production,
		const Grammar & grammar,
		const int indent = 0);

	void output_parser_cpp_header(
		std::ostream & ostr,
		const std::string & function_prefix,
		const std::string & definite_header,
		const AstNodePtr astRoot,
		const Grammar & grammar);
}

#endif // __GENERATOR_H__
