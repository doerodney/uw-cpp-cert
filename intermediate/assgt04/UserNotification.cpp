#include "UserNotification.h"
#include <algorithm>  // find
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
#ifdef UNITTEST_BUILD
        // Log the notification:
        m_notificationLog.push_back(category);
#endif
        // Extract callback from map and invoke:
        auto func = m_notifications.at(category);
        func();
    }

    void UserNotification::ClearNotificationLog() {
        m_notificationLog.clear();
    }        
    
    bool UserNotification::HasLoggedNotification(Notification category) const {        
        auto it = find(m_notificationLog.begin(), m_notificationLog.end(), category);
        return (it != m_notificationLog.end());
    }
}
