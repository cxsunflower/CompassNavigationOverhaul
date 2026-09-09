#pragma once

#include "IUI/GFxDisplayObject.h"

#include "utils/Geometry.h"

namespace CNO
{
	class Compass : public IUI::GFxDisplayObject
	{
	public:
		struct Marker
		{
			Marker(RE::TESObjectREFR* a_markerRef, float a_angleToPlayerCamera,
				   std::uint32_t a_index, std::uint32_t a_icon, const std::string_view& a_description) :
				ref{ a_markerRef }, angleToPlayerCamera{ a_angleToPlayerCamera },
				index{ a_index }, icon{ a_icon }, description{ a_description }
			{}

			RE::TESObjectREFR* ref;
			float angleToPlayerCamera;
			float distanceToPlayer = util::GetDistanceBetween(RE::PlayerCharacter::GetSingleton(), ref);
			float heightDifference = util::GetHeightDifferenceBetween(RE::PlayerCharacter::GetSingleton(), ref);
			std::uint32_t index;
			std::uint32_t icon;
			std::string description;
		};

		static constexpr inline std::string_view path = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass";

		static void InitSingleton(const GFxDisplayObject& a_originalCompass);

		static Compass* GetSingleton() { return singleton; }

		void SetupMod(const GFxDisplayObject& a_replaceCompass);

		// 从全局设置读取单位，可安全重复调用。
		void SetUnits();

		// 整体缩放（已废弃，保留封装供回退）：ApplyAllSettings 改调下面两个分量接口。
		void SetMarkerTextScale(float a_scale);

		void SetMarkerNameScale(float a_scale);

		void SetMarkerDistanceScale(float a_scale);

		void SetFocusedMarkerInfo(const std::string_view& a_targetText, float a_distance,
								  float a_heightDifference, std::uint32_t a_markerIndex);

		IUI::GFxDisplayObject GetFocusedMarkerTargetTextField();

		void FocusMarker();

		void UnfocusMarker();

		void UpdateFocusedMarker();

		// 未知地点图标由 HUDMarkerManager::ProcessLocationMarker 直接更新。

	private:
		Compass(const GFxDisplayObject& a_originalCompass) : GFxDisplayObject{ a_originalCompass }
		{}

		static inline Compass* singleton = nullptr;
	};
}
