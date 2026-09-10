#include "Config.h"
#include "ConfigValue.h"
#include <Windows.h>

namespace CNO::PalmTest
{
    namespace
    {
        constexpr auto kINI = "Data\\SKSE\\Plugins\\CNO_PalmTest.ini";
        float ReadFloat(const char* key, float fallback, float low, float high)
        {
            char buffer[64]{};
            GetPrivateProfileStringA("PalmTest", key, "", buffer, sizeof(buffer), kINI);
            return ParseConfigFloat(buffer, fallback, low, high);
        }
    }

    Config ReadConfig()
    {
        Config result;
        result.enabled = GetPrivateProfileIntA("PalmTest", "bEnabled", 0, kINI) != 0;
        result.width = ReadFloat("fWidth", 24.0F, 4.0F, 80.0F);
        result.offset = {ReadFloat("fOffsetX", 0.0F, -100.0F, 100.0F),
            ReadFloat("fOffsetY", -14.0F, -100.0F, 100.0F),
            ReadFloat("fOffsetZ", 0.0F, -100.0F, 100.0F)};
        return result;
    }
}
