#include <algorithm>
#include "Cave.h"
#include "Denizen.h"

namespace HuntTheWumpus
{
    Cave::Cave(const int caveId/*, IDungeon& dungeon*/)
        : m_caveId(caveId),
        //m_dungeon(dungeon),
        m_connectedCaves(),
        m_denizens()
    {
    }

    void Cave::ConnectTo(int caveId, std::weak_ptr<Cave> cave) {
        m_connectedCaves[caveId] = cave;
    }

    std::vector<int> Cave::GetConnectedIds() const {
        std::vector<int> ids;
        for (std::unordered_map<int, std::weak_ptr<Cave> >::const_iterator pos = m_connectedCaves.begin(); 
             pos != m_connectedCaves.end(); 
             ++pos) {
            ids.push_back(pos->first);
        }
        
        return ids;
    }

    std::weak_ptr<Cave> Cave::GetConnectedCave(int caveId) const {
        // Gentleman rules, for now:
        std::weak_ptr<Cave> cave = m_connectedCaves.at(caveId);
        return cave;
    }

    bool Cave::HasDenizen(const DenizenIdentifier &identifier) const
    {
        const auto found = std::find_if(m_denizens.begin(), m_denizens.end(), [&](const std::shared_ptr<Denizen> &denizen)
        {
            return denizen->GetIdentifier().m_category == identifier.m_category;
        });

        return found != m_denizens.end();
    }

    /* 
    "Make" is confusing. There are is one wumpus, two bats, and a hunter with 
    arrows that move between caves.  It seems that there should be a Genesis 
    event where these are all created in a neutral space, and moved to caves.
    This should be loaded with std::move operations.  I think "Accept" is a 
    clearer verb.
    */
    void Cave::MakeDenizen(Category category) {
        // Not sure what to do here? 

        
    }
}
