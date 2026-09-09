#pragma once

#include "RE/G/GFxMovieDef.h"

// Public hook surface. Relocations, call-site validation and trampoline details
// live under source/hooks/ so normal users do not depend on implementation types.
namespace hooks
{
	bool Install();

	namespace compat
	{
		class MapMarkerFramework
		{
		public:
			static RE::GFxMovieDef* GetCompassMovieDef();
			static void Install(HMODULE a_moduleHandle);

			static inline const SKSE::PluginInfo* pluginInfo = nullptr;
			static inline RE::GFxMovieDef* compassMovieDef = nullptr;
		};
	}
}
