#include "HUDMarkerManager.h"
#include "NND/NPCNameProvider.h"

namespace CNO
{

	void HUDMarkerManager::ProcessLocationMarker(RE::ExtraMapMarker* a_mapMarker, RE::TESObjectREFR* a_marker,
												 std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_marker);

		bool isDiscoveredLocation = a_mapMarker->mapData->flags.all(RE::MapMarkerData::Flag::kVisible);

		// 已发现地点始终显示详情；未发现地点由正向开关控制。
		if (isDiscoveredLocation || settings::display::showUndiscoveredLocationInfo)
		{
			if ((IsTheFocusedMarker(a_marker) && angleToPlayerCamera < keepFocusedAngle) ||
				angleToPlayerCamera < facingAngle)
			{
				std::string_view locationFullName = a_mapMarker->mapData->locationName.GetFullName();

				facedMarkers.emplace_back(a_marker, angleToPlayerCamera,
										  hudMarkerManager->currentMarkerIndex - 1,
										  a_markerIcon, locationFullName);
			}

			if (isDiscoveredLocation)
			{
				return;
			}
		}

		// kHidden 已在 Hook 入口过滤；kUnknown 使用 AS 的 0 号“?”图标帧。
		if (settings::display::undiscoveredLocationMarkers == settings::UndiscoveredLocationMarkers::kUnknown)
		{
			hudMarkerManager->scaleformMarkerData[hudMarkerManager->currentMarkerIndex - 1].icon.SetNumber(0);
		}
	}

	void HUDMarkerManager::ProcessEnemyMarker(RE::Character* a_enemy, std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_enemy);

		if ((IsTheFocusedMarker(a_enemy) && angleToPlayerCamera < keepFocusedAngle) ||
			angleToPlayerCamera < facingAngle)
		{
			// 关闭名称时跳过 NND 查询。
			const char* enemyName = settings::display::showEnemyNameUnderMarker ?
										NND::NPCNameProvider::GetSingleton()->GetName(a_enemy) :
										"";

			facedMarkers.emplace_back(a_enemy, angleToPlayerCamera,
									hudMarkerManager->currentMarkerIndex - 1,
									a_markerIcon, enemyName);
		}
	}

	void HUDMarkerManager::ProcessPlayerSetMarker(RE::TESObjectREFR* a_marker, std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_marker);

		if ((IsTheFocusedMarker(a_marker) && angleToPlayerCamera < keepFocusedAngle) ||
			angleToPlayerCamera < facingAngle)
		{
			facedMarkers.emplace_back(a_marker, angleToPlayerCamera,
										hudMarkerManager->currentMarkerIndex - 1,
										a_markerIcon, "");
		}
	}
}
