#include "HUDMarkerManager.h"

#include "RE/B/BSTimer.h"

#include "RE/I/IMenu.h"

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
					miscQuestItem[a_marker] = QuestItem{ a_marker, questType, "$MISCELLANEOUS", isInSameLocation, a_questAgeIndex };
				}

				questItem = &miscQuestItem[a_marker];
			}
			else
			{
				RE::BSString questFullName = a_quest->GetFullName();
				ReplaceTagsInQuestText(&questFullName, a_quest, a_quest->currentInstanceID);

				questItems[a_marker][a_quest] = QuestItem{ a_marker, questType, questFullName.c_str(), isInSameLocation, a_questAgeIndex };

				questItem = &questItems[a_marker][a_quest];
			}

			if (std::ranges::find(questItem->objectives, a_questObjective) == questItem->objectives.end())
			{
				questItem->objectives.push_back(a_questObjective);
			}
		}
	}

	void HUDMarkerManager::ProcessLocationMarker(RE::ExtraMapMarker* a_mapMarker, RE::TESObjectREFR* a_marker,
												 std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_marker);

		bool isDiscoveredLocation = a_mapMarker->mapData->flags.all(RE::MapMarkerData::Flag::kVisible);

		// 已发现地点始终显示详情；未发现地点由正向开关控制。
		if (isDiscoveredLocation || settings::display::showUndiscoveredLocationInfo)
		{
			if ((IsTheFocusedMarker(a_marker) && angleToPlayerCamera < keepFocusedAngle) ||
				angleToPlayerCamera < facingAngle)
			{
				std::string_view locationFullName = a_mapMarker->mapData->locationName.GetFullName();

				facedMarkers.emplace_back(a_marker, angleToPlayerCamera,
										  hudMarkerManager->currentMarkerIndex - 1,
										  a_markerIcon, locationFullName);
			}

			if (isDiscoveredLocation)
			{
				return;
			}
		}

		// kHidden 已在 Hook 入口过滤；kUnknown 使用 AS 的 0 号“?”图标帧。
		if (settings::display::undiscoveredLocationMarkers == settings::UndiscoveredLocationMarkers::kUnknown)
		{
			hudMarkerManager->scaleformMarkerData[hudMarkerManager->currentMarkerIndex - 1].icon.SetNumber(0);
		}
	}

	void HUDMarkerManager::ProcessEnemyMarker(RE::Character* a_enemy, std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_enemy);

		if ((IsTheFocusedMarker(a_enemy) && angleToPlayerCamera < keepFocusedAngle) ||
			angleToPlayerCamera < facingAngle)
		{
			// 关闭名称时跳过 NND 查询。
			const char* enemyName = settings::display::showEnemyNameUnderMarker ?
										NND::NPCNameProvider::GetSingleton()->GetName(a_enemy) :
										"";

			facedMarkers.emplace_back(a_enemy, angleToPlayerCamera,
									hudMarkerManager->currentMarkerIndex - 1,
									a_markerIcon, enemyName);
		}
	}

	void HUDMarkerManager::ProcessPlayerSetMarker(RE::TESObjectREFR* a_marker, std::uint32_t a_markerIcon)
	{
		float angleToPlayerCamera = GetAngleBetween(playerCamera, a_marker);

		if ((IsTheFocusedMarker(a_marker) && angleToPlayerCamera < keepFocusedAngle) ||
			angleToPlayerCamera < facingAngle)
		{
			facedMarkers.emplace_back(a_marker, angleToPlayerCamera,
										hudMarkerManager->currentMarkerIndex - 1,
										a_markerIcon, "");
		}
	}

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

			// 聚焦任务标记稳定 0.3 秒后显示；失焦或切换标记时立即清空旧列表。
			RE::TESObjectREFR* targetQuestMarker =
				canQuestItemListBeDisplayed && isFocusedQuestMarker ? focusedMarker->ref : nullptr;

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
						if (questItems.contains(targetQuestMarker))
						{
							for (auto& [quest, questItem] : questItems[targetQuestMarker])
							{
								questItemList->AddQuest(questItem);
								questItemList->SetQuestSide(GetSideInQuest(questItem.type));
								questItemList->GetMovieView()->Advance(0.0F);
							}
						}

						if (miscQuestItem.contains(targetQuestMarker))
						{
							questItemList->AddQuest(miscQuestItem[targetQuestMarker]);
							questItemList->GetMovieView()->Advance(0.0F);
						}

						questItemList->SetHiddenByForce(false);
						questItemList->ShowAllQuests();
						questItemList->Update();
						displayedQuestMarker = targetQuestMarker;
						pendingQuestListMarker = nullptr;
						questListFocusTime = 0.0F;
					}
				}
			}
		}

		facedMarkers.clear();
		questItems.clear();
		miscQuestItem.clear();
	}

	std::unique_ptr<Compass::Marker> HUDMarkerManager::GetMostCenteredMarker() const
	{
		std::unique_ptr<Compass::Marker> mostCenteredMarker = nullptr;

		float closestAngleToPlayerCamera = std::numeric_limits<float>::max();

		int mostCenteredMarkerIndex = -1;

		for (int i = 0; i < facedMarkers.size(); i++)
		{
			const Compass::Marker& facedMarker = facedMarkers[i];

			if (facedMarker.angleToPlayerCamera < closestAngleToPlayerCamera)
			{
				mostCenteredMarkerIndex = i;
				closestAngleToPlayerCamera = facedMarker.angleToPlayerCamera;
			}
		}

		if (mostCenteredMarkerIndex >= 0)
		{
			mostCenteredMarker = std::make_unique<Compass::Marker>(facedMarkers[mostCenteredMarkerIndex]);
		}

		return mostCenteredMarker;
	}

	bool HUDMarkerManager::UpdateFocusedMarker()
	{
		std::unique_ptr<Compass::Marker> mostCenteredMarker = GetMostCenteredMarker();

		static auto IsMarkerDifferent = [](const std::unique_ptr<Compass::Marker>& a_lhs, const std::unique_ptr<Compass::Marker>& a_rhs) -> bool
		{
			if (a_lhs && a_rhs)
			{
				return a_lhs->ref != a_rhs->ref;
			}
			else if (!a_lhs && !a_rhs)
			{
				return false;
			}

			return true;
		};

		if (IsMarkerDifferent(mostCenteredMarker, preFocusedMarker))
		{
			timePreFocusingMarker = 0.0F;
		}

		if (preFocusedMarker || mostCenteredMarker)
		{
			preFocusedMarker = std::move(mostCenteredMarker);
		}

		if (IsMarkerDifferent(preFocusedMarker, focusedMarker))
		{
			if (preFocusedMarker)
			{
				if (timePreFocusingMarker > settings::display::focusingDelayToShow)
				{	
					focusedMarker = std::move(preFocusedMarker);
					return true;
				}
				else
				{
					timePreFocusingMarker += timeManager->realTimeDelta;
				}
			}
			else
			{
				focusedMarker = nullptr;
				return true;
			}
		}
		else if (preFocusedMarker && focusedMarker)
		{
			focusedMarker = std::move(preFocusedMarker);
		}

		return false;
	}

	float HUDMarkerManager::GetAngleBetween(const RE::PlayerCamera* a_playerCamera,
											const RE::TESObjectREFR* a_marker) const
	{
		float angleToPlayerCameraInRadians = util::GetAngleBetween(a_playerCamera, a_marker);
		float angleToPlayerCamera = util::RadiansToDegrees(angleToPlayerCameraInRadians);

		if (angleToPlayerCamera > 180.0F)
			angleToPlayerCamera = 360.0F - angleToPlayerCamera;

		return angleToPlayerCamera;
	}

	bool HUDMarkerManager::IsPlayerAllyOfFaction(const RE::TESFaction* a_faction) const
	{
		if (!a_faction)
		{
			return false;
		}

		if (player->IsInFaction(a_faction)) 
		{
			return true;
		}

		return player->VisitFactions([a_faction](RE::TESFaction* a_visitedFaction, std::int8_t a_rank) -> bool
		{
			if (!a_visitedFaction)
			{
				return false;
			}

			if (a_visitedFaction == a_faction && a_rank > 0)
			{
				return true;
			}

			for (RE::GROUP_REACTION* reactionToFaction : a_visitedFaction->reactions)
			{
				if (!reactionToFaction || !reactionToFaction->form)
				{
					continue;
				}

				auto relatedFaction = reactionToFaction->form->As<RE::TESFaction>();
				if (relatedFaction == a_faction && reactionToFaction->fightReaction >= RE::FIGHT_REACTION::kAlly)
				{
					return true;
				}
			}

			return false;
		});
	}

	bool HUDMarkerManager::IsPlayerOpponentOfFaction(const RE::TESFaction* a_faction) const
	{
		if (!a_faction)
		{
			return false;
		}

		return player->VisitFactions([a_faction](RE::TESFaction* a_visitedFaction, std::int8_t a_rank) -> bool
		{
			if (!a_visitedFaction)
			{
				return false;
			}

			if (a_visitedFaction == a_faction && a_rank < 0)
			{
				return true;
			}

			for (RE::GROUP_REACTION* reactionToFaction : a_visitedFaction->reactions)
			{
				if (!reactionToFaction || !reactionToFaction->form)
				{
					continue;
				}

				auto relatedFaction = reactionToFaction->form->As<RE::TESFaction>();
				if (relatedFaction == a_faction && reactionToFaction->fightReaction == RE::FIGHT_REACTION::kEnemy)
				{
					return true;
				}
			}

			return false;
		});
	}

	std::string HUDMarkerManager::GetSideInQuest(RE::QUEST_DATA::Type a_questType) const
	{
		switch (a_questType)
		{
		case RE::QUEST_DATA::Type::kCivilWar:
			if (IsPlayerAllyOfFaction(sonsOfSkyrimFaction) || IsPlayerAllyOfFaction(stormCloaksFaction) ||
				IsPlayerOpponentOfFaction(imperialLegionFaction))
			{
				return "StormCloaks";
			}
			else
			{
				return "ImperialLegion";
			}
		case RE::QUEST_DATA::Type::kDLC01_Vampire:
			if (player->HasKeywordString("Vampire") || IsPlayerAllyOfFaction(vampireFaction) ||
				IsPlayerOpponentOfFaction(dawnGuardFaction))
			{
				return "Vampires";
			}
			else
			{
				return "Dawnguard"; 
			}
		}

		return { };
	}
}
