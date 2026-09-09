#include "HUDMarkerManager.h"

namespace CNO
{
	void HUDMarkerManager::SetMarkersExtraInfo()
	{
		// VR 会在 Infinity UI 完成 HUDMenu 补丁前更新 Compass，不能永久缓存尚未创建的 GFx 单例。
		auto compass = Compass::GetSingleton();
		if (!compass)
		{
			if (displayedQuestMarker)
			{
				if (auto questItemList = QuestItemList::GetSingleton())
				{
					questItemList->RemoveAllQuests();
				}
				displayedQuestMarker = nullptr;
			}
			pendingQuestListMarker = nullptr;
			questListFocusTime = 0.0F;
			compassGazeActive = false;
			preFocusedMarker.reset();
			focusedMarker.reset();
			timePreFocusingMarker = 0.0F;
			facedMarkers.clear();
			questItems.clear();
			miscQuestItem.clear();
			return;
		}

		bool focusChanged = UpdateFocusedMarker();

		if (focusChanged)
		{
			compass->UnfocusMarker();
		}

		bool isFocusedQuestMarker = false;

		if (focusedMarker)
		{
			std::string focusedMarkerDescription = focusedMarker->description;
			const bool hasRegularQuests = questItems.contains(focusedMarker->ref);
			const bool hasMiscellaneousQuest = miscQuestItem.contains(focusedMarker->ref);
			isFocusedQuestMarker = hasRegularQuests || hasMiscellaneousQuest;

			// 仅在显示任务目标文本时附加其他目标数量。
			if (settings::display::showObjectiveAsTarget && settings::display::showOtherObjectivesCount)
			{
				int objectivesCount = 0;

				if (hasRegularQuests)
				{
					std::unordered_map<RE::TESQuest*, QuestItem>& questItemMap = questItems[focusedMarker->ref];

					for (auto& [quest, questItem] : questItemMap)
					{
						objectivesCount += questItem.objectives.size();
					}
				}

				if (hasMiscellaneousQuest)
				{
					QuestItem& questItem = miscQuestItem[focusedMarker->ref];

					objectivesCount += questItem.objectives.size();
				}

				if (objectivesCount > 1)
				{
					focusedMarkerDescription += " (+" + std::to_string(objectivesCount - 1) + ")";
				}
			}

			compass->SetFocusedMarkerInfo(focusedMarkerDescription, focusedMarker->distanceToPlayer,
										  focusedMarker->heightDifference, focusedMarker->index);

			if (focusChanged)
			{
				compass->FocusMarker();
			}

			compass->UpdateFocusedMarker();
		}

		// QuestItemList 可能比 Compass 更晚创建；缺失时只跳过任务列表，不影响名称与距离。
		if (auto questItemList = QuestItemList::GetSingleton())
		{
			RE::ActorState* playerState = player->AsActorState();
			bool canQuestItemListBeDisplayed = questItemList->CanBeDisplayed(player->GetParentCell(), playerState->IsWeaponDrawn());
			// Snapshot the current marker's quests before the per-frame maps are cleared.
			auto CollectCurrentQuests = [&](RE::TESObjectREFR* a_marker) {
				std::vector<QuestItem> result;
				if (questItems.contains(a_marker))
				{
					for (const auto& [quest, item] : questItems[a_marker])
					{
						QuestItem copy = item;
						copy.side = GetSideInQuest(copy.type);
						result.push_back(std::move(copy));
					}
				}
				if (miscQuestItem.contains(a_marker))
				{
					result.push_back(miscQuestItem[a_marker]);
				}
				return result;
			};

			// 聚焦任务标记稳定 0.3 秒后显示；失焦或切换标记时立即清空旧列表。
			// 注视门控：任务聚焦 + 罗盘可见 + 3D 视线看向罗盘，三者同时成立才计时 0.3 秒；
			// 任一丢失走 !targetQuestMarker 分支，立即清空旧列表。
			RE::TESObjectREFR* targetQuestMarker = canQuestItemListBeDisplayed && isFocusedQuestMarker &&
					IsLookingAtCompass(compass) ?
				focusedMarker->ref :
				nullptr;

			if (!targetQuestMarker)
			{
				if (displayedQuestMarker)
				{
					questItemList->RemoveAllQuests();
					displayedQuestMarker = nullptr;
				}
				pendingQuestListMarker = nullptr;
				questListFocusTime = 0.0F;
			}
			else if (displayedQuestMarker == targetQuestMarker)
			{
				pendingQuestListMarker = nullptr;
				questListFocusTime = 0.0F;
				questItemList->SyncQuests(CollectCurrentQuests(targetQuestMarker));
				questItemList->ShowAllQuests();
				questItemList->Update();
			}
			else
			{
				if (displayedQuestMarker)
				{
					questItemList->RemoveAllQuests();
					displayedQuestMarker = nullptr;
				}

				if (pendingQuestListMarker != targetQuestMarker)
				{
					pendingQuestListMarker = targetQuestMarker;
					questListFocusTime = 0.0F;
				}
				else
				{
					questListFocusTime += timeManager->realTimeDelta;
					if (questListFocusTime >= 0.3F)
					{
						questItemList->SyncQuests(CollectCurrentQuests(targetQuestMarker));
						questItemList->GetMovieView()->Advance(0.0F);

						questItemList->SetHiddenByForce(false);
						questItemList->ShowAllQuests();
						questItemList->Update();
						displayedQuestMarker = targetQuestMarker;
						pendingQuestListMarker = nullptr;
						questListFocusTime = 0.0F;
					}
				}
			}

			if (targetQuestMarker && displayedQuestMarker == targetQuestMarker)
			{
				questItemList->AnchorBelow(compass->GetFocusedMarkerTargetTextField());
			}
		}

		facedMarkers.clear();
		questItems.clear();
		miscQuestItem.clear();
	}
}
