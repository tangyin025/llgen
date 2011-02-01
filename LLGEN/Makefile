
all: llgen.exe

llgen.exe: generator.o lexer.o main.o parser.o
	g++ -o llgen.exe generator.o lexer.o main.o parser.o -lboost_regex-mt -lboost_program_options-mt

generator.o: generator.cpp generator.h parser.h
	g++ -c generator.cpp

lexer.o: lexer.cpp
	g++ -c lexer.cpp

lexer.cpp: lexer.l
	flex -olexer.cpp lexer.l

main.o: main.cpp generator.h parser.h
	g++ -c main.cpp

parser.o: parser.cpp parser.h
	g++ -c parser.cpp

.PHONY: clean
clean:
	-rm *.o lexer.cpp llgen.exe
