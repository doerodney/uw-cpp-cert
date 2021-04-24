CC = g++
CFLAGS = -g -Wall -O3

default: unittests

unittests: Failure.o Main.o q03_07_test.o Test.o TestRegistry.o TestResult.o WFailure.o 
	$(CC) $(CFLAGS) -o unittests Failure.o Main.o q03_07_test.o Test.o TestRegistry.o TestResult.o WFailure.o 

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

q03_07_test.o: q03_07_test.cpp TestHarness.h Test.h TestResult.h \
 Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c q03_07_test.cpp

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

