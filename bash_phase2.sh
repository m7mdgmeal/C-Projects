#!/bin/bash
g++ -ansi -std=c++03 -Wall -Werror -pedantic -Wconversion -c my_time.cpp msg_printer.cpp my_timer.cpp  main.cpp
g++ -ansi -std=c++03 -Wall -Werror -pedantic -Wconversion -o run my_time.o msg_printer.o my_timer.o main.o
valgrind ./run


