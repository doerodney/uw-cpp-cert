#include "Pit.h"

namespace HuntTheWumpus {

Pit::Pit(int instance)
: Denizen({Category::Pit, instance}, {false, false, true, false, false}, 1){

}

void Pit::ObserveCaveEntrance() {}

void Pit::ReportPresence() {}


} //namespace HuntTheWumpus