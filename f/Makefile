CC=g++
CFLAGS= -ansi -std=c++03 -g -Wall -Werror -pedantic -Wconversion
INCLUDE:= -Iheaders/
SOURCE:= cpps/my_time.cpp \
		 cpps/msg_printer.cpp \
		 cpps/my_timer.cpp  \
		 cpps/main.cpp
VARGIEN=valgrind ./run
EXE= RUN_TESTER

all: $(EXE)
$(EXE):
	$(CC) $(INCLUDE) $(CFLAGS) -c $(SOURCE)
	$(CC) $(INCLUDE) $(CFLAGS) -o $(SOURCE)
	$(VARGIEN)