#include "Wumpus.h"

namespace HuntTheWumpus {

Wumpus::Wumpus(int instance)
: Denizen({Category::Wumpus, instance}, {false, false, true, false, false}, 2){

}

void Wumpus::ObserveCaveEntrance() {}

void Wumpus::ReportPresence() {}


} //namespace HuntTheWumpus