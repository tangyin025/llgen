
all: libboost_program_options.a libboost_regex.a llgen.exe cppparser.exe

libboost_program_options.a:
	(cd libboost_program_options && make)
	
libboost_regex.a:
	(cd libboost_regex && make)

llgen.exe:
	(cd LLGEN && make)

cppparser.exe:
	(cd CPPParser && make)

.PHONE: clean
clean: clean_libboost_program_options clean_libboost_regex clean_llgen clean_cppparser

clean_libboost_program_options:
	(cd libboost_program_options && make clean)
	
clean_libboost_regex:
	(cd libboost_regex && make clean)

clean_llgen:
	(cd LLGEN && make clean)

clean_cppparser:
	(cd CPPParser && make clean)

lexer.cpp: llgen_lexer cppparser_lexer

llgen_lexer:
	(cd LLGEN && make lexer.cpp)

cppparser_lexer:
	(cd CPPParser && make lexer.cpp)

