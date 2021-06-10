#include "UserNotification.h"

#include <stdexcept>

namespace HuntTheWumpus
{
    void UserNotification::AddCallback(const Notification category, std::function<void()>&& callback)
    {
        // Store callback functions in map by category:
        m_notifications[category] = callback;
    }


    void UserNotification::Notify(Notification category) const 
    {
        // Extract callback function from map and invoke:
        auto func = m_notifications.at(category);
        func();
    }
}
