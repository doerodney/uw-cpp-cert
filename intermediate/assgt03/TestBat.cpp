#include "TestHarness.h"

#include "Bat.h"
#include "Cave.h"
#include "Hunter.h"
#include "Wumpus.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(BatSuite, HunterResponse) {
        // Create a test environment:
        TestEnvironment env;

        // Create a Bat for the cave:
        int batInstance = 1;
        const auto bat = std::make_shared<HuntTheWumpus::Bat>(batInstance, env.m_context);
        // const HuntTheWumpus::DenizenIdentifier batId { HuntTheWumpus::Category::Bat, batInstance};
        
        // Create a Hunter:
        const auto hunter = std::make_shared<HuntTheWumpus::Hunter>(env.m_context);

        // Create a Cave:
        auto cave = std::make_shared<HuntTheWumpus::Cave>(1, env.m_dungeon);

        // Add the bat to the cave:
        cave->AddDenizen(bat, true);
        bat->EnterCave(cave);
        
        // The hunter enters the cave:
        hunter->EnterCave(cave);

        auto moved = bat->ObserveCaveEntrance(hunter);

        CHECK_EQUAL(true, moved);
    }

    TEST(BatSuite, WumpusResponse) {
        // Create a test environment:
        TestEnvironment env;

        // Create a Bat for the cave:
        int batInstance = 1;
        const auto bat = std::make_shared<HuntTheWumpus::Bat>(batInstance, env.m_context);
        // const HuntTheWumpus::DenizenIdentifier batId { HuntTheWumpus::Category::Bat, batInstance};

        // Create a Wumpus:
        auto wumpus = std::make_shared<HuntTheWumpus::Wumpus>(1, env.m_context);

        // Create a Cave:
        auto cave = std::make_shared<HuntTheWumpus::Cave>(1, env.m_dungeon);

        // Add the bat to the cave:
        cave->AddDenizen(bat, true);
        bat->EnterCave(cave);

        // The wumpus enters the cave:
        wumpus->EnterCave(cave);

        auto moved = bat->ObserveCaveEntrance(wumpus);

        CHECK_EQUAL(false, moved);

    }

    TEST(BatSuite, Bat_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Bat bat(0, env.m_context);

        const auto &properties = bat.Properties();

        CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(!properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        CHECK_EQUAL(10, bat.GetPriority());

        const auto& id = bat.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Bat, id.m_category);
    }
}
