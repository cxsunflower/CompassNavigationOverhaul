#include "Settings.h"

#include "IUI/API.h"
#include "IUI/GFxLoggers.h"
#include "NND/NPCNameProvider.h"

#include "Compass.h"
#include "QuestItemList.h"
#include "Test.h"

#include "Hooks.h"

#undef GetModuleHandle

// 处理 SKSE 与 Infinity UI 消息；VR 额外支持 VR_HMD_info、三层 INI 热重载和 CoMAP。

const SKSE::LoadInterface* skse;

void InfinityUIMessageListener(SKSE::MessagingInterface::Message* a_msg);

// 将当前设置同步到已创建的 UI 实例。
static void ApplyAllSettings()
{
	const logger::level effectiveLogLevel = settings::debug::EffectiveLogLevel();
	logger::set_level(effectiveLogLevel, effectiveLogLevel);

	if (auto compass = CNO::Compass::GetSingleton())
	{
		compass->SetUnits();
	}

	if (auto questItemList = QuestItemList::GetSingleton())
	{
		questItemList->UpdateLayout();
		questItemList->SetMaxHeight(settings::questlist::maxHeight);
		questItemList->SetTextScale(settings::questlist::textScale);
	}
}

// 菜单关闭时仅在 INI 时间戳变化后重载，避免依赖 SE/VR 不一致的菜单名。
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

void SKSEMessageListener(SKSE::MessagingInterface::Message* a_msg)
{
	// 所有插件加载完成后初始化外部集成与设置。
	if (a_msg->type == SKSE::MessagingInterface::kPostLoad)
	{
		// Infinity UI 缺失时保留其他 Hook，只禁用 UI 替换。
		if (SKSE::GetMessagingInterface()->RegisterListener("InfinityUI", InfinityUIMessageListener))
		{
			logger::info("Successfully registered for Infinity UI messages!");
		}
		else
		{
			logger::error("Infinity UI installation not detected. Please, download it from https://www.nexusmods.com/skyrimspecialedition/mods/74483");
		}

		// VR 直接加载三层 INI，不注册 MCM++。
		settings::LoadFromINI();

		const logger::level effectiveLogLevel = settings::debug::EffectiveLogLevel();
		logger::set_level(effectiveLogLevel, effectiveLogLevel);

		// UI 单例可能尚未创建；补丁完成后会再次幂等同步。
		ApplyAllSettings();

		NND::NPCNameProvider::GetSingleton()->RequestAPI();

		// 保留 VR 侧的 CoMAP 兼容补丁。
		const SKSE::PluginInfo* mapMarkerFrameworkPluginInfo = skse->GetPluginInfo("MapMarkerFramework");

		if (mapMarkerFrameworkPluginInfo && mapMarkerFrameworkPluginInfo->version < 0x02020000)
		{
			logger::info("CoMAP detected. Loading compatibility patch...");
			hooks::compat::MapMarkerFramework::Install(GetModuleHandleA("MapMarkerFramework.dll"));
			hooks::compat::MapMarkerFramework::pluginInfo = mapMarkerFrameworkPluginInfo;
			logger::info("Successfully loaded compatibility patch for CoMAP!");
		}
	}
	// VR 新增：等到游戏数据加载完（此时 RE::UI 单例一定就绪）再挂菜单监听。
	else if (a_msg->type == SKSE::MessagingInterface::kDataLoaded)
	{
		RegisterINIReloadSink();
	}
}

// 替换前后记录成员列表与舞台坐标。
static void LogDisplayObject(IUI::GFxDisplayObject& a_object)
{
	static GFxMemberLogger<logger::level::debug> memberLogger;

	memberLogger.LogMembersOf(a_object);

	RE::GPointF origin = a_object.LocalToGlobal();

	logger::debug("{} is on ({}, {})", a_object.ToString().c_str(), origin.x, origin.y);
}

