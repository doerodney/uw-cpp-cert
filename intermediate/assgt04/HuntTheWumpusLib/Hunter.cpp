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

        bool adjacentPit = false;
        bool adjacentBat = false;
        bool adjacentWumpus = false;

        //HuntTheWumpus::IDungeon& dungeon = cave->GetDungeon();
        const auto dungeon = cave->GetDungeon();
        std::vector<int> connectedIds = cave->GetConnectedIds();
        for (auto id : connectedIds) {
            const std::shared_ptr<Cave>& cave = dungeon.FindCave(id);
            const auto cave = dungeon.FindCave(id)
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