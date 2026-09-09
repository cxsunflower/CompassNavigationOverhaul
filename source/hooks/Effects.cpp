#include "Internal.h"

#include "Settings.h"

#include "HUDMarkerManager.h"

namespace hooks
{
	// 开关启用时读取效果范围，随后始终转发原函数。
	void DetectLifeEffectUpdate(RE::ActiveEffect* a_activeEffect, float a_delta)
	{
		if (magicEffectAreaProbeEnabled)
		{
			[[maybe_unused]] std::uint32_t area = utils::GetMagicEffectArea(a_activeEffect->effect);
		}

		DetectLifeEffect::Update(a_activeEffect, a_delta);
	}

	// 仅对 FormID 0x8AFCC–0x8AFCE 读取效果范围，随后转发原函数。
	void ScriptEffectUpdate(RE::ActiveEffect* a_activeEffect, float a_delta)
	{
		if (magicEffectAreaProbeEnabled && a_activeEffect->spell)
		{
			const RE::FormID spellFormID = a_activeEffect->spell->GetFormID();

			if (spellFormID >= 0x8AFCC && spellFormID <= 0x8AFCE)
			{
				[[maybe_unused]] std::uint32_t area = utils::GetMagicEffectArea(a_activeEffect->effect);
			}
		}

		ScriptEffect::Update(a_activeEffect, a_delta);
	}

	// 上游实现为纯转发。
	void ShaderReferenceEffectDetach(RE::ReferenceEffect* a_referenceEffect)
	{
		ShaderReferenceEffect::DetachImpl(a_referenceEffect);
	}

}
