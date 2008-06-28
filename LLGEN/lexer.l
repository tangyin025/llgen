
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

void skip_comment_line(void);
	
void skip_comment_stream(void);

%}

%%

"\n"							{ lineno++; columnno = nextcolumnno = 1; }

[\t\f\v\r ]+

"//"							{ skip_comment_line(); }

"/*"							{ skip_comment_stream(); }

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

void skip_comment_line(void)
{
	char c;
	do
	{
		c = yyinput();
	}
	while(c != EOF && c != '\n');
	lineno++;
}

void skip_comment_stream(void)
{
	char c[2];
	c[1] = 0;
	do
	{
		c[0] = c[1];
		c[1] = yyinput();

		if(c[1] == '\n')
		{
			lineno++;
		}
	}
	while(c[1] != EOF && !(c[0] == '*' && c[1] == '/'));
}
