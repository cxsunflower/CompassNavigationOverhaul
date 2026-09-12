#include "QuestItemList.h"

#include "RE/B/BGSInstancedQuestObjective.h"
#include "utils/Logger.h"

void QuestItemList::InitSingleton(const GFxDisplayObject& a_questItemList)
{
		if (!singleton)
		{
			owner.reset(new QuestItemList{ a_questItemList });
			singleton = owner.get();
		}
	}

void QuestItemList::ResetSingleton()
{
	singleton = nullptr;
	owner.reset();
}

bool QuestItemList::CanBeDisplayed(RE::TESObjectCELL* a_cell, bool a_isPlayerWeaponDrawn) const
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

void QuestItemList::UpdateLayout()
{
		Invoke("SetOffsetX", settings::questlist::offsetX);
		Invoke("UpdateAnchor");
	}

void QuestItemList::AnchorBelow(IUI::GFxDisplayObject a_anchorTextField, float a_gap)
{
		// Values from the shared HUD movie must never cross into the private movie.
		if (REL::Module::IsVR()) return;
		Invoke("SetAnchor", a_anchorTextField, a_gap);
		static int diagnosticSamples = 0;
		if (diagnosticSamples < 3)
		{
			const auto state = Invoke("GetAnchorState");
			logger::info("[QuestListAnchor] {}", state.ToString().c_str());
			++diagnosticSamples;
		}
	}

void QuestItemList::SetTextScale(float a_scale)
{
		Invoke("SetTextScale", a_scale);
	}

void QuestItemList::AddToHudElements()
{
		Invoke("AddToHudElements");
	}

void QuestItemList::AddQuest(const QuestItem& a_questItem)
{
		GFxArray gfxQuestObjectives{ GetMovieView() };

		for (const RE::BGSInstancedQuestObjective* questObjective : a_questItem.objectives)
		{
			if (!questObjective)
			{
				continue;
			}
			IUI::GFxObject objective{ GetMovieView() };
			objective.SetMember("text", questObjective->GetDisplayTextWithReplacedTags().c_str());
			const auto state = questObjective->instanceState;
			objective.SetMember("completed", state == RE::QUEST_OBJECTIVE_STATE::kCompleted ||
				state == RE::QUEST_OBJECTIVE_STATE::kCompletedDisplayed);
			objective.SetMember("failed", state == RE::QUEST_OBJECTIVE_STATE::kFailed ||
				state == RE::QUEST_OBJECTIVE_STATE::kFailedDisplayed);
			gfxQuestObjectives.PushBack(objective);
		}

		Invoke("AddQuest", a_questItem.type, a_questItem.name.c_str(), a_questItem.description.c_str(), a_questItem.isInSameLocation,
			   gfxQuestObjectives, a_questItem.ageIndex);

	}

void QuestItemList::SetQuestSide(const std::string& a_sideName)
{
		Invoke("SetQuestSide", a_sideName.c_str());
	}

void QuestItemList::Update()
{
		Invoke("Update");
	}

void QuestItemList::ShowAllQuests()
{
		Invoke("ShowAllQuests");
	}

void QuestItemList::RemoveAllQuests()
{
		hasQuestSnapshot = false;
		lastQuestSignature.clear();
		Invoke("RemoveAllQuests");
	}

QuestItemList::QuestItemList(const GFxDisplayObject& a_questItemList) :
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
