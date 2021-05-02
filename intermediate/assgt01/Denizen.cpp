#include "Denizen.h"

#include <bit>
#include <functional>
#include <iostream>
#include <limits>
#include <unordered_map>

// using namespace std;

namespace HuntTheWumpus
{
#ifdef NOT_USED
// See https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values/50978188
size_t xorshift(const size_t n, const int i)
{
    return n ^ (n >> i);
}

uint32_t distribute(const uint32_t n)
{
    constexpr uint32_t p = 0x55555555ul; // pattern of alternating 0 and 1
    constexpr uint32_t c = 3423571495ul; // random uneven integer constant; 
    return static_cast<uint32_t>(c * xorshift(p * xorshift(n, 16), 16));
}

size_t hash_combine(const std::size_t seed, const size_t v)
{
    return std::rotl(seed, std::numeric_limits<size_t>::digits / 3) ^ distribute(static_cast<uint32_t>(v));
}
#endif

std::ostream& operator<<(std::ostream& out, const Category& value)
{
    static std::unordered_map<Category, std::string> s_valueMap =
    {
        {Category::Arrow, "Arrow" },
        {Category::Bat, "Bat" },
        {Category::Hunter, "Hunter" },
        {Category::Pit, "Pit" },
        {Category::Wumpus, "Wumpus" }
    };

    out << s_valueMap[value];
    return out;
}


Denizen::Denizen(
    const DenizenIdentifier& id, const DenizenProperties& props, int priority
) : m_identifier(id), m_properties(props), m_priority(priority) {

}

const DenizenProperties& Denizen::Properties() const {
    return m_properties;
}

const DenizenIdentifier& Denizen::GetIdentifier() const {
    return m_identifier;
}

int Denizen::GetPriority() const {
    return m_priority;
}

}  // namespace HuntTheWumpus
