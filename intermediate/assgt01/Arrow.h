#ifndef ARROW_H
#define ARROW_H
#include "Denizen.h"

namespace HuntTheWumpus {

class Arrow : public Denizen 
{
public:
    Arrow(int instance);
    Arrow(const Arrow&) = default;
    ~Arrow() = default;
    Arrow& operator=(const Arrow &rhs) = default;

};

} // namespace HuntTheWumpus

#endif