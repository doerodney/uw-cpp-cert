#include <iostream>
#include "Hunter.h"

#include "Arrow.h"

#include "Cave.h"
#include "Context.h"
#include "GameStateObservation.h"

namespace HuntTheWumpus
{
    Hunter::Hunter(Context& providers)
        : Denizen({ Category::Hunter, 0 }, { true, false, false, true, true }, providers)
    {
        for (auto arrowIdx = 0; arrowIdx < 5; ++arrowIdx)
        {
            m_arrows.emplace_back(std::make_shared<Arrow>(arrowIdx, providers));
        }
    }

    void Hunter::EnterCave(const std::shared_ptr<Cave>& cave)
    {
        Denizen::EnterCave(cave);

        // Report current and adjacent caves:
        const std::vector<int> ids = cave->GetConnectedIds();
        std::cout << "Welcome to cave " << cave->GetCaveId() << " ." << std::endl;
        std::cout << "Adjacent caves are:";
        for (auto id : ids) {
            std::cout << id << std::endl; 
        }
    
        // Test adjacent caves for nasty occupants:
        const std::vector<int> serials = {0, 1};
        bool adjBat = false;
        bool adjPit = false;
        bool adjWumpus = false;

        for (auto id : ids) {
            const auto adjCave = cave->GetConnectedCave(id).lock();
            
            // Test for bats:
            for (auto serial: serials) {
                if (adjCave->HasDenizen({HuntTheWumpus::Category::Bat, serial})) {
                    adjBat = true;
                }
            }

            // Test for pits:
            for (auto serial: serials) {
                if (adjCave->HasDenizen({HuntTheWumpus::Category::Pit, serial})) {
                    adjPit = true;
                }
            }

            // Test for wumpus:
            if (adjCave->HasDenizen({HuntTheWumpus::Category::Wumpus, 0})) {
                adjWumpus = true;
            }            
        }

        if (adjBat) {
            m_providers.m_notification.Notify(HuntTheWumpus::UserNotification::Notification::ObserveBat);
        }

        if (adjPit) {
            m_providers.m_notification.Notify(HuntTheWumpus::UserNotification::Notification::ObservePit);
        }

        if (adjWumpus) {
            m_providers.m_notification.Notify(HuntTheWumpus::UserNotification::Notification::ObserveWumpus);
        }
        
    }

    std::shared_ptr<Arrow> Hunter::GetArrow()
    {
        auto result = m_arrows.back();
        m_arrows.pop_back();

        return result;
    }

    bool Hunter::ObserveCaveEntrance(const std::shared_ptr<Denizen>& trigger)
    {
        if (trigger->Properties().m_fatalToHunter)
        {
            m_providers.m_change.GameOver(false);

            return true;
        }

        return false;
    }
}