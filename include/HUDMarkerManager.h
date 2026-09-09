#pragma once

#include "RE/H/HUDMarkerManager.h"

#include "RE/B/BSFixedString.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiSmartPointer.h"

#include "Settings.h"

#include "Compass.h"
#include "QuestItemList.h"

namespace CNO
{
	class HUDMarkerManager
	{
	public:
		static HUDMarkerManager* GetSingleton()
		{
			static HUDMarkerManager singleton;

			return &singleton;
		}

		void ProcessQuestMarker(RE::TESQuest* a_quest, RE::BGSInstancedQuestObjective* a_questObjective,
								int a_questAgeIndex, RE::TESObjectREFR* a_marker, std::uint32_t a_markerIcon);

		void ProcessLocationMarker(RE::ExtraMapMarker* a_mapMarker, RE::TESObjectREFR* a_marker,
								   std::uint32_t a_markerIcon);

		void ProcessEnemyMarker(RE::Character* a_enemy, std::uint32_t a_markerIcon);

		void ProcessPlayerSetMarker(RE::TESObjectREFR* a_marker, std::uint32_t a_markerIcon);

		void SetMarkersExtraInfo();

	private:

		bool IsTheFocusedMarker(const RE::TESObjectREFR* a_marker) const
		{
			return focusedMarker && a_marker == focusedMarker->ref;
		}

		std::unique_ptr<Compass::Marker> GetMostCenteredMarker() const;

		bool UpdateFocusedMarker();

		float GetAngleBetween(const RE::PlayerCamera* a_playerCamera, const RE::TESObjectREFR* a_marker) const;

		// 罗盘注视门控：任务 yaw 聚焦之外，另要求“罗盘显示中 + 3D 视线看向罗盘”。
		// 读 settings::questlist::* 实时值，MCM 可热切；总开关关闭时恒返回 true。
		bool IsLookingAtCompass(const Compass* a_compass);

		// 有效注视模式（0=俯角兜底，1=右手节点，2=罗盘节点）：配置值不可用时自动降级。
		std::uint32_t GetEffectiveGazeMode();

		// 相机前向量（世界坐标单位向量）：旋转矩阵 12 个候选轴与已验证 yaw 自校准。
		bool GetCameraForward(RE::NiPoint3& a_forwardOut);

		// 罗盘可见性：GFx _visible/_alpha 与 skyVR_HUD01 节点可见性三者 OR。
		bool IsCompassVisible(const Compass* a_compass);

		RE::NiAVObject* FindCompassNode();
		RE::NiAVObject* FindHandNode();
		bool IsNodeVisible(const RE::NiAVObject* a_node) const;

		// 缓存节点是否仍属于当前场景根（读档/3D 重建后旧缓存必然失配，需重找）。
		bool IsNodeFromCurrentRoots(const RE::NiAVObject* a_node) const;

		bool IsPlayerAllyOfFaction(const RE::TESFaction* a_faction) const;

		bool IsPlayerOpponentOfFaction(const RE::TESFaction* a_faction) const;

		std::string GetSideInQuest(RE::QUEST_DATA::Type a_questType) const;

		static const RE::TESFaction* LookupFaction(RE::FormID a_localFormID, std::string_view a_modName)
		{
			const auto dataHandler = RE::TESDataHandler::GetSingleton();
			return dataHandler ? dataHandler->LookupForm<RE::TESFaction>(a_localFormID, a_modName) : nullptr;
		}

		float facingAngle = settings::display::angleToShowMarkerDetails;
		float keepFocusedAngle = settings::display::angleToKeepMarkerDetailsShown;

		float timePreFocusingMarker = 0.0F;

		std::vector<Compass::Marker> facedMarkers;
		std::unique_ptr<Compass::Marker> preFocusedMarker;
		std::unique_ptr<Compass::Marker> focusedMarker;
		RE::TESObjectREFR* displayedQuestMarker = nullptr;
		RE::TESObjectREFR* pendingQuestListMarker = nullptr;
		float questListFocusTime = 0.0F;

		// 注视门控状态：true 时用 keep 阈值，否则用 show 阈值（迟滞防抖）。
		bool compassGazeActive = false;

		std::uint32_t lastEffectiveGazeMode = 3;  // 3=尚未标定；变化时打一行 info/warn

		int calibratedForwardAxis = -1;  // 相机前向量标定：12 候选轴序号，-1=未标定

		RE::NiPointer<RE::NiAVObject> compassNode;  // skyVR_HUD01 缓存
		RE::NiPointer<RE::NiAVObject> handNode;     // 右手节点缓存

		float nodeRetryTime = 0.0F;  // 节点查找失败 1 秒后重试
		float gazeProbeTime = 0.0F;  // [QuestListGaze] 打点节流（约 2Hz）

		std::unordered_map<RE::TESObjectREFR*, std::unordered_map<RE::TESQuest*, QuestItem>> questItems;
		std::unordered_map<RE::TESObjectREFR*, QuestItem> miscQuestItem;

		RE::HUDMarkerManager* const hudMarkerManager = RE::HUDMarkerManager::GetSingleton();
		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
		RE::PlayerCamera* playerCamera = RE::PlayerCamera::GetSingleton();
		RE::BSTimer* timeManager = RE::BSTimer::GetTimeManager();

		// 按插件名和本地 FormID 查找，避免 VR/Creation Club 改变加载序号后得到空指针。
		const RE::TESFaction* const imperialLegionFaction = LookupFaction(0x02BF9A, "Skyrim.esm");
		const RE::TESFaction* const stormCloaksFaction = LookupFaction(0x028849, "Skyrim.esm");
		const RE::TESFaction* const sonsOfSkyrimFaction = LookupFaction(0x02BF9B, "Skyrim.esm");
		const RE::TESFaction* const dawnGuardFaction = LookupFaction(0x014217, "Dawnguard.esm");
		const RE::TESFaction* const vampireFaction = LookupFaction(0x003376, "Dawnguard.esm");
	};
}
