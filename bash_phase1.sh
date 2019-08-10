#!/bin/bash
g++ -ansi -std=c++03 -Wall -Werror -pedantic -Wconversion -c my_time.cpp testphase1.cpp
g++ -ansi -std=c++03 -Wall -Werror -pedantic -Wconversion -o run my_time.o testphase1.o
valgrind ./run

