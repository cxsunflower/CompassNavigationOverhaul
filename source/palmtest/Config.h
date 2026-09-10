#pragma once
#include <RE/Skyrim.h>

namespace CNO::PalmTest
{
    struct Config
    {
        bool enabled{false};
        float width{24.0F};
        RE::NiPoint3 offset{0.0F, -14.0F, 0.0F};
    };

    // Read-only, no INI writes. Runtime owns the polling cadence.
    Config ReadConfig();
}
