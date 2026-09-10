#pragma once
#include <cstdint>

namespace CNO::PalmTest
{
    // Experimental, opt-in; does not touch the Compass SWF or Palm's node transform.
    void OnMessage(std::uint32_t a_type);
}
