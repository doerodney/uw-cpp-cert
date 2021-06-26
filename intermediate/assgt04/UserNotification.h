#pragma once

#include <functional>
#include <map>  // notifications
#include <vector>  // notification log

namespace HuntTheWumpus
{
    // Inform the user about particular operations happening.
    class UserNotification final
    {
    public:

        enum class Notification
        {
            ObserveWumpus,
            ObservePit,
            ObserveBat,
            ObserveMiss,
            ObserveOutOfArrows,
            BatTriggered,
            PitTriggered,
            WumpusTriggered,
            WumpusAwoken,
            WumpusShot,
            HunterEaten,
            HunterShot,
            CaveEntered,
            ReportIllegalMove,
            ReportNeighboringCaves
        };

        UserNotification() = default;
        ~UserNotification() = default;

        void AddCallback(Notification category, std::function<void()>&& callback);

        void Notify(Notification category) const;
        void ClearNotificationLog();
        bool HasLoggedNotification(Notification category) const;

        UserNotification(const UserNotification&) = default;
        UserNotification(UserNotification&&) = default;
        UserNotification& operator=(const UserNotification&) = default;
        UserNotification& operator=(UserNotification&&) = default;

    private:

       std::map<Notification, std::function<void()> > m_notifications;
       std::vector<Notification> m_notificationLog;
    };
}