
all: lexer.cpp

lexer.cpp: lexer.l
	flex -olexer.cpp lexer.l