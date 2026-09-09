#include "Internal.h"

#include "Settings.h"

#include "utils/INISettingCollection.h"
#include "utils/Logger.h"

namespace settings::detail
{
	namespace
	{
		bool settingsRegistered = false;
	}

		void RegisterSettingsOnce()
		{
			using namespace utils;

			if (settingsRegistered)
			{
				return;
			}
			settingsRegistered = true;

			INISettingCollection* iniSettingCollection = INISettingCollection::GetSingleton();

			// 每层只覆盖其包含的键。
			{
				using namespace debug;
				iniSettingCollection->AddSettings(
					MakeSetting("uLogLevel:Debug", static_cast<std::uint32_t>(logLevel)),
                    MakeSetting("bCalibrateQuestList:Debug", calibrateQuestList),
                    MakeSetting("uCalibrationAxis:Debug", calibrationAxis),
                    MakeSetting("fCalibrationStart:Debug", calibrationStart),
                    MakeSetting("fCalibrationStep:Debug", calibrationStep),
                    MakeSetting("fCalibrationCross:Debug", calibrationCross));
			}
			{
				using namespace display;
				iniSettingCollection->AddSettings(
					MakeSetting("bUseMetricUnits:Display", useMetricUnits),
					MakeSetting("fMarkerTextScale:Display", markerTextScale),
					MakeSetting("fMarkerNameScale:Display", markerNameScale),
					MakeSetting("fMarkerDistanceScale:Display", markerDistanceScale),
					MakeSetting("uUndiscoveredLocationMarkers:Display", static_cast<std::uint32_t>(undiscoveredLocationMarkers)),
					MakeSetting("bShowUndiscoveredLocationInfo:Display", showUndiscoveredLocationInfo),
					MakeSetting("bShowEnemyMarkers:Display", showEnemyMarkers),
					MakeSetting("bShowEnemyNameUnderMarker:Display", showEnemyNameUnderMarker),
					MakeSetting("bShowObjectiveAsTarget:Display", showObjectiveAsTarget),
					MakeSetting("bShowOtherObjectivesCount:Display", showOtherObjectivesCount),
					MakeSetting("bShowInteriorMarkers:Display", showInteriorMarkers),
					MakeSetting("fAngleToShowMarkerDetails:Display", angleToShowMarkerDetails),
					MakeSetting("fAngleToKeepMarkerDetailsShown:Display", angleToKeepMarkerDetailsShown),
					MakeSetting("fFocusingDelayToShow:Display", focusingDelayToShow));
			}
			{
				using namespace questlist;
				iniSettingCollection->AddSettings(
					MakeSetting("fOffsetX:QuestList", offsetX),
					MakeSetting("fOffsetY:QuestList", offsetY),
					MakeSetting("fPositionX:QuestList", positionX),
					MakeSetting("fPositionY:QuestList", positionY),
					MakeSetting("fTextScale:QuestList", textScale),
					MakeSetting("bShowInExteriors:QuestList", showInExteriors),
					MakeSetting("bShowInInteriors:QuestList", showInInteriors),
					MakeSetting("bHideInCombat:QuestList", hideInCombat),
					MakeSetting("bRequireLookingAtCompass:QuestList", requireLookingAtCompass),
					MakeSetting("bRequireCompassVisible:QuestList", requireCompassVisible),
					MakeSetting("uCompassGazeMode:QuestList", compassGazeMode),
					MakeSetting("fCompassGazeAngleToShow:QuestList", compassGazeAngleToShow),
					MakeSetting("fCompassGazeAngleToKeep:QuestList", compassGazeAngleToKeep),
					MakeSetting("fCompassMaxDistance:QuestList", compassMaxDistance),
					MakeSetting("fCompassGazePitchToShow:QuestList", compassGazePitchToShow),
					MakeSetting("fCompassGazePitchToKeep:QuestList", compassGazePitchToKeep),
					MakeSetting("bCompassOnPalm:QuestList", compassOnPalm));
			}

			logger::debug("Registered {} setting keys", CountSettings(
				reinterpret_cast<const RE::INISettingCollection*>(iniSettingCollection)));
		}
}
