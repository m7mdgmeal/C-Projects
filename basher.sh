#!/bin/bash

make tests
valgrind ./tests
make clean