#pragma once

#include "Hooks.h"

#include "utils/MagicEffect.h"
#include "utils/Trampoline.h"

#include "RE/A/ActiveEffect.h"
#include "RE/B/BSCoreTypes.h"
#include "RE/C/Compass.h"
#include "RE/D/DetectLifeEffect.h"
#include "RE/H/HUDMarkerManager.h"
#include "RE/N/NiPoint3.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/S/ScriptEffect.h"
#include "RE/S/ShaderReferenceEffect.h"

namespace hooks
{
	bool UpdateQuests(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
					  RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
					  std::uint32_t* a_markerSources, std::uint32_t a_markerSource,
					  const void* a_runtimeQuestTarget);

	RE::TESWorldSpace* AllowedToShowMapMarker(const RE::TESObjectREFR* a_marker);

	bool UpdateLocations(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
						 RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
						 std::uint32_t* a_markerSources, std::uint32_t a_markerSource);

	bool UpdateEnemies(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
					   RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
					   std::uint32_t* a_markerSources, std::uint32_t a_markerSource);

	bool UpdatePlayerSetMarker(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
							   RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
							   std::uint32_t* a_markerSources, std::uint32_t a_markerSource);

	void UpdateCompass(RE::Compass* a_compass);

	// 三个上游虚表 Hook 共用一个无写入点的开关，默认只转发；仍安装以保持调用链兼容。

	// DAT_1801d9538：恒为 false 的开关，全 DLL 无写入点。
	inline bool magicEffectAreaProbeEnabled = false;

	void DetectLifeEffectUpdate(RE::ActiveEffect* a_activeEffect, float a_delta);

	void ScriptEffectUpdate(RE::ActiveEffect* a_activeEffect, float a_delta);

	void ShaderReferenceEffectDetach(RE::ReferenceEffect* a_referenceEffect);

	class HUDMarkerManager
	{
		static constexpr REL::RelocationID UpdateQuestsId{ 50826, 51691 };
		static constexpr REL::RelocationID UpdateLocationsId{ 50870, 51744 };
		static constexpr REL::RelocationID AddMarkerId{ 50851, 51728 };

	public:

		static inline REL::Relocation<bool(*)(const RE::HUDMarkerManager*, RE::TESQuest**,
											  RE::BSTArray<RE::TESQuestTarget>*)> UpdateQuests{ UpdateQuestsId };

		static inline REL::Relocation<bool(*)(const RE::HUDMarkerManager*)> UpdateLocations{ UpdateLocationsId };

		static inline REL::Relocation<bool(*)(const RE::HUDMarkerManager*, RE::HUDMarker::ScaleformData*,
											  RE::NiPoint3*, const RE::RefHandle&, std::int32_t,
											  std::uint32_t*, std::uint32_t)> AddMarker{ AddMarkerId };
	};

	class HUDMenu
	{
		static constexpr REL::RelocationID ProcessMessageId{ 50718, 51612 };

	public:

		static inline REL::Relocation<RE::UI_MESSAGE_RESULTS(*)(const RE::HUDMenu*, RE::UIMessage&)> ProcessMessage{ ProcessMessageId };
	};

	class Compass
	{
		static constexpr REL::RelocationID SetMarkersId{ 50775, 51670 };
		static constexpr REL::RelocationID UpdateId{ 50773, 51668 };

	public:
		static inline REL::Relocation<std::uintptr_t> vTable{ RE::VTABLE_Compass[0] };

		static inline REL::Relocation<bool (*)(RE::Compass*)> SetMarkers{ SetMarkersId };
		static inline REL::Relocation<void (*)(RE::Compass*)> Update{ UpdateId };
	};

	// write_vfunc 返回的旧地址用于调用原函数。
	class DetectLifeEffect
	{
	public:
		static inline REL::Relocation<std::uintptr_t> vTable{ RE::VTABLE_DetectLifeEffect[0] };

		// vfunc 04 = RE::ActiveEffect::Update(float)，写入偏移 vtable + 0x20。
		static constexpr std::size_t UpdateIndex = 4;

		static inline REL::Relocation<void (*)(RE::ActiveEffect*, float)> Update;
	};

	class ScriptEffect
	{
	public:
		static inline REL::Relocation<std::uintptr_t> vTable{ RE::VTABLE_ScriptEffect[0] };

		// 同为 vfunc 04（vtable + 0x20）。
		static constexpr std::size_t UpdateIndex = 4;

		static inline REL::Relocation<void (*)(RE::ActiveEffect*, float)> Update;
	};

	class ShaderReferenceEffect
	{
	public:
		static inline REL::Relocation<std::uintptr_t> vTable{ RE::VTABLE_ShaderReferenceEffect[0] };

		// vfunc 0x3E = RE::ReferenceEffect::DetachImpl()，写入偏移 vtable + 0x1F0（0x1F0 / 8 = 62）。
		static constexpr std::size_t DetachImplIndex = 0x3E;

		static inline REL::Relocation<void (*)(RE::ReferenceEffect*)> DetachImpl;
	};

}
