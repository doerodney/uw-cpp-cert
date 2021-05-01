#ifndef INC_DENIZEN_PROPERTIES_H
#define INC_DENIZEN_PROPERTIES_H

namespace HuntTheWumpus {

struct DenizenProperties {
    DenizenProperties(bool carryable, bool fatalToWumpus, bool fatalToHunter, 
        bool isEdible, bool reportMovement);

    bool m_carryable;
    bool m_fatalToWumpus;
    bool m_fatalToHunter;
    bool m_isEdible;
    bool m_reportMovement;
};

}
#endif