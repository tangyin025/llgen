
all: libboost_regex.a

libboost_regex.a: c_regex_traits.o cpp_regex_traits.o cregex.o fileiter.o icu.o instances.o posix_api.o regex.o regex_debug.o regex_raw_buffer.o regex_traits_defaults.o static_mutex.o usinstances.o w32_regex_traits.o wc_regex_traits.o wide_posix_api.o winstances.o
	ar rvs libboost_regex.a c_regex_traits.o cpp_regex_traits.o cregex.o fileiter.o icu.o instances.o posix_api.o regex.o regex_debug.o regex_raw_buffer.o regex_traits_defaults.o static_mutex.o usinstances.o w32_regex_traits.o wc_regex_traits.o wide_posix_api.o winstances.o
	
c_regex_traits.o: c_regex_traits.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c c_regex_traits.cpp

cpp_regex_traits.o: cpp_regex_traits.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c cpp_regex_traits.cpp

cregex.o: cregex.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c cregex.cpp

fileiter.o: fileiter.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c fileiter.cpp

icu.o: icu.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c icu.cpp

instances.o: instances.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c instances.cpp

posix_api.o: posix_api.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c posix_api.cpp

regex.o: regex.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c regex.cpp

regex_debug.o: regex_debug.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c regex_debug.cpp

regex_raw_buffer.o: regex_raw_buffer.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c regex_raw_buffer.cpp

regex_traits_defaults.o: regex_traits_defaults.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c regex_traits_defaults.cpp

static_mutex.o: static_mutex.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c static_mutex.cpp

usinstances.o: usinstances.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c usinstances.cpp

w32_regex_traits.o: w32_regex_traits.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c w32_regex_traits.cpp

wc_regex_traits.o: wc_regex_traits.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c wc_regex_traits.cpp

wide_posix_api.o: wide_posix_api.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c wide_posix_api.cpp

winstances.o: winstances.cpp
	g++ -I /cygdrive/d/Program\ Files\ \(2\)/boost_1_34_1/ -c winstances.cpp

.PHONY: clean
clean:
	-rm *.o libboost_regex.a
