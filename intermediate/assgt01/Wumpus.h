#ifndef WUMPUS_H
#define WUMPUS_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Wumpus : public Denizen {
    Wumpus(int instance);
    Wumpus(const Wumpus&) = default;
    ~Wumpus() = default;
    Wumpus& operator=(const Wumpus &rhs) = default;

    void ObserveCaveEntrance();
    void ReportPresence();

};

} // namespace HuntTheWumpus

#endif