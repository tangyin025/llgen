
all: libboost_program_options.a

libboost_program_options.a: cmdline.o config_file.o convert.o options_description.o parsers.o positional_options.o utf8_codecvt_facet.o value_semantic.o variables_map.o winmain.o
	ar rvs libboost_program_options.a cmdline.o config_file.o convert.o options_description.o parsers.o positional_options.o utf8_codecvt_facet.o value_semantic.o variables_map.o winmain.o

cmdline.o: cmdline.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c cmdline.cpp

config_file.o: config_file.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c config_file.cpp

convert.o: convert.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c convert.cpp

options_description.o: options_description.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c options_description.cpp

parsers.o: parsers.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c parsers.cpp

positional_options.o: positional_options.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c positional_options.cpp

utf8_codecvt_facet.o: utf8_codecvt_facet.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c utf8_codecvt_facet.cpp

value_semantic.o: value_semantic.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c value_semantic.cpp

variables_map.o: variables_map.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c variables_map.cpp

winmain.o: winmain.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c winmain.cpp
	
.PHONY: clean
clean:
	-rm *.o libboost_program_options.a
