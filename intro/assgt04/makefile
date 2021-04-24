CC = g++
CFLAGS = -g -Wall -O3 -std=c++17

default: unittests

unittests: assgt04_test.o Failure.o Main.o Test.o TestRegistry.o TestResult.o WFailure.o write.o write_test.o 
	$(CC) $(CFLAGS) -o unittests assgt04_test.o Failure.o Main.o Test.o TestRegistry.o TestResult.o WFailure.o write.o write_test.o 

assgt04_test.o: assgt04_test.cpp TestHarness.h Test.h TestResult.h \
 Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c assgt04_test.cpp

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

write.o: write.cpp write.h
	$(CC) $(CFLAGS) -c write.cpp

write_test.o: write_test.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h write.h
	$(CC) $(CFLAGS) -c write_test.cpp


clean:
	$(RM) unittests *.o

