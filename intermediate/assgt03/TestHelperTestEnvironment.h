#pragma once
#include "TestHelperGameStateMonitor.h"
#include "TestHelperRandomProvider.h"
#include "TestHelperDungeon.h"

#include "Context.h"

namespace TestHuntTheWumpus
{
    struct TestEnvironment
    {    
        TestEnvironment() = default;

        TestRandomProvider m_provider;
        TestGameStateMonitor m_gameStateMonitor;

        HuntTheWumpus::Context m_context {m_provider, m_gameStateMonitor};

        TestDungeon m_dungeon;
    };
}