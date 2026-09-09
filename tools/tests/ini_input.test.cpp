#include "utils/INIInput.h"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <windows.h>

namespace fs = std::filesystem;

static void Write(const fs::path& a_path, const std::string& a_data)
{
	std::ofstream out(a_path, std::ios::binary);
	out.write(a_data.data(), a_data.size());
	assert(out.good());
}

static std::string Read(const fs::path& a_path)
{
	std::ifstream in(a_path, std::ios::binary);
	return { std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>() };
}

static std::wstring Profile(const fs::path& a_path, const wchar_t* a_section, const wchar_t* a_key)
{
	wchar_t value[128]{};
	GetPrivateProfileStringW(a_section, a_key, L"<missing>", value, 128, a_path.c_str());
	return value;
}

int main()
{
	wchar_t directory[MAX_PATH + 1]{};
	assert(GetTempPathW(MAX_PATH + 1, directory) > 0);
	wchar_t name[MAX_PATH + 1]{};
	assert(GetTempFileNameW(directory, L"CNO", 0, name) != 0);
	const fs::path root = name;
	fs::remove(root);
	fs::create_directory(root);
	try
	{
		const fs::path source = root / "saved.ini";
		const std::string original = "\xEF\xBB\xBF[Debug]\r\nuLogLevel = 1\r\n\r\n[QuestList]\r\nfTextScale = 110\r\n";
		Write(source, original);
		assert(Profile(source, L"Debug", L"uLogLevel") == L"<missing>");
		assert(Profile(source, L"QuestList", L"fTextScale") == L"110");
		fs::path prepared;
		{
			utils::INIInput input(source);
			assert(input.IsValid() && input.WasNormalized());
			prepared = input.GetPath();
			assert(prepared != source && fs::exists(prepared));
			assert(Read(prepared) == original.substr(3));
			assert(Profile(prepared, L"Debug", L"uLogLevel") == L"1");
			assert(Profile(prepared, L"QuestList", L"fTextScale") == L"110");
			assert(Read(source) == original);
		}
		assert(!fs::exists(prepared));
		assert(Read(source) == original);
		std::cout << "PASS UTF-8 BOM first section, all other sections, source integrity and temporary cleanup\n";

		const fs::path plain = root / "plain.ini";
		Write(plain, original.substr(3));
		{
			utils::INIInput input(plain);
			assert(input.IsValid() && !input.WasNormalized() && input.GetPath() == plain);
		}
		assert(fs::exists(plain) && Read(plain) == original.substr(3));
		std::cout << "PASS no-BOM passthrough\n";

		const fs::path empty = root / "bom-only.ini";
		Write(empty, "\xEF\xBB\xBF");
		{
			utils::INIInput input(empty);
			assert(input.IsValid() && input.WasNormalized());
			assert(Read(input.GetPath()).empty());
		}
		assert(Read(empty) == "\xEF\xBB\xBF");
		std::cout << "PASS BOM-only input preserves the source\n";

		const fs::path missing = root / "missing.ini";
		utils::INIInput input(missing);
		assert(!input.IsValid() && !input.GetError().empty());
		assert(!fs::exists(missing));
		std::cout << "PASS missing source does not create a file\n";
	}
	catch (...)
	{
		fs::remove_all(root);
		throw;
	}
	fs::remove_all(root);
	return 0;
}
