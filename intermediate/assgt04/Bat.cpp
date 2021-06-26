#include "Bat.h"

#include "Cave.h"
#include "Context.h"
#include "Dungeon.h"
#include "RandomProvider.h"

namespace HuntTheWumpus
{
    Bat::Bat(const int batInstance, Context& providers)
        : Denizen(DenizenIdentifier{ Category::Bat, batInstance }, { false, false, false, false, false }, providers)
    {
    }

    bool Bat::ObserveCaveEntrance(const std::shared_ptr<Denizen>& trigger)
    {
        if (trigger->Properties().m_carryableByBats)
        {

            const auto cave = m_cave.lock();
            
            // Handle Req 13: Report the presence of a bat.
            m_providers.m_notification.Notify(HuntTheWumpus::UserNotification::Notification::BatTriggered);

            // Handle Req13:  Report the presence of a bat.
            m_providers.m_notification.Notify(HuntTheWumpus::UserNotification::Notification::BatTriggered);


            // Carry to another spot.
            const auto caveId = cave->GetCaveId();

            auto newCaveFound = false;
            auto newCaveId = 0;

            while (!newCaveFound)
            {
                newCaveId = m_providers.m_random.MakeRandomCave();
                newCaveFound = (newCaveId != caveId);
            }

            cave->GetDungeon().Move(trigger->GetIdentifier(), newCaveId);
            return true;
        }

        return false;
    }
}