#pragma once

// Shared implementation detail for the three-layer INI loader. Public settings
// remain in include/Settings.h; no additional runtime state is introduced here.
namespace settings::detail
{
	void RegisterSettingsOnce();
}
