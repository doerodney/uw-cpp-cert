#include "TestHarness.h"

#include "Wumpus.h"

namespace TestHuntTheWumpus
{
    TEST(WumpusSuite, Wumpus_HasProperAttributes)
    {
        const HuntTheWumpus::Wumpus wumpus(0);

        const auto &properties = wumpus.Properties();

        CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        const auto& id = wumpus.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Wumpus, id.m_category);
    }

	TEST(DenizenSuite, TestIdentifier_Comparison_ProperSorting)
    {
        const HuntTheWumpus::DenizenIdentifier thing1 { HuntTheWumpus::Category::Wumpus, 0 };  // Wumpus == 0 
        const HuntTheWumpus::DenizenIdentifier thing2 { HuntTheWumpus::Category::Arrow, 0 };   // Arrow == 4
        const HuntTheWumpus::DenizenIdentifier thing3 { HuntTheWumpus::Category::Arrow, 1 };

        CHECK( thing1 <=> thing2 == std::strong_ordering::less);
        CHECK( thing2 <=> thing1 == std::strong_ordering::greater);
        CHECK( thing2 <=> thing3 == std::strong_ordering::less);
        CHECK( thing3 <=> thing2 == std::strong_ordering::greater);
        CHECK( thing3 <=> thing3 == std::strong_ordering::equal);

        CHECK( thing3 == thing3 );
    }

    TEST(DenizenSuite, DenizenIdentifier_Hashing_UniqueHashes)
    {
        const HuntTheWumpus::DenizenIdentifier thing1 { HuntTheWumpus::Category::Arrow, 0 };
        const HuntTheWumpus::DenizenIdentifier thing2 { HuntTheWumpus::Category::Bat, 0 };
        const HuntTheWumpus::DenizenIdentifier thing3 { HuntTheWumpus::Category::Bat, 1 };
        const HuntTheWumpus::DenizenIdentifier thing4 { HuntTheWumpus::Category::Bat, 1 };

        const HuntTheWumpus::DenizenIdentifierHasher hasher;

        const auto hash1 = hasher(thing1);
        const auto hash2 = hasher(thing2);
        const auto hash3 = hasher(thing3);
        const auto hash4 = hasher(thing4);

        CHECK( hash1 != hash2 );
        CHECK( hash2 != hash3 );
        CHECK_EQUAL(hash3, hash4);
    }
}
