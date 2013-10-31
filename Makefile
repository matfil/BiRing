.cpp:
	g++-4.7 -O2 -std=c++11 -Wall -Wshadow -g -o $@.e $<
tests:
clear:
	rm ./*.e
	
