#include "Hunter.h"

namespace HuntTheWumpus{

Hunter::Hunter(int instance)
: Denizen({Category::Hunter, instance}, {true, false, true, true, true}, -1){

}

void Hunter::ObserveCaveEntrance() {}

void Hunter::ReportPresence() {}


} //namespace HuntTheWumpus