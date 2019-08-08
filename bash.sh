#!/bin/bash
g++ -ansi -std=c++98 -Wall -Werror -pedantic -Wconversion -c test.cpp
g++ -ansi -std=c++98 -Wall -Werror -pedantic -Wconversion -o run test.o
valgrind ./run


