#ifndef PIT_H
#define PIT_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Pit : public Denizen {
    Pit(int instance);
    Pit(const Pit&) = default;
    ~Pit() = default;
    Pit& operator=(const Pit &rhs) = default;

    int GetPriority();
    void ObserveCaveEntrance();
    void ReportPresence();

};


} // namespace HuntTheWumpus

#endif