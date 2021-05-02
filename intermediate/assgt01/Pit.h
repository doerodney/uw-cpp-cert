#ifndef PIT_H
#define PIT_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Pit : public Denizen 
{
public:
    Pit(int instance);
    Pit(const Pit&) = default;
    ~Pit() = default;
    Pit& operator=(const Pit &rhs) = default;
    
    void ObserveCaveEntrance();
    void ReportPresence();

};


} // namespace HuntTheWumpus

#endif