#ifndef CAVE_H
#define CAVE_H

#include "Denizen.h"

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

namespace HuntTheWumpus
{
    class IDungeon;

    class Cave
    {
    public:
        explicit Cave(int caveId /*, IDungeon &dungeon*/);
        ~Cave() = default;

        bool HasDenizens() const { return !m_denizens.empty(); }
        bool HasDenizen(const DenizenIdentifier &identifier) const;

        // IDungeon &GetDungeon() const { return m_dungeon; }

        Cave() = delete;
        Cave(const Cave&) = delete;
        Cave(Cave&&) = delete;
        Cave& operator=(const Cave&) = delete;
        Cave& operator=(Cave&&) = delete;

        void ConnectTo(int caveId, std::weak_ptr<Cave> cave);
        std::vector<int> GetConnectedIds() const;
        std::weak_ptr<Cave> GetConnectedCave(int caveId) const;
        void MakeDenizen(Category category);
        
    private:
        int m_caveId;
        // IDungeon &m_dungeon;
        std::unordered_map<int, std::weak_ptr<Cave> > m_connectedCaves;
        std::vector<std::shared_ptr<Denizen> > m_denizens;
        
    };
}

#endif