void InfinityUIMessageListener(SKSE::MessagingInterface::Message* a_msg)
{
	if (!a_msg || std::string_view(a_msg->sender) != "InfinityUI")
	{
		return;
	}

	if (auto message = IUI::API::TranslateAs<IUI::API::Message>(a_msg))
	{
		std::string_view movieUrl = message->movie->GetMovieDef()->GetFileURL();

		// SE 使用 HUDMenu.swf，VR 则把同一套 HUDMovieBaseInstance 放在 VR_HMD_info.swf 中。
		const bool isSupportedHUDMovie = movieUrl.find("HUDMenu") != std::string::npos ||
			movieUrl.find("VR_HMD_info") != std::string::npos;

		if (!isSupportedHUDMovie)
		{
			return;
		}

		switch (a_msg->type)
		{
		case IUI::API::Message::Type::kStartLoadInstances:
			logger::info("Started loading HUD patches");
			break;
		case IUI::API::Message::Type::kPreReplaceInstance:
			if (auto preReplaceMessage = IUI::API::TranslateAs<IUI::API::PreReplaceInstanceMessage>(a_msg))
			{
				std::string pathToOriginal = preReplaceMessage->originalInstance.ToString().c_str();

				if (pathToOriginal == CNO::Compass::path)
				{
					CNO::Compass::InitSingleton(preReplaceMessage->originalInstance);

					if (auto compass = CNO::Compass::GetSingleton())
					{
						logger::debug("Before replacing:");
						LogDisplayObject(*compass);
					}
				}
			}
			break;
		case IUI::API::Message::Type::kPostPatchInstance:
			if (auto postPatchMessage = IUI::API::TranslateAs<IUI::API::PostPatchInstanceMessage>(a_msg))
			{
				std::string pathToNew = postPatchMessage->newInstance.ToString().c_str();

				if (pathToNew == CNO::Compass::path)
				{
					// holder 应已在替换前初始化，否则说明补丁流程异常。
					if (auto compass = CNO::Compass::GetSingleton())
					{
						compass->SetupMod(postPatchMessage->newInstance);

						// 单例创建后补同步单位；重复调用无副作用。
						compass->SetUnits();

						logger::debug("After replacing:");
						LogDisplayObject(*compass);

						if (hooks::compat::MapMarkerFramework::pluginInfo)
						{
							hooks::compat::MapMarkerFramework::compassMovieDef = postPatchMessage->newInstanceMovieDef;
						}
					}
					else
					{
						logger::error("Compass instance counterpart not ready for {}", CNO::Compass::path);
					}
				}
				else if (pathToNew == QuestItemList::path)
				{
					QuestItemList::InitSingleton(postPatchMessage->newInstance);

					if (auto questItemList = QuestItemList::GetSingleton())
					{
						// 单例创建后补同步布局；两个调用均幂等。
						questItemList->UpdateLayout();
						questItemList->SetMaxHeight(settings::questlist::maxHeight);

						LogDisplayObject(*questItemList);
					}
				}
			}
			break;
		case IUI::API::Message::Type::kAbortPatchInstance:
			if (auto abortPatchMessage = IUI::API::TranslateAs<IUI::API::AbortPatchInstanceMessage>(a_msg))
			{
				std::string pathToOriginal = abortPatchMessage->originalValue.ToString().c_str();

				if (pathToOriginal == CNO::Compass::path)
				{
					logger::error("Aborted replacement of {}", CNO::Compass::path);
				}
			}
			break;
		case IUI::API::Message::Type::kFinishLoadInstances:
			if (auto finishLoadMessage = IUI::API::TranslateAs<IUI::API::FinishLoadInstancesMessage>(a_msg))
			{
				RE::GFxValue test;
				if (finishLoadMessage->movie->GetVariable(&test, Test::path.data()))
				{
					Test::InitSingleton(test);
				}
			}
			logger::info("Finished loading HUD patches");
			break;
		case IUI::API::Message::Type::kPostInitExtensions:
			if (auto postInitExtMessage = IUI::API::TranslateAs<IUI::API::PostInitExtensionsMessage>(a_msg))
			{
				if (auto questItemList = QuestItemList::GetSingleton())
				{
					questItemList->AddToHudElements();

					logger::debug("QuestItemList added to HUD elements");
				}

				logger::debug("Extensions initialization finished");
			}
			break;
		default:
			break;
		}
	}
}
