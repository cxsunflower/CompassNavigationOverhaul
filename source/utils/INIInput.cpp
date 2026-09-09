#include "utils/INIInput.h"

#include <array>
#include <fstream>
#include <windows.h>

namespace utils
{
	INIInput::INIInput(const std::filesystem::path& a_source) : path(a_source)
	{
		std::ifstream input(a_source, std::ios::binary);
		if (!input)
		{
			path.clear();
			error = "cannot open source INI";
			return;
		}

		std::array<unsigned char, 3> prefix{};
		input.read(reinterpret_cast<char*>(prefix.data()), prefix.size());
		if (input.gcount() != 3 || prefix != std::array<unsigned char, 3>{ 0xEF, 0xBB, 0xBF })
		{
			// Existing ANSI/UTF-16/no-BOM files keep the original native path.
			return;
		}

		input.clear();
		input.seekg(3, std::ios::beg);
		wchar_t directory[MAX_PATH + 1]{};
		const DWORD length = GetTempPathW(MAX_PATH + 1, directory);
		if (length == 0 || length > MAX_PATH)
		{
			path.clear();
			error = "cannot resolve temporary directory";
			return;
		}

		wchar_t name[MAX_PATH + 1]{};
		if (GetTempFileNameW(directory, L"CNO", 0, name) == 0)
		{
			path.clear();
			error = "cannot create temporary INI";
			return;
		}
		temporaryPath = name;
		{
			std::ofstream output(temporaryPath, std::ios::binary | std::ios::trunc);
			if (!output)
			{
				path.clear();
				error = "cannot write temporary INI";
				return;
			}
			// A BOM-only file is valid; streambuf insertion alone sets failbit
			// when there are no payload bytes to copy.
			if (input.peek() != std::char_traits<char>::eof())
			{
				output << input.rdbuf();
			}
			output.flush();
			if (!output || input.bad())
			{
				path.clear();
				error = "cannot complete temporary INI";
				return;
			}
		}
		path = temporaryPath;
		normalized = true;
	}

	INIInput::~INIInput()
	{
		if (!temporaryPath.empty())
		{
			std::error_code ec;
			std::filesystem::remove(temporaryPath, ec);
		}
	}
}
