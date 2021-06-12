CC = g++
CFLAGS = -g -Wall -O3 -std=c++2a

default: unittests

unittests: Arrow.o Bat.o Cave.o Denizen.o Dungeon.o Failure.o Hunter.o HuntTheWumpus.o Pit.o TestArrow.o TestBat.o TestCave.o Test.o TestDungeon.o TestHelperTestEnvironment.o TestHunter.o TestPit.o TestRegistry.o TestResult.o TestThingInCave.o TestWumpus.o unittests.o UserNotification.o WFailure.o Wumpus.o 
	$(CC) $(CFLAGS) -o unittests Arrow.o Bat.o Cave.o Denizen.o Dungeon.o Failure.o Hunter.o HuntTheWumpus.o Pit.o TestArrow.o TestBat.o TestCave.o Test.o TestDungeon.o TestHelperTestEnvironment.o TestHunter.o TestPit.o TestRegistry.o TestResult.o TestThingInCave.o TestWumpus.o unittests.o UserNotification.o WFailure.o Wumpus.o 

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

HuntTheWumpus.o: HuntTheWumpus.cpp Context.h Dungeon.h Denizen.h Cave.h \
 RandomProvider.h GameStateObservation.h UserNotification.h
	$(CC) $(CFLAGS) -c HuntTheWumpus.cpp

Pit.o: Pit.cpp Pit.h Denizen.h Context.h GameStateObservation.h
	$(CC) $(CFLAGS) -c Pit.cpp

TestArrow.o: TestArrow.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Arrow.h Denizen.h TestHelperTestEnvironment.h \
 TestHelperGameState.h GameStateObservation.h TestHelperRandomProvider.h \
 RandomProvider.h TestHelperDungeon.h Dungeon.h Cave.h Context.h \
 UserNotification.h
	$(CC) $(CFLAGS) -c TestArrow.cpp

TestBat.o: TestBat.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Bat.h Denizen.h Cave.h Hunter.h Wumpus.h \
 TestHelperTestEnvironment.h TestHelperGameState.h GameStateObservation.h \
 TestHelperRandomProvider.h RandomProvider.h TestHelperDungeon.h \
 Dungeon.h Context.h UserNotification.h
	$(CC) $(CFLAGS) -c TestBat.cpp

TestCave.o: TestCave.cpp Cave.h Denizen.h Dungeon.h Context.h \
 RandomProvider.h TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h TestHelperTestEnvironment.h TestHelperGameState.h \
 GameStateObservation.h TestHelperRandomProvider.h TestHelperDungeon.h \
 UserNotification.h
	$(CC) $(CFLAGS) -c TestCave.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestDungeon.o: TestDungeon.cpp TestHarness.h Test.h TestResult.h \
 Failure.h WFailure.h TestRegistry.h Dungeon.h Denizen.h Cave.h Context.h \
 RandomProvider.h TestHelperTestEnvironment.h TestHelperGameState.h \
 GameStateObservation.h TestHelperRandomProvider.h TestHelperDungeon.h \
 UserNotification.h
	$(CC) $(CFLAGS) -c TestDungeon.cpp

TestHelperTestEnvironment.o: TestHelperTestEnvironment.cpp \
 TestHelperTestEnvironment.h TestHelperGameState.h GameStateObservation.h \
 TestHelperRandomProvider.h RandomProvider.h TestHelperDungeon.h \
 Dungeon.h Denizen.h Cave.h Context.h UserNotification.h
	$(CC) $(CFLAGS) -c TestHelperTestEnvironment.cpp

TestHunter.o: TestHunter.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Hunter.h Denizen.h Arrow.h Wumpus.h \
 TestHelperTestEnvironment.h TestHelperGameState.h GameStateObservation.h \
 TestHelperRandomProvider.h RandomProvider.h TestHelperDungeon.h \
 Dungeon.h Cave.h Context.h UserNotification.h
	$(CC) $(CFLAGS) -c TestHunter.cpp

TestPit.o: TestPit.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Pit.h Denizen.h Hunter.h \
 TestHelperTestEnvironment.h TestHelperGameState.h GameStateObservation.h \
 TestHelperRandomProvider.h RandomProvider.h TestHelperDungeon.h \
 Dungeon.h Cave.h Context.h UserNotification.h
	$(CC) $(CFLAGS) -c TestPit.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

TestThingInCave.o: TestThingInCave.cpp TestHarness.h Test.h TestResult.h \
 Failure.h WFailure.h TestRegistry.h TestHelperTestEnvironment.h \
 TestHelperGameState.h GameStateObservation.h TestHelperRandomProvider.h \
 RandomProvider.h TestHelperDungeon.h Dungeon.h Denizen.h Cave.h \
 Context.h UserNotification.h Bat.h Wumpus.h Pit.h Hunter.h Arrow.h
	$(CC) $(CFLAGS) -c TestThingInCave.cpp

TestWumpus.o: TestWumpus.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Wumpus.h Denizen.h Arrow.h Bat.h Cave.h \
 Hunter.h TestHelperTestEnvironment.h TestHelperGameState.h \
 GameStateObservation.h TestHelperRandomProvider.h RandomProvider.h \
 TestHelperDungeon.h Dungeon.h Context.h UserNotification.h
	$(CC) $(CFLAGS) -c TestWumpus.cpp

unittests.o: unittests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c unittests.cpp

UserNotification.o: UserNotification.cpp UserNotification.h
	$(CC) $(CFLAGS) -c UserNotification.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp

Wumpus.o: Wumpus.cpp Wumpus.h Denizen.h Cave.h Context.h Dungeon.h \
 RandomProvider.h GameStateObservation.h
	$(CC) $(CFLAGS) -c Wumpus.cpp


clean:
	$(RM) unittests *.o

