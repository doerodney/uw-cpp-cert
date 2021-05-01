#include "DenizenIdentifier.h"

using namespace HuntTheWumpus;

DenizenIdentifier::DenizenIdentifier(Category category, int instance) 
: m_category(category), m_instance(instance) {
}

std::strong_ordering DenizenIdentifier::operator<=>(const DenizenIdentifier &rhs) const {
    if (&rhs == this) {
        return std::strong_ordering::equal;
    } else if (m_category != rhs.m_category) {
        return m_category <=> rhs.m_category;
    } else {
        return m_instance <=> rhs.m_instance;
    }
}

bool DenizenIdentifier::operator==(const DenizenIdentifier &rhs) const {
    return ((m_category == rhs.m_category) && (m_instance == rhs.m_instance));
}
    