#include <memory>

#include "TestHarness.h"

#include "Bat.h"
#include "Cave.h"
#include "TestHelperDungeon.h"
#include "TestHelperTestEnvironment.h"


namespace TestHuntTheWumpus
{
    // Create a test dungeon:
    TestDungeon dungeon;

    // Create a test environment:
    TestEnvironment env;

    // Create a Bat to move in and out of the cave:
    const HuntTheWumpus::Bat bat(0, env.m_context);

    // Create a Cave:
    HuntTheWumpus::Cave cave(1, dungeon);

    TEST(CaveSuite, Cave_HasDenizens)
    {
        CHECK_EQUAL(false, cave.HasDenizens());
    }

}

