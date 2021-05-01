#include "Bat.h"

namespace HuntTheWumpus {

Bat::Bat(int instance)
: Denizen({Category::Bat, instance}, {false, false, false, false, false}, 0){

}

void Bat::ObserveCaveEntrance() {}

void Bat::ReportPresence() {}


} //namespace HuntTheWumpus