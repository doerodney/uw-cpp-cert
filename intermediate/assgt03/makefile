CC = g++
CFLAGS = -g -Wall -O3 -std=c++2a

default: unittests

unittests: Arrow.o Bat.o Cave.o Denizen.o Dungeon.o Failure.o Hunter.o Pit.o TestCave.o Test.o TestRegistry.o TestResult.o UnitTestHuntTheWumpus.o unittests.o WFailure.o Wumpus.o 
	$(CC) $(CFLAGS) -o unittests Arrow.o Bat.o Cave.o Denizen.o Dungeon.o Failure.o Hunter.o Pit.o TestCave.o Test.o TestRegistry.o TestResult.o UnitTestHuntTheWumpus.o unittests.o WFailure.o Wumpus.o 

Arrow.o: Arrow.cpp Arrow.h Denizen.h
	$(CC) $(CFLAGS) -c Arrow.cpp

Bat.o: Bat.cpp Bat.h Denizen.h Cave.h Context.h Dungeon.h \
 RandomProvider.h
	$(CC) $(CFLAGS) -c Bat.cpp

Cave.o: Cave.cpp Cave.h Denizen.h
	$(CC) $(CFLAGS) -c Cave.cpp

Denizen.o: Denizen.cpp Denizen.h
	$(CC) $(CFLAGS) -c Denizen.cpp

Dungeon.o: Dungeon.cpp Dungeon.h Denizen.h Cave.h Context.h \
 RandomProvider.h Bat.h Wumpus.h Hunter.h Pit.h Arrow.h \
 GameStateObservation.h
	$(CC) $(CFLAGS) -c Dungeon.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Hunter.o: Hunter.cpp Hunter.h Denizen.h Arrow.h Cave.h Context.h \
 GameStateObservation.h
	$(CC) $(CFLAGS) -c Hunter.cpp

Pit.o: Pit.cpp Pit.h Denizen.h Context.h GameStateObservation.h
	$(CC) $(CFLAGS) -c Pit.cpp

TestCave.o: TestCave.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Bat.h Denizen.h Cave.h TestHelperDungeon.h \
 Dungeon.h Context.h RandomProvider.h TestHelperTestEnvironment.h \
 TestHelperGameStateMonitor.h GameStateObservation.h \
 TestHelperRandomProvider.h
	$(CC) $(CFLAGS) -c TestCave.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

UnitTestHuntTheWumpus.o: UnitTestHuntTheWumpus.cpp TestHarness.h Test.h \
 TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c UnitTestHuntTheWumpus.cpp

unittests.o: unittests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c unittests.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp

Wumpus.o: Wumpus.cpp Wumpus.h Denizen.h Cave.h Context.h Dungeon.h \
 RandomProvider.h GameStateObservation.h
	$(CC) $(CFLAGS) -c Wumpus.cpp


clean:
	$(RM) unittests *.o

