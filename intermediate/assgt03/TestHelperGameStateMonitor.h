#ifndef TEST_GAME_STATE_MONITOR_H
#define TEST_GAME_STATE_MONITOR_H

#include "GameStateObservation.h"

namespace TestHuntTheWumpus
{
    class TestGameStateMonitor : public HuntTheWumpus::IGameStateChange {
    public:
        virtual void GameOver(bool won) override {m_isPlaying = !won;}
        virtual bool IsPlaying() const override {return m_isPlaying;}

        TestGameStateMonitor() = default;
        TestGameStateMonitor(TestGameStateMonitor &) = default;
        TestGameStateMonitor(TestGameStateMonitor &&) = default;
        TestGameStateMonitor &operator=(const TestGameStateMonitor &) = default;
        TestGameStateMonitor &operator=(TestGameStateMonitor &&) = default;
        
    private:
        bool m_isPlaying = true;

    };

}

#endif