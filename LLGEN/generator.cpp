
#include <assert.h>
#include <limits.h>
#include <sstream>
#include "generator.h"
#include "parser.h"

#include <boost/regex.hpp>

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

	static StringSet securityStack;

	static void insert_selection_set_inside(StringSet & selectionSet, const SymbolNode & symbolNode, const Grammar & grammar)
	{
		if(grammar.tokenSet.count(symbolNode.first)
			|| is_character_symbol(symbolNode.first)
			|| T_EMPTY == symbolNode.first)
		{
			selectionSet.insert(symbolNode.first);
			return;
		}

		assert(grammar.productionMap.count(symbolNode.first));

		StringSet localSet;
		if(!securityStack.count(symbolNode.first))
		{
			securityStack.insert(symbolNode.first);

			const ProductionNode & productionNode = *grammar.productionMap.find(symbolNode.first);
			SymbolMap::const_iterator sym_node_iter = productionNode.second.begin();
			for(; sym_node_iter != productionNode.second.end(); sym_node_iter++)
			{
				insert_selection_set_inside(localSet, *sym_node_iter, grammar);
			}

			if(!localSet.count(T_EMPTY))
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
	// insert_first_selection_set
	// //////////////////////////////////////////////////////////////////////////////////

	void insert_first_selection_set(StringSet & selectionSet, const std::string & symbol, const Grammar & grammar)
	{
		if(grammar.productionMap.count(symbol))
		{
			insert_selection_set(
				selectionSet,
				grammar.productionMap.find(symbol)->second.begin(),
				grammar.productionMap.find(symbol)->second.end(),
				grammar);
		}
		else
		{
			selectionSet.insert(symbol);
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
	// report_left_recursion
	// //////////////////////////////////////////////////////////////////////////////////

	typedef std::vector<std::string> StringList;

	static bool find_left_recursion(StringList & returnPath, const Grammar & grammar, const std::string & symbol)
	{
		if(grammar.tokenSet.count(symbol)
			|| is_character_symbol(symbol)
			|| T_EMPTY == symbol)
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

		assert(grammar.productionMap.count(symbol));

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

	static void output_left_recursion_path(std::ostream & ostr, const StringList & recursionPath)
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

	void report_left_recursion(std::ostream & ostr, const Grammar & grammar)
	{
		ProductionMap::const_iterator production_iter = grammar.productionMap.begin();
		for(; production_iter != grammar.productionMap.end(); production_iter++)
		{
			StringList returnPath;
			if(find_left_recursion(returnPath, grammar, production_iter->first))
			{
				output_left_recursion_path(ostr, returnPath);
			}
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// report_empty_conflict
	// //////////////////////////////////////////////////////////////////////////////////

	static void output_empty_conflict_result(
		std::ostream & ostr,
		SymbolMap::const_iterator fst_symbol_node_iter,
		SymbolMap::const_iterator sec_symbol_node_iter,
		const StringSet & intersectionSet)
	{
		assert(!intersectionSet.count(T_EMPTY));

		ostr << fst_symbol_node_iter->first << " . " << sec_symbol_node_iter->first << std::endl;

		output_selection_set(ostr, intersectionSet, 1);
	}

	static void report_empty_conflict_inside(
		std::ostream & ostr,
		SymbolMap::const_iterator fst_symbol_node_iter,
		SymbolMap::const_iterator sec_symbol_node_iter,
		const Grammar & grammar)
	{
		StringSet fst_selection_set;
		insert_first_selection_set(fst_selection_set, fst_symbol_node_iter->first, grammar);

		if(fst_selection_set.count(T_EMPTY))
		{
			fst_selection_set.erase(T_EMPTY);

			StringSet sec_selection_set;
			insert_first_selection_set(sec_selection_set, sec_symbol_node_iter->first, grammar);

			StringSet intersectionSet;
			std::set_intersection(
				fst_selection_set.begin(),
				fst_selection_set.end(),
				sec_selection_set.begin(),
				sec_selection_set.end(),
				std::inserter(intersectionSet, intersectionSet.begin()));

			if(!intersectionSet.empty())
			{
				output_empty_conflict_result(ostr, fst_symbol_node_iter, sec_symbol_node_iter, intersectionSet);
			}
		}

		SymbolMap::const_iterator new_sec_symbol_node_iter = sec_symbol_node_iter->second.begin();
		for(; new_sec_symbol_node_iter != sec_symbol_node_iter->second.end(); new_sec_symbol_node_iter++)
		{
			report_empty_conflict_inside(ostr, sec_symbol_node_iter, new_sec_symbol_node_iter, grammar);
		}
	}

	void report_empty_conflict(std::ostream & ostr, const Grammar & grammar)
	{
		ProductionMap::const_iterator production_node_iter = grammar.productionMap.begin();
		for(; production_node_iter != grammar.productionMap.end(); production_node_iter++)
		{
			SymbolMap::const_iterator fst_symbol_node_iter = production_node_iter->second.begin();
			for(; fst_symbol_node_iter != production_node_iter->second.end(); fst_symbol_node_iter++)
			{
				SymbolMap::const_iterator sec_symbol_node_iter = fst_symbol_node_iter->second.begin();
				for(; sec_symbol_node_iter != fst_symbol_node_iter->second.end(); sec_symbol_node_iter++)
				{
					report_empty_conflict_inside(ostr, fst_symbol_node_iter, sec_symbol_node_iter, grammar);
				}
			}
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
			if(!psymbolMap->count((*ast_node_iter)->getText()))
			{
				psymbolMap->insert(SymbolNode((*ast_node_iter)->getText(), SymbolMap()));
			}

			psymbolMap = &psymbolMap->find((*ast_node_iter)->getText())->second;
		}
	}

	bool convert_ast_tree_to_ll_grammar(Grammar & grammar, const AstNodePtr astRoot, std::ostream & error_report_ostr)
	{
		if("root" != astRoot->getText())
		{
			error_report_ostr << "cannot find root node" << std::endl;
			return false;
		}

		if(2 != astRoot->m_childs.size())
		{
			error_report_ostr << "ast root node must has 2 sub node" << std::endl;
			return false;
		}

		AstNodePtr astTokens = astRoot->m_childs[0];

		if("tokens" != astTokens->getText())
		{
			error_report_ostr << "cannot find tokens node" << std::endl;
			return false;
		}

		AstNodePtrList::const_iterator ast_node_iter = astTokens->m_childs.begin();
		for(; ast_node_iter != astTokens->m_childs.end(); ast_node_iter++)
		{
			grammar.tokenSet.insert((*ast_node_iter)->getText());
		}

		AstNodePtr astProductions = astRoot->m_childs[1];

		if("productions" != astProductions->getText())
		{
			error_report_ostr << "cannot find productions node" << std::endl;
			return false;
		}

		ast_node_iter = astProductions->m_childs.begin();
		for(; ast_node_iter != astProductions->m_childs.end(); ast_node_iter++)
		{
			if(!grammar.productionMap.count((*ast_node_iter)->getText()))
			{
				grammar.productionMap.insert(ProductionNode((*ast_node_iter)->getText(), SymbolMap()));
			}

			if((*ast_node_iter)->m_childs.empty())
			{
				error_report_ostr << "unsupport empty production" << std::endl;
				return false;
			}

			AstNodePtrList::const_iterator ast_symbols_iter = (*ast_node_iter)->m_childs.begin();
			for(; ast_symbols_iter != (*ast_node_iter)->m_childs.end(); ast_symbols_iter++)
			{
				if("symbols" != (*ast_symbols_iter)->getText())
				{
					error_report_ostr << "cannot find symbols node" << std::endl;
					return false;
				}

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
		return true;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// insert_selection_branch
	// //////////////////////////////////////////////////////////////////////////////////

	static void remove_from_set(StringSet & set, StringSet::const_iterator other_set_iter_begin, StringSet::const_iterator other_set_iter_end)
	{
		StringSet::const_iterator other_set_iter = other_set_iter_begin;
		for(; other_set_iter != other_set_iter_end; other_set_iter++)
		{
			assert(set.count(*other_set_iter));

			set.erase(*other_set_iter);
		}
	}

	void insert_selection_branch(SelectionBranchList & selectionBranchList, const StringSet & selectionSet, const SymbolNode & symbolNode)
	{
		StringSet remainSet(selectionSet);

		SelectionBranchList::iterator branch_iter = selectionBranchList.begin();
		for(; branch_iter != selectionBranchList.end(); branch_iter++)
		{
			StringSet intersectionSet;
			std::set_intersection(branch_iter->selectionSet.begin(), branch_iter->selectionSet.end(),
				remainSet.begin(), remainSet.end(), std::inserter(intersectionSet, intersectionSet.begin()));

			if(!intersectionSet.empty())
			{
				branch_iter->branches.push_back(&symbolNode);
			}

			remove_from_set(remainSet, intersectionSet.begin(), intersectionSet.end());
		}

		if(!remainSet.empty())
		{
			selectionBranchList.push_back(SelectionBranch());

			selectionBranchList.back().selectionSet = remainSet;

			selectionBranchList.back().branches.push_back(&symbolNode);
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_production_func
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_symbol_node_simple(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolNode & symbolNode,
		const Grammar & grammar,
		const int indent,
		const int deepth)
	{
		if(T_EMPTY == symbolNode.first)
		{
			output_indent(ostr, indent);
			ostr << "if(" << function_prefix << "_shift_EMPTY(tokens, token_i, node" << deepth << "))" << std::endl;
		}		
		else if(grammar.tokenSet.count(symbolNode.first)
			|| is_character_symbol(symbolNode.first))
		{
			output_indent(ostr, indent);
			ostr << "if(" << function_prefix << "_shift_token<" << symbolNode.first << ">(tokens, token_i, node" << deepth << "))" << std::endl;
		}
		else
		{
			output_indent(ostr, indent);
			ostr << "if(" << function_prefix << "_" << symbolNode.first << "(tokens, token_i, node" << deepth << "))" << std::endl;
		}

		output_indent(ostr, indent);
		ostr << "{" << std::endl;

		output_parser_symbol_node_layer(ostr, function_prefix, symbolNode.second.begin(), symbolNode.second.end(), grammar, indent + 1, deepth + 1);

		output_indent(ostr, indent);
		ostr << "}" << std::endl;
	}

	void output_parser_symbol_node_plist(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolNodePList::const_iterator psym_node_begin,
		const SymbolNodePList::const_iterator psym_node_end,
		const Grammar & grammar,
		const int indent,
		const int deepth)
	{
		assert(psym_node_begin != psym_node_end);

		SymbolNodePList::const_iterator psym_node_iter = psym_node_begin;
		for(; psym_node_iter != psym_node_end; psym_node_iter++)
		{
			if(psym_node_iter != psym_node_begin)
			{
				ostr << std::endl;

				output_indent(ostr, indent);
				ostr << "token_i = current_i;" << std::endl;
			}

			output_parser_symbol_node_simple(ostr, function_prefix, **psym_node_iter, grammar, indent, deepth);
		}
	}

	void output_parser_symbol_node_case(
		std::ostream & ostr,
		const StringSet::const_iterator selection_set_begin,
		const StringSet::const_iterator selection_set_end,
		const int indent)
	{
		StringSet::const_iterator selection_set_iter = selection_set_begin;
		for(; selection_set_iter != selection_set_end; selection_set_iter++)
		{
			if(T_EMPTY == *selection_set_iter)
			{
				output_indent(ostr, indent);
				ostr << "default:" << std::endl;
			}
			else
			{
				output_indent(ostr, indent);
				ostr << "case " << *selection_set_iter << ":" << std::endl;
			}
		}
	}

	bool have_empty_selection(
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end)
	{
		SelectionBranchList::const_iterator selection_branch_iter = selection_branch_begin;
		for(; selection_branch_iter != selection_branch_end; selection_branch_iter++)
		{
			if(selection_branch_iter->selectionSet.count(T_EMPTY))
			{
				return true;
			}
		}
		return false;
	}

	void output_parser_symbol_node_switch(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end,
		const Grammar & grammar,
		const int indent,
		const int deepth)
	{
		output_indent(ostr, indent);
		ostr << "switch(GET_TOKEN_ID(tokens, token_i))" << std::endl;

		output_indent(ostr, indent);
		ostr << "{" << std::endl;

		SelectionBranchList::const_iterator selection_branch_iter = selection_branch_begin;
		for(; selection_branch_iter != selection_branch_end; selection_branch_iter++)
		{
			if(selection_branch_iter != selection_branch_begin)
			{
				ostr << std::endl;
			}

			output_parser_symbol_node_case(
				ostr, selection_branch_iter->selectionSet.begin(), selection_branch_iter->selectionSet.end(), indent);

			output_parser_symbol_node_plist(
				ostr, function_prefix, selection_branch_iter->branches.begin(), selection_branch_iter->branches.end(), grammar, indent + 1, deepth);

			output_indent(ostr, indent + 1);
			ostr << "break;" << std::endl;
		}

		if(!have_empty_selection(selection_branch_begin, selection_branch_end))
		{
			assert(selection_branch_end != selection_branch_begin);
			ostr << std::endl;

			output_indent(ostr, indent);
			ostr << "default:" << std::endl;

			output_indent(ostr, indent + 1);
			ostr << "REPORT_SWITCH_ERROR(tokens, token_i);" << std::endl;
		}

		output_indent(ostr, indent);
		ostr << "}" << std::endl;
	}

	bool find_multi_branch(
		const SelectionBranchList::const_iterator selection_branch_begin,
		const SelectionBranchList::const_iterator selection_branch_end)
	{
		SelectionBranchList::const_iterator selection_branch_iter = selection_branch_begin;
		for(; selection_branch_iter != selection_branch_end; selection_branch_iter++)
		{
			if(selection_branch_iter->branches.size() > 1)
			{
				return true;
			}
		}
		return false;
	}

	void output_parser_symbol_node_layer(
		std::ostream & ostr,
		const std::string & function_prefix,
		const SymbolMap::const_iterator sym_node_begin,
		const SymbolMap::const_iterator sym_node_end,
		const Grammar & grammar,
		const int indent,
		const int deepth /*= 1*/)
	{
		if(sym_node_begin == sym_node_end)
		{
			output_indent(ostr, indent);
			ostr << "return true;" << std::endl;
			return;
		}

		output_indent(ostr, indent);
		ostr << "node_t node" << deepth << ";" << std::endl;

		if(1 == std::distance(sym_node_begin, sym_node_end))
		{
			output_parser_symbol_node_simple(ostr, function_prefix, *sym_node_begin, grammar, indent, deepth);

			if(1 == deepth)
			{
				output_indent(ostr, indent);
				ostr << "return false;" << std::endl;
			}
			return;
		}

		SelectionBranchList selectionBranchList;
		SymbolMap::const_iterator sym_node_iter = sym_node_begin;
		for(; sym_node_iter != sym_node_end; sym_node_iter++)
		{
			StringSet selectionSet;
			insert_selection_set(selectionSet, *sym_node_iter, grammar);
			insert_selection_branch(selectionBranchList, selectionSet, *sym_node_iter);
		}

		if(find_multi_branch(selectionBranchList.begin(), selectionBranchList.end()))
		{
			output_indent(ostr, indent);
			ostr << "int current_i = token_i;" << std::endl;

			output_parser_symbol_node_switch(
				ostr, function_prefix, selectionBranchList.begin(), selectionBranchList.end(), grammar, indent, deepth);

			if(1 == deepth)
			{
				output_indent(ostr, indent);
				ostr << "return false;" << std::endl;
			}
		}
		else
		{
			output_parser_symbol_node_switch(
				ostr, function_prefix, selectionBranchList.begin(), selectionBranchList.end(), grammar, indent, deepth);

			if(1 == deepth)
			{
				output_indent(ostr, indent);
				ostr << "return false;" << std::endl;
			}
		}
	}

	void output_parser_production_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const ProductionNode & production,
		const Grammar & grammar,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "bool " << function_prefix << "_" << production.first << "(const token_t * tokens, int & token_i, node_t & node)" << std::endl;

		output_indent(ostr, indent);
		ostr << "{" << std::endl;

		output_parser_symbol_node_layer(ostr, function_prefix, production.second.begin(), production.second.end(), grammar, indent + 1);

		output_indent(ostr, indent);
		ostr << "}" << std::endl;
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_cpp_source
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_shift_EMPTY_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "bool " << function_prefix << "_shift_EMPTY(const token_t * tokens, int & token_i, node_t & node)" << std::endl;

		output_indent(ostr, indent);
		ostr << "{" << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "return true;" << std::endl;

		output_indent(ostr, indent);
		ostr << "}" << std::endl;
	}

	void output_parser_shift_token_func(
		std::ostream & ostr,
		const std::string & function_prefix,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "template <int TOKEN_ID>" << std::endl;

		output_indent(ostr, indent);
		ostr << "bool " << function_prefix << "_shift_token(const token_t * tokens, int & token_i, node_t & node)" << std::endl;

		output_indent(ostr, indent);
		ostr << "{" << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "if(TOKEN_ID == GET_TOKEN_ID(tokens, token_i))" << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "{" << std::endl;

		output_indent(ostr, indent + 2);
		ostr << "token_i++;" << std::endl;

		output_indent(ostr, indent + 2);
		ostr << "return true;" << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "}" << std::endl;

		ostr << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID);" << std::endl;

		output_indent(ostr, indent + 1);
		ostr << "return false;" << std::endl;

		output_indent(ostr, indent);
		ostr << "}" << std::endl;
	}

	void output_parser_production_comment(
		std::ostream & ostr,
		const AstNodePtr astProduction,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "/******************************************************************************************" << std::endl;

		output_indent(ostr, indent);
		ostr << " * " << astProduction->getText() << std::endl;

		AstNodePtrList::const_iterator ast_symbol_list_iter = astProduction->m_childs.begin();
		for(; ast_symbol_list_iter != astProduction->m_childs.end(); ast_symbol_list_iter++)
		{
			assert("symbols" == (*ast_symbol_list_iter)->getText());

			output_indent(ostr, indent);
			ostr << " * ";

			output_indent(ostr, 1);
			if((*ast_symbol_list_iter)->m_childs.empty())
			{
				ostr << S_EMPTY;
			}
			else
			{
				AstNodePtrList::const_iterator ast_symbol_iter = (*ast_symbol_list_iter)->m_childs.begin();
				for(; ast_symbol_iter != (*ast_symbol_list_iter)->m_childs.end(); ast_symbol_iter++)
				{
					ostr << (*ast_symbol_iter)->getText();
					ostr << " ";
				}
			}
			ostr << std::endl;
		}

		output_indent(ostr, indent);
		ostr << " ******************************************************************************************/" << std::endl;
	}

	void output_parser_cpp_source(
		std::ostream & ostr,
		const std::string & function_prefix,
		const std::string & header_file,
		const AstNodePtr astRoot,
		const Grammar & grammar)
	{
		ostr << std::endl;

		if(!header_file.empty())
		{
			ostr << "#include \"" << header_file << "\"" << std::endl;

			ostr << std::endl;
		}

		ostr << "#define GET_TOKEN_ID(tokens, token_i) tokens[token_i]" << std::endl;

		ostr << std::endl;

		ostr << "#define REPORT_SHIFT_ERROR(tokens, token_i, TOKEN_ID)" << std::endl;

		ostr << std::endl;

		ostr << "#define REPORT_SWITCH_ERROR(tokens, token_i)" << std::endl;

		ostr << std::endl;

		output_parser_shift_EMPTY_func(ostr, function_prefix);

		ostr << std::endl;

		output_parser_shift_token_func(ostr, function_prefix);

		ostr << std::endl;

		assert(2 == astRoot->m_childs.size());

		AstNodePtr astProductions = astRoot->m_childs[1];

		assert("productions" == astProductions->getText());

		AstNodePtrList::const_iterator ast_production_iter = astProductions->m_childs.begin();
		for(; ast_production_iter != astProductions->m_childs.end(); ast_production_iter++)
		{
			assert(grammar.productionMap.count((*ast_production_iter)->getText()));

			if(ast_production_iter != astProductions->m_childs.begin())
			{
				ostr << std::endl;
			}

			output_parser_production_comment(ostr, *ast_production_iter);

			ostr << std::endl;

			output_parser_production_func(ostr, function_prefix, *grammar.productionMap.find((*ast_production_iter)->getText()), grammar);
		}
	}

	// //////////////////////////////////////////////////////////////////////////////////
	// output_parser_cpp_header
	// //////////////////////////////////////////////////////////////////////////////////

	void output_parser_cpp_header_guard_begin(
		std::ostream & ostr,
		const std::string & definite_header,
		const Grammar & grammar,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "#ifndef " << definite_header << std::endl;

		output_indent(ostr, indent);
		ostr << "#define " << definite_header << std::endl;

		return;
		grammar;
	}

	void output_parser_cpp_header_guard_end(
		std::ostream & ostr,
		const std::string & definite_header,
		const Grammar & grammar,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "#endif //" << definite_header << std::endl;

		return;
		grammar;
	}

	void output_parser_token_definition(
		std::ostream & ostr,
		const std::string & token_name,
		const size_t token_value,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "#define " << token_name << " " << token_value << std::endl;
	}

	void output_parser_token_definition_list(
		std::ostream & ostr,
		AstNodePtrList::const_iterator ast_token_begin,
		AstNodePtrList::const_iterator ast_token_end,
		const int indent /*= 0*/)
	{
		AstNodePtrList::const_iterator ast_token_iter = ast_token_begin;
		for(; ast_token_iter != ast_token_end; ast_token_iter++)
		{
			output_parser_token_definition(ostr, (*ast_token_iter)->getText(), std::distance(ast_token_begin, ast_token_iter) + UCHAR_MAX + 1, indent);
		}
	}

	void output_parser_typedef_definition(
		std::ostream & ostr,
		const std::string & old_type_name,
		const std::string & new_type_name,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "typedef " << old_type_name << " " << new_type_name << ";" << std::endl;
	}

	void output_parser_production_func_definition(
		std::ostream & ostr,
		const std::string & function_prefix,
		const ProductionNode & production,
		const Grammar & grammar,
		const int indent /*= 0*/)
	{
		output_indent(ostr, indent);
		ostr << "bool " << function_prefix << "_" << production.first << "(const token_t * tokens, int & token_i, node_t & node);" << std::endl;

		return;
		grammar;
	}

	void output_parser_cpp_header(
		std::ostream & ostr,
		const std::string & function_prefix,
		const std::string & definite_header,
		const AstNodePtr astRoot,
		const Grammar & grammar)
	{
		ostr << std::endl;

		output_parser_cpp_header_guard_begin(ostr, definite_header, grammar);

		assert(2 == astRoot->m_childs.size());

		AstNodePtr astTokens = astRoot->m_childs[0];

		assert("tokens" == astTokens->getText());

		ostr << std::endl;

		output_parser_token_definition_list(ostr, astTokens->m_childs.begin(), astTokens->m_childs.end());

		ostr << std::endl;

		output_parser_typedef_definition(ostr, "int", "token_t");

		ostr << std::endl;

		output_parser_typedef_definition(ostr, "void *", "node_t");

		AstNodePtr astProductions = astRoot->m_childs[1];

		assert("productions" == astProductions->getText());

		ostr << std::endl;

		AstNodePtrList::const_iterator ast_production_iter = astProductions->m_childs.begin();
		for(; ast_production_iter != astProductions->m_childs.end(); ast_production_iter++)
		{
			assert(grammar.productionMap.count((*ast_production_iter)->getText()));

			output_parser_production_func_definition(ostr, function_prefix, *grammar.productionMap.find((*ast_production_iter)->getText()), grammar);
		}

		ostr << std::endl;

		output_parser_cpp_header_guard_end(ostr, definite_header, grammar);
	}
}
