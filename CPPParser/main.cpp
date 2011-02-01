
#include <iostream>
#include <vector>
#include <limits.h>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
#include "parser.h"

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

extern FILE * yyin;

extern int yylex(void);

extern char * yytext;

extern int lineno;

extern int columnno;

class AstToken
{
public:
	std::string m_text;

	int m_line;

	int m_column;

	AstToken(const std::string & text, int line, int column)
		: m_text(text)
		, m_line(line)
		, m_column(column)
	{
	}
};

std::string token_to_str(int tokenID)
{
	switch(tokenID)
	{
	case IDENTIFIER:
		return "IDENTIFIER";
	case INTEGER:
		return "INTEGER";
	case FLOATING:
		return "FLOATING";
	case CHARACTER:
		return "CHARACTER";
	case STRING:
		return "STRING";
	case TYPEDEF_NAME:
		return "TYPEDEF_NAME";
	case NAMESPACE_NAME:
		return "NAMESPACE_NAME";
	case CLASS_NAME:
		return "CLASS_NAME";
	case ENUM_NAME:
		return "ENUM_NAME";
	case TEMPLATE_NAME:
		return "TEMPLATE_NAME";
	case ELLIPSIS:
		return "ELLIPSIS";
	case COLONCOLON:
		return "COLONCOLON";
	case DOTSTAR:
		return "DOTSTAR";
	case ADDEQ:
		return "ADDEQ";
	case SUBEQ:
		return "SUBEQ";
	case MULEQ:
		return "MULEQ";
	case DIVEQ:
		return "DIVEQ";
	case MODEQ:
		return "MODEQ";
	case XOREQ:
		return "XOREQ";
	case ANDEQ:
		return "ANDEQ";
	case OREQ:
		return "OREQ";
	case SL:
		return "SL";
	case SR:
		return "SR";
	case SREQ:
		return "SREQ";
	case SLEQ:
		return "SLEQ";
	case EQ:
		return "EQ";
	case NOTEQ:
		return "NOTEQ";
	case LTEQ:
		return "LTEQ";
	case GTEQ:
		return "GTEQ";
	case ANDAND:
		return "ANDAND";
	case OROR:
		return "OROR";
	case PLUSPLUS:
		return "PLUSPLUS";
	case MINUSMINUS:
		return "MINUSMINUS";
	case ARROWSTAR:
		return "ARROWSTAR";
	case ARROW:
		return "ARROW";
	case ASM:
		return "ASM";
	case AUTO:
		return "AUTO";
	case BOOL:
		return "BOOL";
	case BREAK:
		return "BREAK";
	case CASE:
		return "CASE";
	case CATCH:
		return "CATCH";
	case CHAR:
		return "CHAR";
	case CLASS:
		return "CLASS";
	case CONST:
		return "CONST";
	case CONST_CAST:
		return "CONST_CAST";
	case CONTINUE:
		return "CONTINUE";
	case DEFAULT:
		return "DEFAULT";
	case DELETE:
		return "DELETE";
	case DO:
		return "DO";
	case DOUBLE:
		return "DOUBLE";
	case DYNAMIC_CAST:
		return "DYNAMIC_CAST";
	case ELSE:
		return "ELSE";
	case ENUM:
		return "ENUM";
	case EXPLICIT:
		return "EXPLICIT";
	case EXPORT:
		return "EXPORT";
	case EXTERN:
		return "EXTERN";
	case FALSE:
		return "FALSE";
	case FLOAT:
		return "FLOAT";
	case FOR:
		return "FOR";
	case FRIEND:
		return "FRIEND";
	case GOTO:
		return "GOTO";
	case IF:
		return "IF";
	case INLINE:
		return "INLINE";
	case INT:
		return "INT";
	case LONG:
		return "LONG";
	case MUTABLE:
		return "MUTABLE";
	case NAMESPACE:
		return "NAMESPACE";
	case NEW:
		return "NEW";
	case OPERATOR:
		return "OPERATOR";
	case PRIVATE:
		return "PRIVATE";
	case PROTECTED:
		return "PROTECTED";
	case PUBLIC:
		return "PUBLIC";
	case REGISTER:
		return "REGISTER";
	case REINTERPRET_CAST:
		return "REINTERPRET_CAST";
	case RETURN:
		return "RETURN";
	case SHORT:
		return "SHORT";
	case SIGNED:
		return "SIGNED";
	case SIZEOF:
		return "SIZEOF";
	case STATIC:
		return "STATIC";
	case STATIC_CAST:
		return "STATIC_CAST";
	case STRUCT:
		return "STRUCT";
	case SWITCH:
		return "SWITCH";
	case TEMPLATE:
		return "TEMPLATE";
	case THIS:
		return "THIS";
	case THROW:
		return "THROW";
	case TRUE:
		return "TRUE";
	case TRY:
		return "TRY";
	case TYPEDEF:
		return "TYPEDEF";
	case TYPEID:
		return "TYPEID";
	case TYPENAME:
		return "TYPENAME";
	case UNION:
		return "UNION";
	case UNSIGNED:
		return "UNSIGNED";
	case USING:
		return "USING";
	case VIRTUAL:
		return "VIRTUAL";
	case VOID:
		return "VOID";
	case VOLATILE:
		return "VOLATILE";
	case WCHAR_T:
		return "WCHAR_T";
	case WHILE:
		return "WHILE";
	default:
		break;
	}

	std::ostringstream osstr;
	if(tokenID >= 0 && tokenID <= CHAR_MAX)
	{
		osstr << (char)tokenID;
	}
	else
	{
		osstr << "unknown token: " << tokenID;
	}
	return osstr.str();
}

