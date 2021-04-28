#pragma once
#include <compare>
#include <functional>
#include <sstream>
#include <string>

#include "Denizen.h"

using namespace std;
using namespace HuntTheWumpus;

class DenizenIdentifier {
    DenizenIdentifier(Category category, size_t serial);
    
    strong_ordering operator<=>(const DenizenIdentifier &rhs) const;
    bool operator==(const DenizenIdentifier &rhs) const;

    private:
        Category m_category;
        size_t m_serial;

    friend struct DenizenIdentifierHasher;
};


struct DenizenIdentifierHasher {
    std::size_t operator()(const DenizenIdentifier& id) const noexcept {
        std::stringstream ss;
        ss << id.m_category << "|" << id.m_serial;

        size_t h = std::hash<std::string>{}(ss.str());
        return h;
    }
};