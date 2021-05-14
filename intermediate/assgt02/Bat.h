#ifndef BAT_H
#define BAT_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Bat : public Denizen 
{
public:
    Bat(int instance);
    Bat(const Bat&) = default;
    ~Bat() = default;
    Bat& operator=(const Bat &rhs) = default;

    void ObserveCaveEntrance() override;
    void ReportPresence() override;

};


} // namespace HuntTheWumpus

#endif