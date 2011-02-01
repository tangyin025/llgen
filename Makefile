
all: llgen.exe cppparser.exe

llgen.exe:
	(cd LLGEN && make)

cppparser.exe:
	(cd CPPParser && make)

.PHONE: clean
clean: clean_llgen clean_cppparser

clean_llgen:
	(cd LLGEN && make clean)

clean_cppparser:
	(cd CPPParser && make clean)

lexer.cpp: llgen_lexer cppparser_lexer

llgen_lexer:
	(cd LLGEN && make lexer.cpp)

cppparser_lexer:
	(cd CPPParser && make lexer.cpp)

