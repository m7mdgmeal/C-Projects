CC=g++
CFLAGS= -ansi -std=c++03 -g -Wall -Werror -pedantic -Wconversion
INCLUDE:= -Iheaders/
SOURCE:=source/my_time.cpp \
		source/my_timer.cpp \
		source/msg_printer.cpp \
		tests_folder/main.cpp \

EXE= tests

all:
$(EXE):
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o $(EXE)
clean:
	rm $(EXE)  