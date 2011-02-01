
all: cppparser.exe

cppparser.exe: lexer.o main.o parser.o
	g++ -o cppparser.exe lexer.o main.o parser.o

lexer.o: lexer.cpp
	g++ -c lexer.cpp

lexer.cpp: lexer.l
	flex -olexer.cpp lexer.l

main.o: main.cpp
	g++ -c main.cpp

parser.o: parser.cpp
	g++ -c parser.cpp

.PHONY: clean
clean:
	-rm *.o lexer.cpp cppparser.exe
