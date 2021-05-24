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
    const auto b = std::make_shared<HuntTheWumpus::Bat>(0, env.m_context);

    // Create a Cave:
    HuntTheWumpus::Cave cave(1, dungeon);

    TEST(CaveSuite, Cave_HasDenizens)
    {
        // Verify that new cave has no denizens:
        CHECK_EQUAL(false, cave.HasDenizens());

        // Add a denizen to the cave:
        cave.AddDenizen(b, true);

        // Verify that the cave now has a denizen:
        CHECK_EQUAL(true, cave.HasDenizens());

    }

}

