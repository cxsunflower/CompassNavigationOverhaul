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
        inline bool calibrateQuestList = false;
        inline std::uint32_t calibrationAxis = 0;
        inline float calibrationStart = 700.0F;
        inline float calibrationStep = 40.0F;
        inline float calibrationCross = 512.0F;

		inline bool IsDebugEnabled()
		{
			return logLevel <= logger::level::debug;
		}


		inline logger::level EffectiveLogLevel()
		{
			return logLevel;
		}
	}

	namespace display
	{
		inline bool useMetricUnits = true;
		// 整体缩放（已废弃：保留解析，C++ 不再应用；用下面两个分量代替）。
		inline float markerTextScale = 100.0F;
		inline float markerNameScale = 100.0F;
		inline float markerDistanceScale = 100.0F;

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
		// Legacy position keys are read for compatibility only.
		inline float offsetX = 0.0F;
		inline float offsetY = 0.0F;
		inline float positionX = 0.008F;
		inline float positionY = 0.125F;
		inline float textScale = 100.0F;

		inline bool showInExteriors = true;
		inline bool showInInteriors = true;

		inline bool hideInCombat = false;

		// 罗盘注视门控：任务列表要求“罗盘显示中 + 3D 视线看向罗盘”。
		inline bool requireLookingAtCompass = true;
		inline bool requireCompassVisible = true;

		// 0=俯角兜底，1=右手节点，2=罗盘节点；高档缺失时自动降级。
		inline std::uint32_t compassGazeMode = 2;

		inline float compassGazeAngleToShow = 15.0F;
		inline float compassGazeAngleToKeep = 25.0F;
		inline float compassMaxDistance = 90.0F;  // 游戏单位，约 70 单位=1 米

		inline float compassGazePitchToShow = 18.0F;
		inline float compassGazePitchToKeep = 10.0F;

		// true=Palm Compass VR（低头看手掌），false=罗盘在视线上方（抬头看）。
		inline bool compassOnPalm = true;
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
