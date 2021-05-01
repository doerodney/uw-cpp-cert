#ifndef DENIZEN_IDENTIFIER_H
#define DENIZEN_IDENTIFIER_H
#include <compare>
#include <functional>
#include <sstream>
#include <string>

namespace HuntTheWumpus {

enum class Category
{
    Wumpus,
    Pit,
    Bat,
    Hunter,
    Arrow
};

std::ostream& operator<<(std::ostream& out, const Category& value);

class DenizenIdentifier 
{
public:
    DenizenIdentifier(Category category, int instance);
    DenizenIdentifier(const DenizenIdentifier&) = default;
    
    std::strong_ordering operator<=>(const DenizenIdentifier &rhs) const;
    bool operator==(const DenizenIdentifier &rhs) const;

private:
        Category m_category;
        int m_instance;

    friend struct DenizenIdentifierHasher;
};


struct DenizenIdentifierHasher {
    // Implements a hash from the simple combination of strings:
    // "category|instance".  (I do this in SQL all the time.)
    // This is simple but maybe not performant.  (No perf reqs, yet.)
    std::size_t operator()(const DenizenIdentifier& id) const noexcept {
        std::stringstream ss;
        ss << id.m_category << "|" << id.m_instance;
        std::hash<std::string> str_hasher;
        size_t h = str_hasher(ss.str());
        return h;
    }
};

}  // namespace HuntTheWumpus

#endif