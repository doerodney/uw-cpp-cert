CC = g++
CFLAGS = -g -Wall -O3 -std=c++17

default: unittests

unittests: dynarray.o Failure.o Main.o probe.o ptxy.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o 
	$(CC) $(CFLAGS) -o unittests dynarray.o Failure.o Main.o probe.o ptxy.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o 

dynarray.o: dynarray.cpp dynarray.h
	$(CC) $(CFLAGS) -c dynarray.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

probe.o: probe.cpp probe.h
	$(CC) $(CFLAGS) -c probe.cpp

ptxy.o: ptxy.cpp ptxy.h probe.h
	$(CC) $(CFLAGS) -c ptxy.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

unittests.o: unittests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h ptxy.h probe.h
	$(CC) $(CFLAGS) -c unittests.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp


clean:
	$(RM) unittests *.o

