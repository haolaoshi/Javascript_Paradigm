BUILD=g++
FLAG=-g -O0 
all=main
main:InvokeLog.cpp user.o log.o 
	$(BUILD) $^ $(FLAG) -o $@
user.o:UserLog1.cpp
	$(BUILD) -c $^ -o $@
log.o:LogFile.cpp
	$(BUILD) -c $^  -o $@
clean:
	$(RM) *.o  main a.out