static const token_t * s_tokens = NULL;
static int s_token_i = 0;
static std::vector<int> s_tokenIDs;

static std::string s_file;
static int s_line;

void set_switch_error(const token_t * tokens, int token_i, const std::string & file, int line)
{
	//if(NULL == s_tokens)
	{
		s_tokens = tokens;
		s_token_i = token_i;
		s_tokenIDs.clear();

		s_file = file;
		s_line = line;
	}
}

void set_shift_error(const token_t * tokens, int token_i, int TOKEN_ID, const std::string & file, int line)
{
	//if(NULL == s_tokens)
	{
		set_switch_error(tokens, token_i, file, line);
		s_tokenIDs.push_back(TOKEN_ID);
	}
}

int main(int argc, char ** argv)
{

#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
#endif

	for(int i = 1; i < argc; i++)
	{
		yyin = fopen(argv[i], "r");
		if(NULL == yyin)
		{
			std::cerr << "cannot open " << argv[i] << std::endl;
			exit(1);
		}

		std::vector<int> tokens;
		std::vector<AstToken> astTokens;
		for(int tokenID = yylex(); tokenID != 0; tokenID = yylex())
		{
			tokens.push_back(tokenID);
			astTokens.push_back(AstToken(yytext, lineno, columnno));
		}
		tokens.push_back(0);
		astTokens.push_back(AstToken("EOF", lineno, columnno));

		int token_i = 0;
		void * root = NULL;
		if(!cpp_parser_translation_unit(&tokens[0], token_i, root))
		{
			assert(NULL != s_tokens);
			std::cerr << "syntax error: "
				<< argv[i]
				<< "("
				<< astTokens[s_token_i].m_line
				<< ": "
				<< astTokens[s_token_i].m_column
				<< "): unknown "
				<< token_to_str(tokens[s_token_i])
				<< " '"
				<< astTokens[s_token_i].m_text
				<< "'";

			if(!s_tokenIDs.empty())
			{
				std::cerr << ", need '" << token_to_str(s_tokenIDs.front()) << "'";
			}
			std::cerr << std::endl;

			std::cerr << "report at: " << s_file << "(" << s_line << ")" << std::endl;
			exit(1);
		}

		fclose(yyin);
		std::cout << "parser " << argv[i] << " succeed" << std::endl;
	}
	return 0;
}
