#include "SettingsLifecycle.h"

#include "Settings.h"
#include "Compass.h"
#include "QuestItemList.h"
#include "utils/Logger.h"

namespace CNO::UI
{
void ApplyQuestListSettings(QuestItemList& a_list)
{
	a_list.UpdateLayout();
	a_list.SetTextScale(settings::questlist::textScale);
	const bool enabled = settings::debug::IsDebugEnabled();
	const bool available = a_list.HasMember("SetLayoutDebug");
	if (available)
	{
		a_list.Invoke("SetLayoutDebug", enabled);
	}
	const std::string debugState = a_list.HasMember("GetLayoutDebugState") ?
		a_list.Invoke("GetLayoutDebugState").ToString().c_str() : "unavailable";
	logger::info("[QuestListDebug] level={} requested={} method={} state={}",
		static_cast<std::uint32_t>(settings::debug::logLevel), enabled, available, debugState);
    if (a_list.HasMember("SetCalibration"))
    {
        a_list.Invoke("SetCalibration", settings::debug::calibrateQuestList,
            settings::debug::calibrationAxis, settings::debug::calibrationStart,
            settings::debug::calibrationStep, settings::debug::calibrationCross);
        logger::info("[QuestListCalibration] {}", a_list.Invoke("GetCalibrationState").ToString().c_str());
    }
	// Snapshot after the new scale has been laid out, not before the next frame.
	const auto state = a_list.Invoke(a_list.HasMember("GetLayoutSnapshot") ?
		"GetLayoutSnapshot" : "GetAnchorState");
	logger::info("[QuestListLayout] panel={} {}", settings::questlist::textScale,
		state.ToString().c_str());
}

void ApplyAllSettings()
{
	const logger::level effectiveLogLevel = settings::debug::EffectiveLogLevel();
	logger::set_level(effectiveLogLevel, effectiveLogLevel);

	if (auto compass = CNO::Compass::GetSingleton())
	{
		compass->SetUnits();
		compass->SetMarkerNameScale(settings::display::markerNameScale);
		compass->SetMarkerDistanceScale(settings::display::markerDistanceScale);
		if (compass->HasMember("GetMarkerScaleState"))
		{
			const auto state = compass->Invoke("GetMarkerScaleState");
			logger::info("[MarkerScale] {}", state.ToString().c_str());
		}
		else
		{
			logger::warn("[MarkerScale] diagnostic SWF method missing");
		}
	}

	if (auto questItemList = QuestItemList::GetSingleton())
	{
		ApplyQuestListSettings(*questItemList);
	}
}

	namespace
	{
	std::filesystem::path INIFullPath(std::string_view a_dataRelativePath)
	{
		std::error_code ec;
		std::filesystem::path root = std::filesystem::current_path(ec);

		if (ec)
		{
			return {};
		}

		return root / "Data" / a_dataRelativePath;
	}

	// 首次调用只负责「记下当前状态」并返回 false（那一刻 kPostLoad 已经读过了）。
	bool AnyINIChanged()
	{
		static constexpr std::array<std::string_view, 3> paths{
			settings::iniDefaultsPath,
			settings::iniMcmHelperPath,
			settings::iniUserPath
		};

		static std::array<std::filesystem::file_time_type, paths.size()> lastWrites{};
		static bool primed = false;

		bool changed = false;

		for (std::size_t i = 0; i < paths.size(); ++i)
		{
			std::error_code ec;
			const std::filesystem::path fullPath = INIFullPath(paths[i]);
			const std::filesystem::file_time_type writeTime =
				fullPath.empty() ? std::filesystem::file_time_type{} : std::filesystem::last_write_time(fullPath, ec);

			// 文件不存在就统一记成默认时间戳：从「有」变「没有」也算变了。
			const std::filesystem::file_time_type stamp = ec ? std::filesystem::file_time_type{} : writeTime;

			if (stamp != lastWrites[i])
			{
				lastWrites[i] = stamp;
				changed = true;
			}
		}

		if (!primed)
		{
			primed = true;
			return false;
		}

		return changed;
	}

	class INIReloadSink : public RE::BSTEventSink<RE::MenuOpenCloseEvent>
	{
	public:
		static INIReloadSink* GetSingleton()
		{
			static INIReloadSink singleton;

			return &singleton;
		}

		RE::BSEventNotifyControl ProcessEvent(
			const RE::MenuOpenCloseEvent* a_event,
			RE::BSTEventSource<RE::MenuOpenCloseEvent>*) override
		{
			// 只在关闭时检查：菜单打开的那一帧玩家还没机会改文件。
			if (a_event && !a_event->opening && AnyINIChanged())
			{
				logger::info("INI change detected, reloading settings");

				settings::LoadFromINI();
				ApplyAllSettings();
			}

			return RE::BSEventNotifyControl::kContinue;
		}

	private:
		INIReloadSink() = default;
	};

	}

	void RegisterINIReloadSink()
	{
		// 三层 INI 是唯一设置来源，因此始终启用热重载。
		RE::UI* ui = RE::UI::GetSingleton();

		if (!ui)
		{
			logger::error("Failed to get RE::UI singleton, INI hot-reload unavailable");
			return;
		}

		// 记录基线，避免第一次关闭菜单时误判。
		AnyINIChanged();

		ui->AddEventSink<RE::MenuOpenCloseEvent>(INIReloadSink::GetSingleton());

		logger::info("INI hot-reload enabled: edit Data\\{} then open and close any menu to apply", settings::iniUserPath);
	}
}
