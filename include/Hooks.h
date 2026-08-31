#pragma once

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

	static inline bool Install()
	{
		// Hook UpdateQuests 对 AddMarker 的调用。
		struct UpdateQuestsHook : Hook<5>
		{
			static std::uintptr_t Address() { return HUDMarkerManager::UpdateQuests.address() + REL::VariantOffset{ 0x114, 0x180, 0x13A }.offset(); }

			struct HookCodeGenerator : Xbyak::CodeGenerator
			{
				HookCodeGenerator(std::uintptr_t a_hookedAddress)
				{
					Xbyak::Label hookLabel;
					Xbyak::Label retnLabel;

					// rbx 是目标指针槽位；直接把 [rbx] 中的运行时目标作为第八参数传递。
					mov(rax, ptr[rbx]);
					mov(ptr[rsp + 0x38], rax);
					call(ptr[rip + hookLabel]);

					jmp(ptr[rip + retnLabel]);

					L(hookLabel), dq(reinterpret_cast<std::uintptr_t>(&UpdateQuests));
					L(retnLabel), dq(a_hookedAddress + 5);

					ready();
				}
			};

			UpdateQuestsHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, HookCodeGenerator{ a_hookedAddress } }
			{}
		};

		// Hook UpdateLocations 对 TESObjectREFR::GetWorldspace 的调用。
		struct AllowedToShowMapMarkerHook : Hook<5>
		{
			static std::uintptr_t Address1() { return HUDMarkerManager::UpdateLocations.address() + REL::VariantOffset{ 0x139, 0x13C, 0x13D }.offset(); }
			static std::uintptr_t Address2() { return HUDMarkerManager::UpdateLocations.address() + REL::VariantOffset{ 0x21C, 0x24B, 0x230 }.offset(); }

			AllowedToShowMapMarkerHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&AllowedToShowMapMarker) }
			{}
		};

		// Hook UpdateLocations 添加地点标记的调用。
		struct UpdateLocationsHook : Hook<5>
		{
			static std::uintptr_t Address() { return HUDMarkerManager::UpdateLocations.address() + REL::VariantOffset{ 0x450, 0x473, 0x468 }.offset(); }

			UpdateLocationsHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&UpdateLocations) }
			{}
		};

		// Hook HUDMenu::ProcessMessage 添加敌人标记的调用。
		struct UpdateEnemiesHook : Hook<5>
		{
			// 1.6.640 与 1.6.1130 的偏移不同，需按版本细分。
			static std::uintptr_t Address()
			{
				// VR 把敌人标记更新拆成了紧邻 UpdateLocations 的独立函数；此处定位其 AddMarker 调用。
				if (REL::Module::IsVR())
				{
					return HUDMarkerManager::UpdateLocations.address() - 0x27;
				}

				REL::Version version = REL::Module::get().version();
				std::uintptr_t offsetAE = version < SKSE::RUNTIME_SSE_1_6_1130 ? 0x1695 : 0x1735;

				return HUDMenu::ProcessMessage.address() + REL::VariantOffset{ 0x15AB, offsetAE, 0x15AB }.offset();
			}

			UpdateEnemiesHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&UpdateEnemies) }
			{}
		};

		// Hook Compass::SetMarkers 添加玩家标记的调用。
		struct UpdatePlayerSetMarkerHook : Hook<5>
		{
			// AE 将 Compass::SetMarkers 内联进 Compass::Update。
			static std::uintptr_t Address()
			{
				if (REL::Module::IsVR())
				{
					return Compass::SetMarkers.address() + 0x9E;
				}

				return REL::Module::IsAE() ? Compass::Update.address() + 0xAE : Compass::SetMarkers.address() + 0x8D;
			}

			UpdatePlayerSetMarkerHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&UpdatePlayerSetMarker) }
			{}
		};

		// 在写入跳板前验证目标仍是近调用指令，避免地址库或 EXE 不匹配时破坏游戏代码。
		const std::array callSites{
			std::pair{ UpdateQuestsHook::Address(), "任务标记"sv },
			std::pair{ AllowedToShowMapMarkerHook::Address1(), "地点世界空间（第一处）"sv },
			std::pair{ AllowedToShowMapMarkerHook::Address2(), "地点世界空间（第二处）"sv },
			std::pair{ UpdateLocationsHook::Address(), "地点标记"sv },
			std::pair{ UpdateEnemiesHook::Address(), "敌人标记"sv },
			std::pair{ UpdatePlayerSetMarkerHook::Address(), "玩家标记"sv }
		};

		for (const auto& [address, name] : callSites)
		{
			if (*reinterpret_cast<const std::uint8_t*>(address) != 0xE8)
			{
				SKSE::log::critical("Hook 指令验证失败：{}，地址 0x{:X}", name, address);
				return false;
			}
		}

		UpdateQuestsHook updateQuestsHook{ UpdateQuestsHook::Address() };
		AllowedToShowMapMarkerHook allowedToShowMapMarkerHook[2]{ AllowedToShowMapMarkerHook::Address1(), AllowedToShowMapMarkerHook::Address2() };
		UpdateLocationsHook updateLocationsHook{ UpdateLocationsHook::Address() };
		UpdateEnemiesHook updateEnemiesHook{ UpdateEnemiesHook::Address() };
		UpdatePlayerSetMarkerHook updatePlayerSetMarkerHook{ UpdatePlayerSetMarkerHook::Address() };
		
		// AllowedToShowMapMarker 的多个 Hook 共用目标代码，只分配一次。
		static DefaultTrampoline defaultTrampoline{ updateQuestsHook.getSize() + allowedToShowMapMarkerHook->getSize() +
													updateLocationsHook.getSize() + updateEnemiesHook.getSize() +
													updatePlayerSetMarkerHook.getSize() };
		
		defaultTrampoline.write_branch(updateQuestsHook);
		defaultTrampoline.write_call(allowedToShowMapMarkerHook[0]);
		defaultTrampoline.write_call(allowedToShowMapMarkerHook[1]);
		defaultTrampoline.write_call(updateLocationsHook);
		defaultTrampoline.write_call(updateEnemiesHook);
		defaultTrampoline.write_call(updatePlayerSetMarkerHook);

		Compass::vTable.write_vfunc(1, UpdateCompass);

		// 安装三个兼容性虚表 Hook，并保存原函数。
		DetectLifeEffect::Update = DetectLifeEffect::vTable.write_vfunc(DetectLifeEffect::UpdateIndex, DetectLifeEffectUpdate);
		ScriptEffect::Update = ScriptEffect::vTable.write_vfunc(ScriptEffect::UpdateIndex, ScriptEffectUpdate);
		ShaderReferenceEffect::DetachImpl = ShaderReferenceEffect::vTable.write_vfunc(ShaderReferenceEffect::DetachImplIndex, ShaderReferenceEffectDetach);

		return true;
	}

	namespace compat
	{
		class MapMarkerFramework
		{
		public:

			static RE::GFxMovieDef* GetCompassMovieDef();

			static inline void Install(HMODULE a_moduleHandle)
			{
				// Hook ImportManager::SetupHUDMenu 对 a_movieView->GetMovieDef() 的调用。
				struct GetCompassMovieDefHook : Hook<6>
				{
					GetCompassMovieDefHook(std::uintptr_t a_hookedAddress) :
						Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&GetCompassMovieDef) }
					{}
				};

				std::uintptr_t getCompassMovieDefHookAddress = SigScanner::FindPattern
				<
					"4C 8B F1 "	// mov     r14, rcx
					"48 8B 02 "	// mov     rax, [rdx]
					"48 8B CA "	// mov     rcx, rdx <- We want this address (offset 6)
					"FF 50 08 "	// call    qword ptr [rax+8]
					"?? 8B ?? "	// mov     ??, rax
					"48 85 C0"	// test    rax, rax
				>(a_moduleHandle) + 6;

				GetCompassMovieDefHook getCompassMovieDefHook{ getCompassMovieDefHookAddress };

				static CustomTrampoline mapMarkerFrameworkTrampoline{ "MapMarkerFramework Trampoline", a_moduleHandle,
																	  getCompassMovieDefHook.getSize() };

				mapMarkerFrameworkTrampoline.write_call(getCompassMovieDefHook);
			}

			static inline const SKSE::PluginInfo* pluginInfo = nullptr;
			static inline RE::GFxMovieDef* compassMovieDef = nullptr;
		};
	}
}
