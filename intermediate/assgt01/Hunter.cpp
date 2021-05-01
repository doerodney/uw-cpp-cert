#include "Hunter.h"

namespace HuntTheWumpus{

Hunter::Hunter(int instance)
: Denizen({Category::Hunter, instance}, {false, false, true, false, false}, -1){

}

void Hunter::ObserveCaveEntrance() {}

void Hunter::ReportPresence() {}


} //namespace HuntTheWumpus