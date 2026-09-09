#include "questlist/QuestData.h"

#include "RE/B/BGSInstancedQuestObjective.h"
#include "RE/T/TESQuest.h"

namespace CNO
{
	namespace
	{
		bool IsVisibleObjectiveState(RE::QUEST_OBJECTIVE_STATE a_state)
		{
			return a_state == RE::QUEST_OBJECTIVE_STATE::kDisplayed ||
				a_state == RE::QUEST_OBJECTIVE_STATE::kCompleted ||
				a_state == RE::QUEST_OBJECTIVE_STATE::kCompletedDisplayed ||
				a_state == RE::QUEST_OBJECTIVE_STATE::kFailed ||
				a_state == RE::QUEST_OBJECTIVE_STATE::kFailedDisplayed;
		}

		bool IsCompletedObjectiveState(RE::QUEST_OBJECTIVE_STATE a_state)
		{
			return a_state == RE::QUEST_OBJECTIVE_STATE::kCompleted ||
				a_state == RE::QUEST_OBJECTIVE_STATE::kCompletedDisplayed;
		}
	}

	std::vector<QuestObjectiveInfo> CollectQuestObjectives(
		const QuestItem& a_questItem, const RE::BSTArray<RE::BGSInstancedQuestObjective>& a_playerObjectives)
	{
		// Normal quests have one owner/instance. Miscellaneous objectives may be
		// grouped under one marker, so retain all relevant owner/instance pairs.
		std::vector<std::pair<RE::TESQuest*, std::uint32_t>> owners;
		for (const auto* selected : a_questItem.objectives)
		{
			if (!selected || !selected->objective || !selected->objective->ownerQuest)
			{
				continue;
			}
			const auto owner = std::make_pair(selected->objective->ownerQuest, selected->instanceID);
			if (std::ranges::find(owners, owner) == owners.end())
			{
				owners.push_back(owner);
			}
		}

		struct OrderedObjective
		{
			QuestObjectiveInfo info;
			std::size_t ownerOrder;
			std::uint16_t objectiveIndex;
		};
		std::vector<OrderedObjective> ordered;
		std::vector<std::pair<const RE::BGSQuestObjective*, std::uint32_t>> seen;
		for (const auto& candidate : a_playerObjectives)
		{
			if (!candidate.objective || !candidate.objective->ownerQuest ||
				!IsVisibleObjectiveState(candidate.instanceState))
			{
				continue;
			}
			const auto owner = std::make_pair(candidate.objective->ownerQuest, candidate.instanceID);
			const auto ownerIt = std::ranges::find(owners, owner);
			if (ownerIt == owners.end())
			{
				continue;
			}
			const auto identity = std::make_pair(static_cast<const RE::BGSQuestObjective*>(candidate.objective), candidate.instanceID);
			if (std::ranges::find(seen, identity) != seen.end())
			{
				continue;
			}
			seen.push_back(identity);
			QuestObjectiveInfo info;
			info.text = candidate.GetDisplayTextWithReplacedTags().c_str();
			if (info.text.empty())
			{
				continue;
			}
			info.completed = IsCompletedObjectiveState(candidate.instanceState);
			info.failed = candidate.instanceState == RE::QUEST_OBJECTIVE_STATE::kFailed ||
				candidate.instanceState == RE::QUEST_OBJECTIVE_STATE::kFailedDisplayed;
			ordered.push_back({ std::move(info), static_cast<std::size_t>(ownerIt - owners.begin()), candidate.objective->index });
		}

		std::stable_sort(ordered.begin(), ordered.end(), [](const auto& a, const auto& b) {
			return std::tie(a.ownerOrder, a.objectiveIndex) < std::tie(b.ownerOrder, b.objectiveIndex);
		});
		std::vector<QuestObjectiveInfo> result;
		result.reserve(ordered.size());
		for (auto& entry : ordered)
		{
			result.push_back(std::move(entry.info));
		}
		return result;
	}
}
