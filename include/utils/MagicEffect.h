#pragma once

#include "RE/E/Effect.h"
#include "RE/E/EffectSetting.h"

namespace utils
{
	// 等价于 RE::Effect::GetArea()，内联实现以避免依赖静态库是否导出该函数。
	inline std::uint32_t GetMagicEffectArea(const RE::Effect* a_effect)
	{
		if (!a_effect || !a_effect->baseEffect)
		{
			return 0;
		}

		if (a_effect->baseEffect->data.flags.any(RE::EffectSetting::EffectSettingData::Flag::kNoArea))
		{
			return 0;
		}

		return a_effect->effectItem.area;
	}
}
