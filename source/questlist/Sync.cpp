#include "QuestItemList.h"

#include "RE/B/BGSInstancedQuestObjective.h"

namespace
{
	void AppendSignature(std::string& a_signature, std::string_view a_value)
	{
		a_signature.append(std::to_string(a_value.size())).push_back(':');
		a_signature.append(a_value);
	}

	std::string MakeQuestKey(const QuestItem& a_item)
	{
		const std::string marker = a_item.markerRef ? std::to_string(a_item.markerRef->GetFormID()) : "0";
		if (a_item.type == RE::QUEST_DATA::Type::kMiscellaneous)
		{
			return "misc:" + marker;
		}
		if (!a_item.objectives.empty() && a_item.objectives.front() && a_item.objectives.front()->objective &&
			a_item.objectives.front()->objective->ownerQuest)
		{
			const auto* objective = a_item.objectives.front();
			return "quest:" + marker + ":" + std::to_string(objective->objective->ownerQuest->GetFormID()) +
				":" + std::to_string(objective->instanceID);
		}
		return "quest:" + marker + ":" + a_item.name;
	}
}

void QuestItemList::SyncQuests(const std::vector<QuestItem>& a_quests)
{
	auto* player = RE::PlayerCharacter::GetSingleton();
	if (!player)
	{
		return;
	}
	const auto& playerObjectives = REL::Module::IsVR() ?
		player->GetVRPlayerRuntimeData()->objectives : player->GetPlayerRuntimeData().objectives;

	struct Snapshot
	{
		const QuestItem* quest;
		std::string key;
		std::vector<QuestObjectiveInfo> objectives;
		std::string signature;
	};
	std::vector<Snapshot> snapshots;
	std::string signature;
	for (const auto& quest : a_quests)
	{
		Snapshot snapshot{ &quest, MakeQuestKey(quest), CNO::CollectQuestObjectives(quest, playerObjectives) };
		AppendSignature(snapshot.signature, snapshot.key);
		AppendSignature(snapshot.signature, quest.name);
		AppendSignature(snapshot.signature, quest.description);
		AppendSignature(snapshot.signature, quest.side);
		AppendSignature(snapshot.signature, std::to_string(static_cast<std::uint32_t>(quest.type)));
		AppendSignature(snapshot.signature, std::to_string(quest.ageIndex));
		for (const auto& objective : snapshot.objectives)
		{
			AppendSignature(snapshot.signature, objective.text);
			snapshot.signature.push_back(objective.completed ? 'C' : objective.failed ? 'F' : 'A');
		}
		AppendSignature(signature, snapshot.signature);
		snapshots.push_back(std::move(snapshot));
	}
	if (hasQuestSnapshot && signature == lastQuestSignature)
	{
		return;
	}

	GFxArray gfxQuests{ GetMovieView() };
	for (const auto& snapshot : snapshots)
	{
		const QuestItem& quest = *snapshot.quest;
		GFxArray gfxObjectives{ GetMovieView() };
		for (const auto& objective : snapshot.objectives)
		{
			IUI::GFxObject gfxObjective{ GetMovieView() };
			gfxObjective.SetMember("text", objective.text.c_str());
			gfxObjective.SetMember("completed", objective.completed);
			gfxObjective.SetMember("failed", objective.failed);
			gfxObjectives.PushBack(gfxObjective);
		}
		IUI::GFxObject gfxQuest{ GetMovieView() };
		gfxQuest.SetMember("key", snapshot.key.c_str());
		gfxQuest.SetMember("type", static_cast<std::uint32_t>(quest.type));
		gfxQuest.SetMember("title", quest.name.c_str());
		gfxQuest.SetMember("description", quest.description.c_str());
		gfxQuest.SetMember("isInSameLocation", quest.isInSameLocation);
		gfxQuest.SetMember("objectives", gfxObjectives);
		gfxQuest.SetMember("ageIndex", quest.ageIndex);
		gfxQuest.SetMember("side", quest.side.c_str());
		gfxQuest.SetMember("signature", snapshot.signature.c_str());
		gfxQuests.PushBack(gfxQuest);
	}
	Invoke("SyncQuests", gfxQuests);
	hasQuestSnapshot = true;
	lastQuestSignature = std::move(signature);
}
