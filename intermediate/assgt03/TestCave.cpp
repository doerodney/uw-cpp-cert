#include <memory>

#include "TestHarness.h"

#include "Bat.h"
#include "Cave.h"
#include "TestHelperDungeon.h"
#include "TestHelperTestEnvironment.h"


namespace TestHuntTheWumpus
{
    TEST(CaveSuite, Cave_HasDenizens)
    {
        // Create a test environment:
        TestEnvironment env;

        // Create a Bat to move in and out of the cave:
        int batInstance = 0;
        const auto bat = std::make_shared<HuntTheWumpus::Bat>(batInstance, env.m_context);
        const HuntTheWumpus::DenizenIdentifier batId { HuntTheWumpus::Category::Bat, batInstance};
        
        // Create a Cave:
        HuntTheWumpus::Cave cave(1, env.m_dungeon);

        // Verify that new cave has no denizens:
        CHECK_EQUAL(false, cave.HasDenizens());

        // Add a denizen to the cave:
        cave.AddDenizen(bat, true);

        // Verify that the cave now has a denizen:
        CHECK_EQUAL(true, cave.HasDenizens());

        // Remove the denizen:
        cave.RemoveDenizen(batId);

        // Verify that cave has no denizens:
        CHECK_EQUAL(false, cave.HasDenizens());
    }

    TEST(CaveSuite, CaveConstruction)
    {
        TestEnvironment env;

        const HuntTheWumpus::Cave cave(57, env.m_dungeon);

        CHECK_EQUAL(57, cave.GetCaveId());
        CHECK_EQUAL(&env.m_dungeon, &cave.GetDungeon());

        CHECK(cave.GetConnectedIds().empty());
    }

}

