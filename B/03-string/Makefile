CC=g++
FLAGS=-g -O0 -I"../../tools"
main:SmallString.cpp  memtest.o
	$(CC) $^  $(FLAGS) -o  $@
memtest.o: ../../tools/MemCheck.cpp
	$(CC) -c $^  -o  $@
clean:
	$(RM) main  *.o
