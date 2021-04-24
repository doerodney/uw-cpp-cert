CC = g++
CFLAGS = -g -Wall -O3 -std=c++17

default: unittests

unittests: Circle.o Failure.o Main.o Point.o Rectangle.o Test.o TestRegistry.o TestResult.o Triangle.o unitests.o WFailure.o 
	$(CC) $(CFLAGS) -o unittests Circle.o Failure.o Main.o Point.o Rectangle.o Test.o TestRegistry.o TestResult.o Triangle.o unitests.o WFailure.o 

Circle.o: Circle.cpp Circle.h Point.h Shape.h
	$(CC) $(CFLAGS) -c Circle.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

Point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) -c Point.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Point.h Shape.h
	$(CC) $(CFLAGS) -c Rectangle.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

Triangle.o: Triangle.cpp Triangle.h Point.h Shape.h
	$(CC) $(CFLAGS) -c Triangle.cpp

unitests.o: unitests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Shape.h Point.h Triangle.h Rectangle.h
	$(CC) $(CFLAGS) -c unitests.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp


clean:
	$(RM) unittests *.o

