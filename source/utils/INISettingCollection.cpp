#include "utils/INISettingCollection.h"

#include "utils/Logger.h"

namespace utils
{
	INISettingCollection::INISettingCollection() noexcept
	{
		REL::Relocation<std::uintptr_t> __vTable(*reinterpret_cast<std::uintptr_t*>(this));

		// 复用 Skyrim 的 INISettingCollection 虚函数。
		static std::uintptr_t* skyrimsVTable = REL::Relocation<std::uintptr_t*>{ vTableId }.get();

		// 除索引 0 的析构函数外全部替换。
		for (int i = 1; i < 10; i++) {
			__vTable.write_vfunc(i, skyrimsVTable[i]);
		}
	}

	// 路径相对于游戏 Data 目录，由调用方指定以支持多层设置。
	bool INISettingCollection::ReadFromFile(std::string_view a_dataRelativePath)
	{
		std::filesystem::path iniPath = std::filesystem::current_path().append("Data").append(a_dataRelativePath);

		const std::string iniPathStr = iniPath.string();

		// subKey 只有 MAX_PATH 字节，超长直接放弃，避免 strcpy_s 触发断言/越界。
		if (iniPathStr.empty() || iniPathStr.size() >= MAX_PATH)
		{
			subKey[0] = '\0';
			return false;
		}

		strcpy_s(subKey, iniPathStr.c_str());

		if (_this()->OpenHandle(false)) {
			_this()->ReadAllSettings();
			_this()->CloseHandle();

			return true;
		}

		return false;
	}
}
