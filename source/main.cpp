#include "Hooks.h"
#include "Settings.h"
#include "MessageListeners.h"

#include "utils/Logger.h"

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	REL::Module::reset();
	
	skse = a_skse;

	const SKSE::PluginDeclaration* plugin = SKSE::PluginDeclaration::GetSingleton();

	if (!logger::init(plugin->GetName()))
	{
		return false;
	}

	logger::info("Loading {} {}...", plugin->GetName(), plugin->GetVersion());

	SKSE::Init(a_skse);

	// SKSEVR 可能把同一份 1.4.15 可执行文件报告为 build 0 或 build 1；二者共享已验证的机器码布局。
	const auto runtimeVersion = a_skse->RuntimeVersion();
	const bool supportedRuntime = REL::Module::IsVR() &&
		 runtimeVersion.major() == 1 && runtimeVersion.minor() == 4 && runtimeVersion.patch() == 15 &&
		 runtimeVersion.build() <= 1;

	if (!supportedRuntime)
	{
		logger::critical("Unsupported runtime version: {}", runtimeVersion.string());
		return false;
	}

	// 设置在 kPostLoad 阶段按三层 INI 加载；此处先使用内置默认值初始化日志。
	const logger::level effectiveLogLevel = settings::debug::EffectiveLogLevel();
	logger::set_level(effectiveLogLevel, effectiveLogLevel);

	if (!SKSE::GetMessagingInterface()->RegisterListener("SKSE", SKSEMessageListener))
	{
		return false;
	}

	if (!hooks::Install())
	{
		return false;
	}

	logger::set_level(logger::level::info, logger::level::info);
	logger::info("Successfully loaded!");

	logger::set_level(effectiveLogLevel, effectiveLogLevel);

	return true;
}
