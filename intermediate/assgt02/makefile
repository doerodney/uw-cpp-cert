CC = g++
CFLAGS = -g -Wall -O3 -std=c++2a

default: unittests

unittests: Arrow.o Bat.o Cave.o Denizen.o DenizenIdentifier.o DenizenProperties.o Dungeon.o Failure.o Hunter.o Main.o Pit.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o Wumpus.o 
	$(CC) $(CFLAGS) -o unittests Arrow.o Bat.o Cave.o Denizen.o DenizenIdentifier.o DenizenProperties.o Dungeon.o Failure.o Hunter.o Main.o Pit.o Test.o TestRegistry.o TestResult.o unittests.o WFailure.o Wumpus.o 

Arrow.o: Arrow.cpp Arrow.h Denizen.h DenizenIdentifier.h \
 DenizenProperties.h
	$(CC) $(CFLAGS) -c Arrow.cpp

Bat.o: Bat.cpp Bat.h Denizen.h DenizenIdentifier.h DenizenProperties.h
	$(CC) $(CFLAGS) -c Bat.cpp

Cave.o: Cave.cpp Cave.h Denizen.h DenizenIdentifier.h DenizenProperties.h
	$(CC) $(CFLAGS) -c Cave.cpp

Denizen.o: Denizen.cpp Denizen.h DenizenIdentifier.h DenizenProperties.h
	$(CC) $(CFLAGS) -c Denizen.cpp

DenizenIdentifier.o: DenizenIdentifier.cpp DenizenIdentifier.h
	$(CC) $(CFLAGS) -c DenizenIdentifier.cpp

DenizenProperties.o: DenizenProperties.cpp DenizenProperties.h
	$(CC) $(CFLAGS) -c DenizenProperties.cpp

Dungeon.o: Dungeon.cpp Dungeon.h Cave.h Denizen.h DenizenIdentifier.h \
 DenizenProperties.h Context.h Bat.h Wumpus.h Hunter.h Pit.h \
 RandomProvider.h
	$(CC) $(CFLAGS) -c Dungeon.cpp

Failure.o: Failure.cpp Failure.h
	$(CC) $(CFLAGS) -c Failure.cpp

Hunter.o: Hunter.cpp Hunter.h Denizen.h DenizenIdentifier.h \
 DenizenProperties.h
	$(CC) $(CFLAGS) -c Hunter.cpp

Main.o: Main.cpp TestHarness.h Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c Main.cpp

Pit.o: Pit.cpp Pit.h Denizen.h DenizenIdentifier.h DenizenProperties.h
	$(CC) $(CFLAGS) -c Pit.cpp

Test.o: Test.cpp Test.h TestResult.h Failure.h WFailure.h TestRegistry.h
	$(CC) $(CFLAGS) -c Test.cpp

TestRegistry.o: TestRegistry.cpp Test.h TestResult.h Failure.h WFailure.h \
 TestRegistry.h
	$(CC) $(CFLAGS) -c TestRegistry.cpp

TestResult.o: TestResult.cpp TestResult.h Failure.h WFailure.h
	$(CC) $(CFLAGS) -c TestResult.cpp

unittests.o: unittests.cpp TestHarness.h Test.h TestResult.h Failure.h \
 WFailure.h TestRegistry.h Arrow.h Denizen.h DenizenIdentifier.h \
 DenizenProperties.h Bat.h Hunter.h Pit.h Wumpus.h
	$(CC) $(CFLAGS) -c unittests.cpp

WFailure.o: WFailure.cpp WFailure.h
	$(CC) $(CFLAGS) -c WFailure.cpp

Wumpus.o: Wumpus.cpp Wumpus.h Denizen.h DenizenIdentifier.h \
 DenizenProperties.h
	$(CC) $(CFLAGS) -c Wumpus.cpp


clean:
	$(RM) unittests *.o

