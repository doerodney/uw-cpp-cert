#include "TestHarness.h"

#include "Hunter.h"
#include "Arrow.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(HunterSuite, HunterMovement) {
        // Create a test environment:
        TestEnvironment env;

        // Create a left cave and a right cave;
        auto leftCaveInstance = 1;
        auto rightCaveInstance = 2;
       
        auto leftCave  = std::make_shared<HuntTheWumpus::Cave>(leftCaveInstance,  env.m_dungeon);
        auto rightCave = std::make_shared<HuntTheWumpus::Cave>(rightCaveInstance, env.m_dungeon);

        // Create a Hunter:
        auto hunterInstance = 1;
        const auto hunter = std::make_shared<HuntTheWumpus::Hunter>(env.m_context);
        const HuntTheWumpus::DenizenIdentifier hunterId{ HuntTheWumpus::Category::Hunter, hunterInstance };

        // Verify that the hunter is not in the left cave:
        auto hasDenizen = leftCave->HasDenizen(hunterId);
        CHECK_EQUAL(false, hasDenizen);

        // Add the hunter to the left cave:
        leftCave->AddDenizen(hunter, true);

        // Verify that the hunter is in the left cave:
        hasDenizen = leftCave->HasDenizen(hunterId);
        CHECK_EQUAL(true, hasDenizen);

        // Verify that the hunter is NOT in the right cave:
        hasDenizen = rightCave->HasDenizen(hunterId);
        CHECK_EQUAL(false, hasDenizen);

        // Remove the hunter from the left cave:
        leftCave->RemoveDenizen(hunterId);
        hasDenizen = leftCave->HasDenizen(hunterId);
        CHECK_EQUAL(false, hasDenizen);

        // Add the hunter to the right cave:
        rightCave->AddDenizen(hunter, true);

        // Verify that the hunter is in the right cave:
        hasDenizen = rightCave->HasDenizen(hunterId);
        CHECK_EQUAL(true, hasDenizen);
    }

    TEST(HunterSuite, Hunter_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Hunter hunter(env.m_context);

        const auto &properties = hunter.Properties();

        CHECK(properties.m_carryableByBats);
        CHECK(properties.m_isEdible);
        CHECK(properties.m_reportMovement);
        CHECK(!properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        CHECK_EQUAL(1, hunter.GetPriority());

        const auto& id = hunter.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Hunter, id.m_category);
    }
}
