#include "Settings.h"

#include "utils/INISettingCollection.h"
#include "utils/Logger.h"

// 按完整键名分发 18 个设置。

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
				markerTextScale = a_setting->GetFloat();
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
				textScale = a_setting->GetFloat();
				return;
			}
			if (name == "fMaxHeight:QuestList")
			{
				maxHeight = a_setting->GetFloat();
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
		}

		// 未识别的键不参与运行时设置。
		logger::trace("Ignored unknown setting: {}", name);
	}

	void InitFromCollection(const RE::INISettingCollection* a_collection)
	{
		if (!a_collection)
		{
			return;
		}

		// CommonLibVR 的 BSSimpleList::begin() const 有 const 正确性 bug：
		// const Node* 无法构造 const_iterator，编译报 C2440。
		// 对 list 成员 const_cast 走非 const begin() 即可，集合数据并未被修改。
		auto& settingsList = const_cast<RE::BSSimpleList<RE::Setting*>&>(a_collection->settings);
		for (const RE::Setting* setting : settingsList)
		{
			OnSettingChanged(setting);
		}
	}

	std::size_t CountSettings(const RE::INISettingCollection* a_collection)
	{
		if (!a_collection)
		{
			return 0;
		}

		std::size_t count = 0;
		auto& settingsList = const_cast<RE::BSSimpleList<RE::Setting*>&>(a_collection->settings);
		for ([[maybe_unused]] const RE::Setting* setting : settingsList)
		{
			++count;
		}

		return count;
	}

	// 三层 INI 共用同一组 Setting 对象和分发入口。
	namespace
	{
		// 18 个 RE::Setting 对象只允许注册一次。
		// InsertSetting 不去重：重复注册会让 BSSimpleList 里出现同名节点，
		// InitFromCollection 就会对同一个键调多次 OnSettingChanged，且旧节点永远泄漏。
		bool settingsRegistered = false;

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
					MakeSetting("uLogLevel:Debug", static_cast<std::uint32_t>(logLevel)));
			}
			{
				using namespace display;
				iniSettingCollection->AddSettings(
					MakeSetting("bUseMetricUnits:Display", useMetricUnits),
					MakeSetting("fMarkerTextScale:Display", markerTextScale),
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
					MakeSetting("fPositionX:QuestList", positionX),
					MakeSetting("fPositionY:QuestList", positionY),
					MakeSetting("fTextScale:QuestList", textScale),
					MakeSetting("fMaxHeight:QuestList", maxHeight),
					MakeSetting("bShowInExteriors:QuestList", showInExteriors),
					MakeSetting("bShowInInteriors:QuestList", showInInteriors),
					MakeSetting("bHideInCombat:QuestList", hideInCombat));
			}

			// 18 以外的数量表示注册异常。
			logger::debug("Registered {} setting keys", CountSettings(
				reinterpret_cast<const RE::INISettingCollection*>(iniSettingCollection)));
		}

		// 读一层。文件不存在 / 打不开都只是「这一层没有」，不是错误。
		bool ReadLayer(std::string_view a_dataRelativePath)
		{
			utils::INISettingCollection* iniSettingCollection = utils::INISettingCollection::GetSingleton();

			if (!iniSettingCollection->ReadFromFile(a_dataRelativePath))
			{
				logger::debug("Skipping Data\\{} (missing or unreadable)", a_dataRelativePath);
				return false;
			}

			// 每读完一层便应用当前集合。
			InitFromCollection(reinterpret_cast<const RE::INISettingCollection*>(iniSettingCollection));

			logger::info("Loaded Data\\{}", a_dataRelativePath);
			return true;
		}

		// 保存注册时的内置默认值。Data 联合体无法按值复制，因此保存其原始字节：
		// CommonLibVR 的 RE::Color 拷贝构造/赋值是用户提供的（非平凡），导致
		// RE::Setting::Data 的复制操作被删除；这些键不含 kString，不涉及指针所有权。
		std::vector<std::pair<RE::Setting*, std::uint64_t>> builtinDefaults;

		void CaptureBuiltinDefaultsOnce()
		{
			if (!builtinDefaults.empty())
			{
				return;
			}

			auto* collection = reinterpret_cast<RE::INISettingCollection*>(
				utils::INISettingCollection::GetSingleton());

			for (RE::Setting* setting : collection->settings)
			{
				if (setting && setting->GetType() != RE::Setting::Type::kString)
				{
					std::uint64_t snapshot = 0;
					std::memcpy(&snapshot, &setting->data, sizeof(snapshot));
					builtinDefaults.emplace_back(setting, snapshot);
				}
			}
		}

		// 重载前恢复默认值，避免删除高优先级键后残留旧值。
		void RestoreBuiltinDefaults()
		{
			for (auto& [setting, data] : builtinDefaults)
			{
				std::memcpy(&setting->data, &data, sizeof(setting->data));
			}
		}
	}

	std::size_t LoadFromINI()
	{
		RegisterSettingsOnce();
		CaptureBuiltinDefaultsOnce();
		RestoreBuiltinDefaults();

		std::size_t layersRead = 0;

		// 顺序即优先级：默认值 → 用户 INI → MCM Helper。
		for (const std::string_view path : { iniDefaultsPath, iniUserPath, iniMcmHelperPath })
		{
			if (ReadLayer(path))
			{
				++layersRead;
			}
		}

		if (layersRead == 0)
		{
			logger::warn("None of the three INI files could be read, using built-in defaults");
		}

		return layersRead;
	}
}
