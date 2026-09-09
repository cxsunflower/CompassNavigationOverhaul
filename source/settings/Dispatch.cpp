#include "Settings.h"
#include "utils/Logger.h"

// Keep the original section-qualified dispatch and all value clamps.
namespace settings
{
	void OnSettingChanged(const RE::Setting* a_setting)
	{
		if (!a_setting || !a_setting->GetName())
		{
			return;
		}

		const std::string_view name{ a_setting->GetName() };

		// ---- [Debug] ----
		{
			using namespace debug;

            if (name == "bCalibrateQuestList:Debug") { calibrateQuestList = a_setting->GetBool(); return; }
            if (name == "uCalibrationAxis:Debug") { calibrationAxis = std::min<std::uint32_t>(1, a_setting->GetUnsignedInteger()); return; }
            if (name == "fCalibrationStart:Debug") { calibrationStart = std::max(0.0F, std::min(1024.0F, a_setting->GetFloat())); return; }
            if (name == "fCalibrationStep:Debug") { calibrationStep = std::max(2.0F, std::min(80.0F, a_setting->GetFloat())); return; }
            if (name == "fCalibrationCross:Debug") { calibrationCross = std::max(12.0F, std::min(1012.0F, a_setting->GetFloat())); return; }
			if (name == "uLogLevel:Debug")
			{
				logLevel = static_cast<logger::level>(a_setting->GetUnsignedInteger());
				return;
			}

		}

		// ---- [Display] ----
		{
			using namespace display;

			if (name == "bUseMetricUnits:Display")
			{
				useMetricUnits = a_setting->GetBool();
				return;
			}
			if (name == "fMarkerTextScale:Display")
			{
				markerTextScale = std::max(25.0F, std::min(200.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "fMarkerNameScale:Display")
			{
				markerNameScale = std::max(25.0F, std::min(150.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "fMarkerDistanceScale:Display")
			{
				markerDistanceScale = std::max(25.0F, std::min(150.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "uUndiscoveredLocationMarkers:Display")
			{
				// 三态：0=隐藏 / 1="?" / 2=正常图标
				undiscoveredLocationMarkers = static_cast<UndiscoveredLocationMarkers>(a_setting->GetUnsignedInteger());
				return;
			}
			if (name == "bShowUndiscoveredLocationInfo:Display")
			{
				showUndiscoveredLocationInfo = a_setting->GetBool();
				return;
			}
			if (name == "bShowEnemyMarkers:Display")
			{
				showEnemyMarkers = a_setting->GetBool();
				return;
			}
			if (name == "bShowEnemyNameUnderMarker:Display")
			{
				showEnemyNameUnderMarker = a_setting->GetBool();
				return;
			}
			if (name == "bShowObjectiveAsTarget:Display")
			{
				showObjectiveAsTarget = a_setting->GetBool();
				return;
			}
			if (name == "bShowOtherObjectivesCount:Display")
			{
				showOtherObjectivesCount = a_setting->GetBool();
				return;
			}
			if (name == "bShowInteriorMarkers:Display")
			{
				showInteriorMarkers = a_setting->GetBool();
				return;
			}
			if (name == "fAngleToShowMarkerDetails:Display")
			{
				angleToShowMarkerDetails = a_setting->GetFloat();
				return;
			}
			if (name == "fAngleToKeepMarkerDetailsShown:Display")
			{
				angleToKeepMarkerDetailsShown = a_setting->GetFloat();
				return;
			}
			if (name == "fFocusingDelayToShow:Display")
			{
				focusingDelayToShow = a_setting->GetFloat();
				return;
			}
		}

		// ---- [QuestList] ----
		{
			using namespace questlist;

			if (name == "fOffsetX:QuestList")
			{
				offsetX = std::max(-100.0F, std::min(100.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "fOffsetY:QuestList")
			{
				offsetY = std::max(-100.0F, std::min(100.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "fPositionX:QuestList")
			{
				positionX = a_setting->GetFloat();
				return;
			}
			if (name == "fPositionY:QuestList")
			{
				positionY = a_setting->GetFloat();
				return;
			}
			if (name == "fTextScale:QuestList")
			{
				textScale = std::max(25.0F, std::min(110.0F, a_setting->GetFloat()));
				return;
			}
			if (name == "bShowInExteriors:QuestList")
			{
				showInExteriors = a_setting->GetBool();
				return;
			}
			if (name == "bShowInInteriors:QuestList")
			{
				showInInteriors = a_setting->GetBool();
				return;
			}
			if (name == "bHideInCombat:QuestList")
			{
				hideInCombat = a_setting->GetBool();
				return;
			}
			if (name == "bRequireLookingAtCompass:QuestList")
			{
				requireLookingAtCompass = a_setting->GetBool();
				return;
			}
			if (name == "bRequireCompassVisible:QuestList")
			{
				requireCompassVisible = a_setting->GetBool();
				return;
			}
			if (name == "uCompassGazeMode:QuestList")
			{
				compassGazeMode = std::min<std::uint32_t>(a_setting->GetUnsignedInteger(), 2);
				return;
			}
			if (name == "fCompassGazeAngleToShow:QuestList")
			{
				compassGazeAngleToShow = a_setting->GetFloat();
				return;
			}
			if (name == "fCompassGazeAngleToKeep:QuestList")
			{
				compassGazeAngleToKeep = a_setting->GetFloat();
				return;
			}
			if (name == "fCompassMaxDistance:QuestList")
			{
				compassMaxDistance = a_setting->GetFloat();
				return;
			}
			if (name == "fCompassGazePitchToShow:QuestList")
			{
				compassGazePitchToShow = a_setting->GetFloat();
				return;
			}
			if (name == "fCompassGazePitchToKeep:QuestList")
			{
				compassGazePitchToKeep = a_setting->GetFloat();
				return;
			}
			if (name == "bCompassOnPalm:QuestList")
			{
				compassOnPalm = a_setting->GetBool();
				return;
			}
		}

		// 未识别的键不参与运行时设置。
		logger::trace("Ignored unknown setting: {}", name);
	}
}
