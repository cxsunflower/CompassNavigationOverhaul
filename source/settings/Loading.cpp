#include "Settings.h"
#include "Internal.h"

#include "utils/INISettingCollection.h"
#include "utils/Logger.h"

// Three-layer loading, collection traversal and built-in default restoration.
// Key dispatch and one-time registration live in source/settings/.

namespace settings
{

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
		detail::RegisterSettingsOnce();
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
		logger::info("[Settings] effective logLevel={} debugEnabled={}",
			static_cast<std::uint32_t>(debug::logLevel), debug::IsDebugEnabled());

		return layersRead;
	}
}
