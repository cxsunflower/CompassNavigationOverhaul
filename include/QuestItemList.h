#pragma once

#include "IUI/GFxArray.h"
#include "IUI/GFxDisplayObject.h"

#include "RE/G/GFxMovieDef.h"

#include "Settings.h"

struct QuestItem
{
	QuestItem() = default;

	QuestItem(RE::TESObjectREFR* a_markerRef, RE::QUEST_DATA::Type a_questType, const std::string& a_questName,
			  bool a_isInSameLocation, int a_questAgeIndex)
	: markerRef{ a_markerRef }, type{ a_questType }, name{ a_questName }, isInSameLocation{ a_isInSameLocation },
	  ageIndex{ a_questAgeIndex }
	{}

	RE::TESObjectREFR* markerRef;
	RE::QUEST_DATA::Type type;
	std::string name;
	bool isInSameLocation;
	std::vector<RE::BGSInstancedQuestObjective*> objectives;
	int ageIndex;
};

class QuestItemList : public IUI::GFxDisplayObject
{
public:
	// VR 中直挂 HUDMovieBaseInstance 会在 Infinity UI 遍历成员表时崩溃，因此与 Compass
	// 一样挂到 CompassShoutMeterHolder；补丁资源路径必须与该层级一致。
	static constexpr inline std::string_view path = "_level0.HUDMovieBaseInstance.CompassShoutMeterHolder.QuestItemList";

	static void InitSingleton(const GFxDisplayObject& a_questItemList)
	{
		if (!singleton)
		{
			static QuestItemList singletonInstance{ a_questItemList };
			singleton = &singletonInstance;
		}
	}

	static QuestItemList* GetSingleton() { return singleton; }

	bool CanBeDisplayed(RE::TESObjectCELL* a_cell, bool a_isPlayerWeaponDrawn) const
	{
		if (!a_isPlayerWeaponDrawn || !settings::questlist::hideInCombat)
		{
			if (a_cell)
			{
				if ((a_cell->IsInteriorCell() && settings::questlist::showInInteriors) ||
					(a_cell->IsExteriorCell() && settings::questlist::showInExteriors))
				{
					return true;
				}
			}
		}

		return false;
	}

	void SetHiddenByForce(bool a_hiddenByForce) { hiddenByForce = a_hiddenByForce; }

	bool IsHiddenByForce() const { return hiddenByForce; }

	// positionX/Y 是影片比例坐标；减去舞台原点可转换为父影片剪辑的局部坐标。
	void UpdateLayout()
	{
		RE::GFxValue::DisplayInfo displayInfo;

		GetDisplayInfo(&displayInfo);

		RE::GFxMovieDef* movieDef = GetMovieView()->GetMovieDef();

		displayInfo.SetX(movieDef->GetWidth() * settings::questlist::positionX - originX);
		displayInfo.SetY(movieDef->GetHeight() * settings::questlist::positionY - originY);

		SetDisplayInfo(displayInfo);
	}

	// 将最大高度同步到 ActionScript。
	void SetMaxHeight(float a_maxHeight)
	{
		Invoke("SetMaxHeight", a_maxHeight);
	}

	void AddToHudElements()
	{
		Invoke("AddToHudElements");
	}

	void AddQuest(const QuestItem& a_questItem)
	{
		GFxArray gfxQuestObjectives{ GetMovieView() };

		for (const RE::BGSInstancedQuestObjective* questObjective : a_questItem.objectives)
		{
			gfxQuestObjectives.PushBack(questObjective->GetDisplayTextWithReplacedTags().c_str());
		}

		Invoke("AddQuest", a_questItem.type, a_questItem.name.c_str(), a_questItem.isInSameLocation,
			   gfxQuestObjectives, a_questItem.ageIndex);

	}

	void SetQuestSide(const std::string& a_sideName)
	{
		Invoke("SetQuestSide", a_sideName.c_str());
	}

	void Update()
	{
		Invoke("Update");
	}

	void ShowAllQuests()
	{
		Invoke("ShowAllQuests");
	}

	void RemoveAllQuests()
	{
		Invoke("RemoveAllQuests");
	}

private:

	// 零参数初始化 AS 实例，并保存舞台原点供 UpdateLayout 使用。
	QuestItemList(const GFxDisplayObject& a_questItemList) :
		GFxDisplayObject{ a_questItemList }
	{
		if (HasMember("QuestItemList"))
		{
			Invoke("QuestItemList");

			RE::GPointF origin = LocalToGlobal();

			originX = origin.x;
			originY = origin.y;
		}
	}

	static inline QuestItemList* singleton = nullptr;

	// 成员顺序必须与 DLL 中的布局一致（GFxValue 占 0x00-0x17）：
	//   originX @0x18、originY @0x1c、hiddenByForce @0x20。
	float originX = 0.0F;
	float originY = 0.0F;

	bool hiddenByForce = false;
};
