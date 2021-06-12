#pragma once

#include "GameStateObservation.h"
#include "RandomProvider.h"
#include "UserNotification.h"

namespace HuntTheWumpus
{
    // class UserNotification;
    // class IRandomProvider;
    // class IGameStateChange;

    struct Context
    {
        UserNotification &m_notification;
        IRandomProvider &m_random;
        IGameStateChange &m_change;
    };
}