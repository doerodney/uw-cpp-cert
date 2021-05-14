#ifndef DENIZEN_PROPERTIES_H
#define DENIZEN_PROPERTIES_H

namespace HuntTheWumpus {

class DenizenProperties 
{
public:
    DenizenProperties(bool carryable, bool fatalToWumpus, bool fatalToHunter, 
        bool isEdible, bool reportMovement);

    //DenizenProperties(const DenizenProperties&) = default;

public:
    bool m_carryableByBats;
    bool m_fatalToWumpus;
    bool m_fatalToHunter;
    bool m_isEdible;
    bool m_reportMovement;
};

}  // namespace HuntTheWumpus
#endif