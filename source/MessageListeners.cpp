#include "MessageListeners.h"
#ifdef CNO_BUILD_PALMTEST
#include "palmtest/PalmTest.h"
#endif
#include "Settings.h"

#include "NND/NPCNameProvider.h"
#include "Hooks.h"
#include "ui/SettingsLifecycle.h"
#include "utils/Logger.h"

#undef GetModuleHandle

const SKSE::LoadInterface* skse;

void SKSEMessageListener(SKSE::MessagingInterface::Message* a_msg)
{
	if (!a_msg) return;
#ifdef CNO_BUILD_PALMTEST
	CNO::PalmTest::OnMessage(a_msg->type);
#endif
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
		CNO::UI::ApplyAllSettings();

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
	// VR 数据加载完成后初始化 UI 监听。
	else if (a_msg->type == SKSE::MessagingInterface::kDataLoaded)
	{
		CNO::UI::RegisterINIReloadSink();
	}
}
