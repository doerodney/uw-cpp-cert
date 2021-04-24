CC = g++
CFLAGS = -g -Wall -O3 -std=c++17

default: unittests

unittests: assgt02_test.o Failure.o Main.o Test.o TestRegistry.o TestResult.o WFailure.o 
	$(CC) $(CFLAGS) -o unittests assgt02_test.o Failure.o Main.o Test.o TestRegistry.o TestResult.o WFailure.o 

assgt02_test.o: assgt02_test.cpp TestHarness.h Test.h TestResult.h \
 Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c assgt02_test.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp


clean:
	$(RM) unittests *.o

