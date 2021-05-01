#pragma once
#include <compare>
#include <functional>
#include <sstream>
#include <string>

#include "Denizen.h"

//using namespace std;
namespace HuntTheWumpus {

class DenizenIdentifier {
    DenizenIdentifier(Category category, int instance);
    
    std::strong_ordering operator<=>(const DenizenIdentifier &rhs) const;
    bool operator==(const DenizenIdentifier &rhs) const;

    private:
        Category m_category;
        int m_instance;

    friend struct DenizenIdentifierHasher;
};


struct DenizenIdentifierHasher {
    std::size_t operator()(const DenizenIdentifier& id) const noexcept {
        std::stringstream ss;
        ss << id.m_category << "|" << id.m_instance;
        std::hash<std::string> str_hash;
        size_t h = str_hash(ss.str());
        return h;
    }
};

}