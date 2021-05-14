#include "Arrow.h"

namespace HuntTheWumpus{

Arrow::Arrow(int instance)
: Denizen({Category::Arrow, instance}, {false, true, true, false, false}, -1){

}

} //namespace HuntTheWumpus