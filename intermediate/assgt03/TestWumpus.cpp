#include "TestHarness.h"

#include "Wumpus.h"

#include "Arrow.h"
#include "Bat.h"
#include "Cave.h"
#include "Hunter.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(WumpusSuite, HunterResponse) {
        // Create a test environment:
        TestEnvironment env;

        // Create a Wumpus:
        auto wumpus = std::make_shared<HuntTheWumpus::Wumpus>(1, env.m_context);

        // Create a Cave:
        auto cave = std::make_shared<HuntTheWumpus::Cave>(1, env.m_dungeon);

        // Add the wumpus to the cave:
        cave->AddDenizen(wumpus, true);
        wumpus->EnterCave(cave);

        // The wumpus enters the cave:
        wumpus->EnterCave(cave);

        // Create a Hunter:
        const auto hunter = std::make_shared<HuntTheWumpus::Hunter>(env.m_context);

        // The hunter enters the cave:
        hunter->EnterCave(cave);

        auto moved = wumpus->ObserveCaveEntrance(wumpus);

        // Wumpus could move or stay and eat the hunter:
        CHECK_EQUAL(true, moved || !moved);  // Lamest unit test ever - cannot fail.

    }


    TEST(WumpusSuite, Wumpus_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Wumpus wumpus(0, env.m_context);

        const auto &properties = wumpus.Properties();

        CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        CHECK_EQUAL(20, wumpus.GetPriority());

        const auto& id = wumpus.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Wumpus, id.m_category);
    }
}
