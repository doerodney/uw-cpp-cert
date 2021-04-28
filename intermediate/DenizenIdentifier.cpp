#include "DenizenIdentifier.h"

using namespace HuntTheWumpus;

DenizenIdentifier::DenizenIdentifier(Category category, size_t serial) 
: m_category(category), m_serial(serial) 
{
}

std::strong_ordering DenizenIdentifier::operator<=>(const DenizenIdentifier &rhs) const {
    if (&rhs == this) {
        return std::strong_ordering::equal;
    } else if (m_category != rhs.m_category) {
        return m_category <=> rhs.m_category;
    } else {
        return m_serial <=> rhs.m_serial;
    }
}

bool DenizenIdentifier::operator==(const DenizenIdentifier &rhs) const {
    return ((m_category == rhs.m_category) && (m_serial == rhs.m_serial));
}
    