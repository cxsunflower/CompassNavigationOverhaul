#pragma once

#include <string>
#include <vector>

#include "RE/B/BGSInstancedQuestObjective.h"
#include "RE/T/TESQuest.h"

struct QuestObjectiveInfo
{
	std::string text;
	bool completed = false;
	bool failed = false;
};

struct QuestItem;

namespace CNO
{
	std::vector<QuestObjectiveInfo> CollectQuestObjectives(
		const QuestItem& a_questItem, const RE::BSTArray<RE::BGSInstancedQuestObjective>& a_playerObjectives);
}

struct QuestItem
{
	QuestItem() = default;

	QuestItem(RE::TESObjectREFR* a_markerRef, RE::QUEST_DATA::Type a_questType, const std::string& a_questName,
			  const std::string& a_description, bool a_isInSameLocation, int a_questAgeIndex)
	: markerRef{ a_markerRef }, type{ a_questType }, name{ a_questName }, isInSameLocation{ a_isInSameLocation },
	  description{ a_description }, ageIndex{ a_questAgeIndex }
	{}

	RE::TESObjectREFR* markerRef;
	RE::QUEST_DATA::Type type;
	std::string name;
	std::string description;
	bool isInSameLocation;
	std::vector<RE::BGSInstancedQuestObjective*> objectives;
	int ageIndex;
	std::string side;
};

