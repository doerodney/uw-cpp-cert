#ifndef WUMPUS_H
#define Wumpus_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Wumpus : public Denizen {
    Wumpus(int instance);
    Wumpus(const Wumpus&) = default;
    ~Wumpus() = default;
    Wumpus& operator=(const Wumpus &rhs) = default;

    int GetPriority();
    void ObserveCaveEntrance();
    void ReportPresence();

};


} // namespace HuntTheWumpus

#endif