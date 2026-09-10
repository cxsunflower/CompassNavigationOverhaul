#include "Internal.h"

#include "Settings.h"
#include "../ui/SettingsLifecycle.h"

#include "HUDMarkerManager.h"

namespace hooks
{
	RE::TESWorldSpace* AllowedToShowMapMarker(const RE::TESObjectREFR* a_marker)
	{
		RE::TESWorldSpace* markerWorldspace = a_marker->GetWorldspace();

		if (settings::display::showInteriorMarkers)
		{
			auto player = RE::PlayerCharacter::GetSingleton();

			RE::TESWorldSpace* playerWorldspace = player->GetWorldspace();

			if (playerWorldspace && markerWorldspace && playerWorldspace != markerWorldspace)
			{
				if (!playerWorldspace->parentWorld && markerWorldspace->parentWorld == playerWorldspace) 
				{
					return playerWorldspace;
				}
			}
		}
			
		return markerWorldspace;
	}

	bool UpdateLocations(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
							   RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
							   std::uint32_t* a_markerSources, std::uint32_t a_markerSource)
	{
		RE::TESObjectREFR* marker = RE::TESObjectREFR::LookupByHandle(a_refHandle).get();
		RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();

		RE::NiPoint3 markerPos = util::GetRealPosition(marker);
		RE::NiPoint3 playerPos = util::GetRealPosition(player);

		float sqDistanceToMarker = playerPos.GetSquaredDistance(markerPos);

		if (sqDistanceToMarker < RE::HUDMarkerManager::GetSingleton()->sqRadiusToAddLocation)
		{
			auto mapMarker = marker->extraList.GetByType<RE::ExtraMapMarker>();

			// kHidden 时仅保留已发现地点，并延后读取 mapData 以保持短路安全。
			if (settings::display::undiscoveredLocationMarkers != settings::UndiscoveredLocationMarkers::kHidden ||
				mapMarker->mapData->flags.all(RE::MapMarkerData::Flag::kVisible))
			{
				if (HUDMarkerManager::AddMarker(a_hudMarkerManager, a_markerData, a_pos, a_refHandle, a_markerGotoFrame,
												a_markerSources, a_markerSource))
				{
					CNO::HUDMarkerManager::GetSingleton()->ProcessLocationMarker(mapMarker, marker, a_markerGotoFrame);

					return true;
				}
			}
		}

		return false;
	}

	bool UpdateEnemies(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
							RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
							std::uint32_t* a_markerSources, std::uint32_t a_markerSource)
	{
		if (settings::display::showEnemyMarkers)
		{
			if (HUDMarkerManager::AddMarker(a_hudMarkerManager, a_markerData, a_pos, a_refHandle, a_markerGotoFrame,
											a_markerSources, a_markerSource))
			{
				RE::TESObjectREFR* marker = RE::TESObjectREFR::LookupByHandle(a_refHandle).get();

				CNO::HUDMarkerManager::GetSingleton()->ProcessEnemyMarker(marker->As<RE::Character>(), a_markerGotoFrame);

				return true;
			}
		}

		return false;
	}

	bool UpdatePlayerSetMarker(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
								RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
								std::uint32_t* a_markerSources, std::uint32_t a_markerSource)
	{
		if (HUDMarkerManager::AddMarker(a_hudMarkerManager, a_markerData, a_pos, a_refHandle, a_markerGotoFrame,
										a_markerSources, a_markerSource))
		{
			RE::TESObjectREFR* marker = RE::TESObjectREFR::LookupByHandle(a_refHandle).get();

			CNO::HUDMarkerManager::GetSingleton()->ProcessPlayerSetMarker(marker, a_markerGotoFrame);

			return true;
		}

		return false;
	}

	void UpdateCompass(RE::Compass* a_compass)
	{
		hooks::Compass::Update(a_compass);

		CNO::HUDMarkerManager::GetSingleton()->SetMarkersExtraInfo();
		CNO::UI::PollDebugOverlay();
	}

}
