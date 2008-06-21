
%{
#include <io.h>
#include <iostream>
#include "parser.h"

int nextcolumnno = 1;

int columnno = nextcolumnno;

int lineno = 1;

#define YY_USER_ACTION \
	{\
		columnno = nextcolumnno;\
		nextcolumnno += yyleng;\
	}

%}

%%

"\n"							{ lineno++; columnno = nextcolumnno = 1; }

[\t\f\v\r ]+

"%%"							{ return PERCENTPERCENT; }

"%token"						{ return PERCENTTOKEN; }

"%"[a-z]+						{ return PERCENTOTHER; }

[a-zA-Z_][a-zA-Z_0-9]*			{ return IDENTIFIER; }

"'"([^']|(\\.))*"'"				{ return CHARACTER; }

":"								{ return ':'; }

"|"								{ return '|'; }

";"								{ return ';'; }

.								{ std::cerr << "unexpected character: '" << (char)yytext[0] << "'" << std::endl; }

%%

int yywrap(void)
{
	return 1;
}
