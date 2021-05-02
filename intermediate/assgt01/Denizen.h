#pragma once

#include <iosfwd>
#include "DenizenIdentifier.h"
#include "DenizenProperties.h"

namespace HuntTheWumpus
{

class Denizen {
public:
    Denizen(
        const DenizenIdentifier& id, const DenizenProperties& props,
        int priority);
    Denizen() = default;
    ~Denizen() = default;

    const DenizenProperties& Properties() const;
    const DenizenIdentifier& GetIdentifier() const;

    virtual void EnterCave() {};
    virtual int GetPriority() const;
    virtual void ObserveCaveEntrance() {};
    virtual void RemoveFromCave() {};
    virtual void ReportPresence() {};
  
  protected:
    DenizenIdentifier m_identifier;
    DenizenProperties m_properties;
    int m_priority;  // Req line 16

};

}  // namespace HuntTheWumpus
