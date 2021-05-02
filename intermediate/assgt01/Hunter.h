#ifndef HUNTER_H
#define HUNTER_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Hunter : public Denizen 
{
public:
    Hunter(int instance);
    Hunter(const Hunter&) = default;
    ~Hunter() = default;
    Hunter& operator=(const Hunter &rhs) = default;

    void ObserveCaveEntrance();
    void ReportPresence();

};

} // namespace HuntTheWumpus

#endif