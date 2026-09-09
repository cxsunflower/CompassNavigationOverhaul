#include "HUDMarkerManager.h"

#include "NND/NPCNameProvider.h"

namespace CNO
{
	void HUDMarkerManager::ProcessQuestMarker(RE::TESQuest* a_quest, RE::BGSInstancedQuestObjective* a_questObjective,
											  int a_questAgeIndex, RE::TESObjectREFR* a_marker, std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_marker);

		if ((IsTheFocusedMarker(a_marker) && angleToPlayerCamera < keepFocusedAngle) ||
			angleToPlayerCamera < facingAngle)
		{
			std::string description;
			RE::QUEST_DATA::Type questType = a_quest->GetType();

			// 根据设置显示目标文本或目标所在位置。
			if (settings::display::showObjectiveAsTarget)
			{
				description = a_questObjective->GetDisplayTextWithReplacedTags().c_str();
			}
			else
			{
				// 任务标记可能指向一个角色，也可能指向一处地点
				switch (a_marker->GetFormType())
				{
				case RE::FormType::Reference:
					if (auto teleportDoor = a_marker->As<RE::TESObjectREFR>())
					{
						// 如果是传送门，取门另一侧的名字
						if (auto teleportLinkedDoor = teleportDoor->extraList.GetTeleportLinkedDoor().get())
						{
							// 先试内景 cell
							if (RE::TESObjectCELL* cell = teleportLinkedDoor->GetParentCell())
							{
								description = cell->GetName();
							}
							// 再试外景 worldspace
							else if (RE::TESWorldSpace* worldSpace = teleportLinkedDoor->GetWorldspace())
							{
								description = worldSpace->GetName();
							}
						}
					}
					break;
				case RE::FormType::ActorCharacter:
					if (auto character = a_marker->As<RE::Character>())
					{
						description = NND::NPCNameProvider::GetSingleton()->GetName(character);
					}
					break;
				}
			}

			// 每个 FormID 仅记录一次最终标题，便于区分 C++ 与 AS/GFx 问题。
			if (settings::debug::logLevel <= logger::level::debug)
			{
				static std::unordered_set<RE::FormID> loggedQuestMarkers;
				if (loggedQuestMarkers.insert(a_marker->GetFormID()).second)
				{
					logger::debug("[QuestMatch] marker 0x{:08X} matched, showObjectiveAsTarget={} dispatched title='{}' (length={})",
								  a_marker->GetFormID(), settings::display::showObjectiveAsTarget,
								  description, description.size());
				}
			}

			facedMarkers.emplace_back(a_marker, angleToPlayerCamera,
									  hudMarkerManager->currentMarkerIndex - 1,
									  a_markerIcon, description);

			bool isInSameLocation = a_markerIcon == RE::HUDMarker::FrameOffsets::GetSingleton()->quest;

			QuestItem* questItem;

			if (questType == RE::QUEST_DATA::Type::kMiscellaneous)
			{
				if (!miscQuestItem.contains(a_marker))
				{
					miscQuestItem[a_marker] = QuestItem{ a_marker, questType, "$MISCELLANEOUS", "", isInSameLocation, a_questAgeIndex };
				}

				questItem = &miscQuestItem[a_marker];
			}
			else
			{
				RE::BSString questFullName = a_quest->GetFullName();
				ReplaceTagsInQuestText(&questFullName, a_quest, a_quest->currentInstanceID);

				std::string questDescription = a_quest->GetCurrentDescriptionWithReplacedTags().c_str();
				questItems[a_marker].try_emplace(a_quest, a_marker, questType, questFullName.c_str(), questDescription, isInSameLocation, a_questAgeIndex);

				questItem = &questItems[a_marker][a_quest];
			}

			if (std::ranges::find(questItem->objectives, a_questObjective) == questItem->objectives.end())
			{
				questItem->objectives.push_back(a_questObjective);
			}
		}
	}
}
