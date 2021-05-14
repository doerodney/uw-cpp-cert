#include "Hunter.h"

namespace HuntTheWumpus{

Hunter::Hunter(int instance)
: Denizen({Category::Hunter, instance}, {true, false, false, true, true}, -1){

}

void Hunter::ObserveCaveEntrance() {}

void Hunter::ReportPresence() {}


} //namespace HuntTheWumpus