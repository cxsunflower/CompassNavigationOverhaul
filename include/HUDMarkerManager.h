#pragma once

#include "RE/H/HUDMarkerManager.h"

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
