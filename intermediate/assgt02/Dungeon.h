#ifndef DUNGEON_H
#define DUNGEON_H

#include "Cave.h"
#include "Context.h"
#include "Denizen.h"

namespace HuntTheWumpus
{
    class IDungeon
    {
    public:
        
        IDungeon() = default;
        virtual ~IDungeon() = default;

        virtual const std::shared_ptr<Cave> &FindCave(int caveId) = 0;

        IDungeon(const IDungeon &) = default;
        IDungeon(IDungeon &&) = default;
        IDungeon &operator=(const IDungeon &) = default;
        IDungeon &operator=(IDungeon &&) = default;
    };

    class Dungeon final : public IDungeon
    {
    public:
        explicit Dungeon(Context &providers);
        ~Dungeon() override = default;

        Dungeon(const Dungeon &) = delete;
        Dungeon(Dungeon &&) = delete;
        Dungeon &operator=(const Dungeon &) = delete;
        Dungeon &operator=(Dungeon &&) = delete;

    private:
        void Initialize(Context &providers);
        void MakeTunnels();
        void AddToCave(const std::shared_ptr<Denizen> &denizen, int caveId);

        Context &m_providers;
        std::unordered_map<int, std::shared_ptr<Cave> > m_caves;

        const std::vector<std::pair<int, std::vector<int> > > getTunnelPairs() const;
    };
}

#endif
