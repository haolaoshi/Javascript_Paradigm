CC=g++
FLAGS=-g -O0 -I"../../../tools" 
all=main
main:MemTest.cpp MemCheck.o
	$(CC) $^  $(FLAGS) -o $@
MemCheck.o:../../../tools/MemCheck.cpp
	$(CC) -c $^ -o $@
clean:
	$(RM) main  *.o
