
all: llgen.exe

llgen.exe: generator.o lexer.o main.o parser.o
	g++ -o llgen.exe generator.o lexer.o main.o parser.o -L../libboost_program_options -L../libboost_regex -lboost_regex -lboost_program_options

generator.o: generator.cpp generator.h parser.h
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c generator.cpp

lexer.o: lexer.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c lexer.cpp

lexer.cpp: lexer.l
	flex -olexer.cpp lexer.l

main.o: main.cpp generator.h parser.h
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c main.cpp

parser.o: parser.cpp parser.h
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c parser.cpp

.PHONY: clean
clean:
	-rm *.o lexer.cpp llgen.exe
