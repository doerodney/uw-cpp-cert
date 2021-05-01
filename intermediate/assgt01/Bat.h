#ifndef BAT_H
#define BAT_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Bat : public Denizen {
    Bat(int instance);
    Bat(const Bat&) = default;
    ~Bat() = default;
    Bat& operator=(const Bat &rhs) = default;

    int GetPriority();
    void ObserveCaveEntrance();
    void ReportPresence();

};


} // namespace HuntTheWumpus

#endif