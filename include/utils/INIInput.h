#pragma once

#include <filesystem>
#include <string>
#include <string_view>

namespace utils
{
	// The game's INI reader does not recognize a UTF-8 BOM before the first
	// section. Present a temporary, BOM-free view without changing the source.
	class INIInput
	{
	public:
		explicit INIInput(const std::filesystem::path& a_source);
		~INIInput();

		INIInput(const INIInput&) = delete;
		INIInput& operator=(const INIInput&) = delete;

		const std::filesystem::path& GetPath() const { return path; }
		bool IsValid() const { return !path.empty(); }
		bool WasNormalized() const { return normalized; }
		std::string_view GetError() const { return error; }

	private:
		std::filesystem::path path;
		std::filesystem::path temporaryPath;
		std::string error;
		bool normalized = false;
	};
}
