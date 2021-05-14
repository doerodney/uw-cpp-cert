#pragma once

namespace HuntTheWumpus
{
    class IRandomProvider;

    struct Context
    {
        IRandomProvider &m_random;
    };
}
