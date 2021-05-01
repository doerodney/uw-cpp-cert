#ifndef HUNTER_H
#define PIT_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Hunter : public Denizen {
    Hunter(int instance);
    Hunter(const Hunter&) = default;
    ~Hunter() = default;
    Hunter& operator=(const Hunter &rhs) = default;

    int GetPriority();
    void ObserveCaveEntrance();
    void ReportPresence();

};


} // namespace HuntTheWumpus

#endif