
#include <iostream>
#include "llgenerator.h"
#include "parser.h"

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

extern FILE * yyin;

extern int yylex(void);

extern char * yytext;

extern int lineno;

extern int columnno;

int main(int argc, char ** argv)
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif

	for(int i = 1; i < argc; i++)
	{
		std::string fname = argv[i];

		// open input file
		yyin = fopen(fname.c_str(), "r");
		if(NULL == yyin)
		{
			std::cerr << "cannot open " << fname << std::endl;
			exit(1);
		}

		// lex tokens
		ll::AstTokenList tokens;
		for(int type = yylex(); type != 0; type = yylex())
		{
			tokens.push_back(ll::AstToken(type, yytext, lineno, columnno));
		}
		tokens.push_back(ll::AstToken(0, "", 0, 0));

		// parser syntax
		int token_i = 0;
		ll::AstNodePtr ast_root;
		if(!cpp_parser_translate_unit(&tokens[0], token_i, ast_root))
		{
			ll::report_last_error(std::cerr);
			exit(1);
		}

		// output ast tree
		ll::output_ast_node(std::cout, ast_root);

		// convert ast tree 2 grammar
		ll::Grammar grammar;
		ll::convert_ast_tree_to_ll_grammar(grammar, ast_root);

		// check left-recursion
		ll::ProductionMap::const_iterator production_iter = grammar.productionMap.begin();
		for(; production_iter != grammar.productionMap.end(); production_iter++)
		{
			ll::StringList returnPath;
			if(ll::find_left_recursion(returnPath, grammar, production_iter->first))
			{
				ll::report_left_recursion_path(std::cout, returnPath);
			}
		}

		/*
		 * output selection set
		 */
		/*ll::ProductionMap::const_iterator*/ production_iter = grammar.productionMap.begin();
		for(; production_iter != grammar.productionMap.end(); production_iter++)
		{
			ll::StringSet selectionSet;
			ll::insert_selection_set(selectionSet, production_iter->second.begin(), production_iter->second.end(), grammar);

			std::cout << "FIRST(" << production_iter->first << "):" << std::endl;
			ll::output_selection_set(std::cout, selectionSet, 1);
		}
	}

	return 0;
}
