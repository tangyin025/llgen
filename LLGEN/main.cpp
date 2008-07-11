
#include <iostream>
#include <fstream>
#include "generator.h"
#include "parser.h"

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#pragma warning(push)
#pragma warning(disable: 4127) // warning C4127: conditional expression is constant
#pragma warning(disable: 4511) // warning C4511: 'class' : copy constructor could not be generated
#pragma warning(disable: 4512) // warning C4512: 'class' : assignment operator could not be generated
#pragma warning(disable: 4819) // warning C4819: The file contains a character that cannot be represented in the current code page (932). Save the file in Unicode format to prevent data loss
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/program_options.hpp>
#pragma warning(pop)

extern FILE * yyin;

extern int yylex(void);

extern char * yytext;

extern int lineno;

extern int columnno;

typedef std::vector<std::string> StringList;

static const boost::regex s_reg_NON_CHAR("[^a-zA-Z]", boost::regex::perl | boost::regex::icase);

static std::string build_local_file_name(const std::string & fname)
{
	std::string::size_type pos = boost::algorithm::replace_all_copy(fname, "\\", "/").find_last_of('/');
	pos = std::string::npos == pos ? 0 : pos + 1;
	return fname.substr(pos);
}

static std::string build_definite_header(const std::string & fname)
{
	std::string format = "_";
	std::string ret = boost::algorithm::to_upper_copy(boost::algorithm::replace_all_regex_copy(fname, s_reg_NON_CHAR, format));
	return "__" + ret + "__";
}

int main(int argc, char ** argv)
{

#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif

	// build program option descriptions
	std::string opt;
	boost::program_options::options_description desc("llgen options");
	desc.add_options()
		("ast-tree,A", "output ast tree to std::cout")
		("left-recursion,L", "output left recursion to std::cout")
		("empty_conflict,E", "output empty conflict to std::cout")
		("first-selection,F", "output first selection to std::cout")
		("header-file,H", boost::program_options::value<std::string>(), "specify output header file")
		("source-file,S", boost::program_options::value<std::string>(), "specify output source file")
		("function-prefix,P", boost::program_options::value<std::string>(&opt)->default_value("ll_parser"), "specify function prefix for source")
		("input-file", boost::program_options::value<StringList>(), "input files");
		;

	// build program option positional description
	boost::program_options::positional_options_description posDesc;
	posDesc.add("input-file", 1);

	// store comman line argument to variables map
	boost::program_options::variables_map vmap;
	boost::program_options::store(
		boost::program_options::command_line_parser(argc, argv).options(desc).positional(posDesc).run(), vmap);
	boost::program_options::notify(vmap);

	if(argc <= 1 || !vmap.count("input-file"))
	{
		// output error message
		std::cerr << desc << std::endl;
	}
	else
	{
		// iterator all input files and build ll grammar
		StringList inputFileList = vmap["input-file"].as<StringList>();
		StringList::const_iterator input_file_iter = inputFileList.begin();
		ll::AstNodePtr astRoot;
		ll::Grammar llGrammar;
		for(; input_file_iter != inputFileList.end(); input_file_iter++)
		{
			// open input file
			yyin = fopen(input_file_iter->c_str(), "r");
			if(NULL == yyin)
			{
				std::cerr << "cannot open " << *input_file_iter << std::endl;
				exit(1);
			}

			// lexer input file
			ll::AstTokenList tokens;
			for(int type = yylex(); type != 0; type = yylex())
			{
				tokens.push_back(ll::AstToken(type, yytext, lineno, columnno));
			}
			tokens.push_back(ll::AstToken(0, "", 0, 0));

			// parser syntax
			int token_i = 0;
			if(!ll_parser_translate_unit(&tokens[0], token_i, astRoot))
			{
				ll::report_last_error(std::cerr);
				exit(1);
			}

			// convert ast tree to grammar
			if(!ll::convert_ast_tree_to_ll_grammar(llGrammar, astRoot, std::cerr))
			{
				exit(1);
			}

			// close input file
			fclose(yyin);
		}

		// output ast tree
		if(vmap.count("ast-tree"))
		{
			ll::output_ast_node(std::cout, astRoot);
		}

		// check and report left-recursion
		if(vmap.count("left-recursion"))
		{
			ll::report_left_recursion(std::cout, llGrammar);
		}

		// check and report empty-conflict
		if(vmap.count("empty_conflict"))
		{
			ll::report_empty_conflict(std::cout, llGrammar);
		}

		// output selection set
		if(vmap.count("first-selection"))
		{
			ll::ProductionMap::const_iterator production_iter = llGrammar.productionMap.begin();
			for(; production_iter != llGrammar.productionMap.end(); production_iter++)
			{
				ll::StringSet selectionSet;
				ll::insert_first_selection_set(selectionSet, production_iter->first, llGrammar);

				std::cout << "FIRST(" << production_iter->first << "):" << std::endl;
				ll::output_selection_set(std::cout, selectionSet, 1);
			}
		}

		assert(vmap.count("function-prefix"));
		std::string functionPrefix = vmap["function-prefix"].as<std::string>();

		// output header file
		std::string localHeaderFileName;
		if(vmap.count("header-file"))
		{
			assert(vmap.count("function-prefix"));
			std::string headerFileName = vmap["header-file"].as<std::string>();
			std::ofstream ofstrHeader(headerFileName.c_str());
			localHeaderFileName = build_local_file_name(headerFileName);
			if(ofstrHeader)
			{
				ll::output_parser_cpp_header(
					ofstrHeader,
					functionPrefix,
					build_definite_header(localHeaderFileName),
					astRoot,
					llGrammar);
			}
		}

		// output source file
		if(vmap.count("source-file"))
		{
			std::string sourceFileName = vmap["source-file"].as<std::string>();
			std::ofstream ofstrSource(sourceFileName.c_str());
			if(ofstrSource)
			{
				ll::output_parser_cpp_source(
					ofstrSource,
					functionPrefix,
					localHeaderFileName,
					astRoot,
					llGrammar);
			}
		}
	}
	return 0;
}
