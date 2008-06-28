
all: lexer.cpp

clean:
	rm lexer.cpp

lexer.cpp: lexer.l
	flex -olexer.cpp lexer.l