#include "../../source/palmtest/ConfigValue.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
int main()
{
    struct Case { const char* input; float expected; };
    // Preserve the old parser: whitespace-only input advances end after strtof, then clamps 0.
    const Case cases[] = {
        {"",24}, {" ",4}, {"oops",24}, {"nan",24}, {"inf",24}, {"-inf",24},
        {"1e99",24}, {"24px",24}, {"48",48}, {" 48 \t",48}, {"4",4}, {"80",80},
        {"-20",4}, {"300",80}, {"0",4}, {"2.4e1",24}, {"+32.5",32.5f}, {"-0",4}
    };
    for (const auto& c : cases) {
        const auto value = CNO::PalmTest::ParseConfigFloat(c.input,24,4,80);
        if (std::abs(value-c.expected)>0.0001f) throw std::runtime_error(c.input);
    }
    const Case offsets[] = {{"-101",-100},{"101",100},{"-14",-14},{"0",0},{"bad",-14}};
    for (const auto& c : offsets) {
        const auto value = CNO::PalmTest::ParseConfigFloat(c.input,-14,-100,100);
        if (std::abs(value-c.expected)>0.0001f) throw std::runtime_error(c.input);
    }
    std::cout << "23 production config-parser cases passed\n";
}
