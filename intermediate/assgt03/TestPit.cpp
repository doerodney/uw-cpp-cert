#include "TestHarness.h"

#include "Pit.h"
#include "Hunter.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(PitSuite, HunterResponse) {
        // Create a test environment:
        TestEnvironment env;

        // Create a Cave:
        auto cave = std::make_shared<HuntTheWumpus::Cave>(1, env.m_dungeon);

        // Create a Pit for the cave:
        const auto pit = std::make_shared<HuntTheWumpus::Pit>(1, env.m_context);

        // Add the pit to the cave:
        cave->AddDenizen(pit, true);
        pit->EnterCave(cave);  // Really?

        // Create a Hunter:
        const auto hunter = std::make_shared<HuntTheWumpus::Hunter>(env.m_context);

        // The hunter enters the cave:
        hunter->EnterCave(cave);

        // Determine if the pit "eats" the hunter
        auto eaten = pit->ObserveCaveEntrance(hunter);

        CHECK_EQUAL(true, eaten);
    }
    
    TEST(PitSuite, Pit_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Pit pit(0, env.m_context);

        const auto &properties = pit.Properties();

        CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        CHECK_EQUAL(5, pit.GetPriority());

        const auto& id = pit.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Pit, id.m_category);
    }
}
