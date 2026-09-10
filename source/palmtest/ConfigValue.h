#pragma once
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>

namespace CNO::PalmTest
{
    // Engine-independent parsing; preserves the prototype's strtof/clamp semantics.
    inline float ParseConfigFloat(const char* buffer, float fallback, float low, float high)
    {
        char* end = nullptr;
        const float value = std::strtof(buffer, &end);
        while (end && *end && std::isspace(static_cast<unsigned char>(*end))) ++end;
        return end == buffer || !end || *end || !std::isfinite(value) ?
            fallback : std::clamp(value, low, high);
    }
}
