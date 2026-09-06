#pragma once

namespace SKSE::log
{
	using level = spdlog::level::level_enum;
}
namespace logger = SKSE::log;

// 设置由三层 INI 叠加提供，不依赖 MCM++；键名与上游 2.9.9 保持一致。

namespace settings
{
	// 未发现地点的三态显示方式，对应 MCM stepper 的三个选项。
	enum class UndiscoveredLocationMarkers : std::uint32_t
	{
		kHidden = 0,  // 完全不上罗盘
		kUnknown = 1,  // 上罗盘，但图标换成「?」
		kNormal = 2  // 上罗盘，用正常图标
	};

	// 默认值与随包 settings.ini 一致。

	namespace debug
	{
		inline logger::level logLevel = logger::level::info;

		inline logger::level EffectiveLogLevel()
		{
			return logLevel;
		}
	}

	namespace display
	{
		inline bool useMetricUnits = true;
		inline float markerTextScale = 100.0F;

		inline UndiscoveredLocationMarkers undiscoveredLocationMarkers = UndiscoveredLocationMarkers::kHidden;

		// 该正向开关与 2.2.0 的 undiscoveredMeansUnknownInfo 极性相反。
		inline bool showUndiscoveredLocationInfo = false;

		inline bool showEnemyMarkers = true;
		inline bool showEnemyNameUnderMarker = true;

		// false 显示地点，true 显示任务目标。
		inline bool showObjectiveAsTarget = true;

		inline bool showOtherObjectivesCount = true;

		inline bool showInteriorMarkers = true;

		inline float angleToShowMarkerDetails = 10.0F;
		inline float angleToKeepMarkerDetailsShown = 35.0F;
		inline float focusingDelayToShow = 0.1F;
	}

	namespace questlist
	{
		inline float positionX = 0.008F;
		inline float positionY = 0.125F;
		inline float textScale = 100.0F;

		inline float maxHeight = 0.675F;

		inline bool showInExteriors = true;
		inline bool showInInteriors = true;

		inline bool hideInCombat = false;
	}

	// 按完整的“键名:分区”分发设置。
	void OnSettingChanged(const RE::Setting* a_setting);

	// 将集合中的所有设置分发到运行时变量。
	void InitFromCollection(const RE::INISettingCollection* a_collection);

	// 统计设置节点，用于注册自检。
	std::size_t CountSettings(const RE::INISettingCollection* a_collection);

	// 按默认值、用户 INI、MCM Helper 的顺序叠加，后读层优先。
	// 重载前恢复内置默认值，确保删除高优先级键后能正确回落。
	inline constexpr std::string_view iniDefaultsPath = "MCM\\Config\\Compass Navigation Overhaul VR\\settings.ini";
	inline constexpr std::string_view iniMcmHelperPath = "MCM\\Settings\\Compass Navigation Overhaul VR.ini";
	inline constexpr std::string_view iniUserPath = "SKSE\\Plugins\\CompassNavigationOverhaulVR.ini";

	// 加载三层设置并返回成功读取的文件数；可重复调用以热重载。
	std::size_t LoadFromINI();
}
