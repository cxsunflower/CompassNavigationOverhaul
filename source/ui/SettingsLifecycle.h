#pragma once

class QuestItemList;

namespace CNO::UI
{
	// Shared by embedded initialization, compatibility patches and INI reloads.
	void ApplyQuestListSettings(QuestItemList& a_list);
	void ApplyAllSettings();
	void RegisterINIReloadSink();
}
