#pragma once

#include "IUI/GFxArray.h"
#include "IUI/GFxDisplayObject.h"
#include "IUI/GFxObject.h"

#include "RE/G/GFxMovieDef.h"

#include "Settings.h"
#include "questlist/QuestData.h"

class QuestItemList : public IUI::GFxDisplayObject
{
public:
	// Attach inside Compass so VR scene-node movement includes the quest details.
	static constexpr inline std::string_view path = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.Compass.FocusedMarkerInfo.Target.QuestItemList";

	static void InitSingleton(const GFxDisplayObject& a_questItemList);
	static void ResetSingleton();

	static QuestItemList* GetSingleton() { return singleton; }

	bool CanBeDisplayed(RE::TESObjectCELL* a_cell, bool a_isPlayerWeaponDrawn) const;

	void SetHiddenByForce(bool a_hiddenByForce) { hiddenByForce = a_hiddenByForce; }

	bool IsHiddenByForce() const { return hiddenByForce; }

	// Position belongs to the compass anchor, including after settings reloads.
	void UpdateLayout();

	void AnchorBelow(IUI::GFxDisplayObject a_anchorTextField, float a_gap = 6.0F);

	void SetTextScale(float a_scale);

	void AddToHudElements();

	void AddQuest(const QuestItem& a_questItem);

	void SetQuestSide(const std::string& a_sideName);

	// Reconcile live rows by stable quest/instance keys without restarting fades.
	void SyncQuests(const std::vector<QuestItem>& a_quests);

	void Update();

	void ShowAllQuests();

	void RemoveAllQuests();

private:

	// 零参数初始化 AS 实例，并保存舞台原点供 UpdateLayout 使用。
	QuestItemList(const GFxDisplayObject& a_questItemList);

	static inline QuestItemList* singleton = nullptr;
	static inline std::unique_ptr<QuestItemList> owner;

	// 成员顺序必须与 DLL 中的布局一致（GFxValue 占 0x00-0x17）：
	//   originX @0x18、originY @0x1c、hiddenByForce @0x20。
	float originX = 0.0F;
	float originY = 0.0F;

	bool hiddenByForce = false;

	// Keep the original GFx-related members and offsets unchanged.
	bool hasQuestSnapshot = false;
	std::string lastQuestSignature;
};
