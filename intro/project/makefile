CC = g++
CFLAGS = -g -Wall -O3 -std=c++17

default: unittests

unittests: CircleFitter.o Failure.o GeometricFeatureFitter.o LineFitter.o Main.o mathutils.o matrix.o Point.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o 
	$(CC) $(CFLAGS) -o unittests CircleFitter.o Failure.o GeometricFeatureFitter.o LineFitter.o Main.o mathutils.o matrix.o Point.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o 

CircleFitter.o: CircleFitter.cpp CircleFitter.h GeometricFeatureFitter.h \
 Point.h mathutils.h
	$(CC) $(CFLAGS) -c CircleFitter.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

GeometricFeatureFitter.o: GeometricFeatureFitter.cpp \
 GeometricFeatureFitter.h Point.h
	$(CC) $(CFLAGS) -c GeometricFeatureFitter.cpp

LineFitter.o: LineFitter.cpp LineFitter.h GeometricFeatureFitter.h \
 Point.h mathutils.h
	$(CC) $(CFLAGS) -c LineFitter.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

mathutils.o: mathutils.cpp mathutils.h
	$(CC) $(CFLAGS) -c mathutils.cpp

matrix.o: matrix.cpp matrix.h
	$(CC) $(CFLAGS) -c matrix.cpp

Point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) -c Point.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

unittests.o: unittests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h LineFitter.h GeometricFeatureFitter.h Point.h \
 mathutils.h matrix.h
	$(CC) $(CFLAGS) -c unittests.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp


clean:
	$(RM) unittests *.o

