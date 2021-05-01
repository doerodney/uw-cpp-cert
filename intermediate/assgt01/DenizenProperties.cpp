#include "DenizenProperties.h"

namespace HuntTheWumpus {

DenizenProperties::DenizenProperties(
    bool carryable, bool fatalToWumpus, bool fatalToHunter, 
    bool isEdible, bool reportMovement) :
    m_carryable(carryable), m_fatalToWumpus(fatalToWumpus),
    m_fatalToHunter(fatalToHunter), m_isEdible(isEdible),
    m_reportMovement(reportMovement) {

}


}  // namespace HuntTheWumpus