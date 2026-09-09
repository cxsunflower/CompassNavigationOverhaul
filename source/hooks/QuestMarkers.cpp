#include "Internal.h"

#include "Settings.h"

#include "HUDMarkerManager.h"

namespace hooks
{
	bool UpdateQuests(const RE::HUDMarkerManager* a_hudMarkerManager, RE::HUDMarker::ScaleformData* a_markerData,
					  RE::NiPoint3* a_pos, const RE::RefHandle& a_refHandle, std::uint32_t a_markerGotoFrame,
					  std::uint32_t* a_markerSources, std::uint32_t a_markerSource,
					  const void* a_runtimeQuestTarget)
	{
		// 同一标记可由多个任务目标反复补充信息。
		if (HUDMarkerManager::AddMarker(a_hudMarkerManager, a_markerData, a_pos, a_refHandle, a_markerGotoFrame,
										a_markerSources, a_markerSource))
		{
			RE::TESObjectREFR* marker = RE::TESObjectREFR::LookupByHandle(a_refHandle).get();
			if (!marker)
			{
				return true;
			}

			auto player = RE::PlayerCharacter::GetSingleton();

			RE::BSTArray<RE::BGSInstancedQuestObjective>& playerObjectives = REL::Module::IsVR() ?
																				player->GetVRPlayerRuntimeData()->objectives :
																				player->GetPlayerRuntimeData().objectives;

			// 诊断目标匹配失败与目标文本为空，仅对每个 FormID 记录一次。
			const bool diag = settings::debug::logLevel <= logger::level::debug;
			bool diagThisMarker = false;
			if (diag)
			{
				static std::unordered_set<RE::FormID> loggedMarkers;
				diagThisMarker = loggedMarkers.insert(marker->GetFormID()).second;
				if (diagThisMarker)
				{
					logger::debug("[QuestMatch] marker 0x{:08X} type={} refHandle=0x{:08X} runtimeTarget=0x{:X} objectives={}",
								  marker->GetFormID(), static_cast<int>(marker->GetFormType()),
								  static_cast<std::uint32_t>(a_refHandle),
								  reinterpret_cast<std::uintptr_t>(a_runtimeQuestTarget),
								  static_cast<std::uint32_t>(playerObjectives.size()));

					// 当 CommonLibVR 的 objectives@0xB70 为空时，按 BSTArray 布局扫描候选偏移。
					// 候选元素必须指向 ownerQuest，且所有解引用前均用 VirtualQuery 验证可读性。
					const std::uintptr_t playerBase = reinterpret_cast<std::uintptr_t>(player);

					auto readable = [](std::uintptr_t p, std::size_t n) -> bool {
						if (p < 0x10000 || n == 0) return false;
						MEMORY_BASIC_INFORMATION mbi{};
						if (VirtualQuery(reinterpret_cast<void*>(p), &mbi, sizeof(mbi)) == 0) return false;
						if (mbi.State != MEM_COMMIT) return false;
						constexpr DWORD readMask = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY |
												   PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;
						if ((mbi.Protect & readMask) == 0) return false;
						if (mbi.Protect & PAGE_GUARD) return false;
						const std::uintptr_t regionBase = reinterpret_cast<std::uintptr_t>(mbi.BaseAddress);
						return (p + n) <= (regionBase + mbi.RegionSize);
					};

					constexpr auto questFormType = static_cast<std::uint8_t>(RE::FormType::Quest);
					int scanHits = 0;
					// 0x400..0xE00 足以覆盖 SE 的 0x580 与 VR 的 0xB70，两端都留了余量。
					for (std::ptrdiff_t off = 0x400; off <= 0xE00; off += 0x8)
					{
						if (!readable(playerBase + off, 0x18)) continue;
						const std::uintptr_t dataPtr = *reinterpret_cast<std::uintptr_t*>(playerBase + off);
						const std::uint32_t  cap = *reinterpret_cast<std::uint32_t*>(playerBase + off + 0x8);
						const std::uint32_t  sz = *reinterpret_cast<std::uint32_t*>(playerBase + off + 0x10);
						if (sz < 1 || sz > 64 || cap < sz) continue;
						if (!readable(dataPtr, static_cast<std::size_t>(sz) * 0x10)) continue;

						// 逐元素校验：首字段是 BGSQuestObjective*，其 +0x8 的 ownerQuest 是 FormType==kQuest 的表单。
						int validObjectives = 0;
						for (std::uint32_t e = 0; e < sz; e++)
						{
							const std::uintptr_t objPtr = *reinterpret_cast<std::uintptr_t*>(dataPtr + static_cast<std::size_t>(e) * 0x10);
							if (!readable(objPtr, 0x20)) continue;
							const std::uintptr_t ownerQuest = *reinterpret_cast<std::uintptr_t*>(objPtr + 0x8);
							if (!readable(ownerQuest, 0x20)) continue;
							if (*reinterpret_cast<std::uint8_t*>(ownerQuest + 0x1A) == questFormType)
							{
								validObjectives++;
							}
						}
						if (validObjectives > 0)
						{
							logger::debug("[QuestScan] absoluteOffset=0x{:X} size={} cap={} data=0x{:X} elementsValidatedAsQuestObjectives={} (0xB70=CommonLib-assumed value)",
										  static_cast<std::uint64_t>(off), sz, cap, dataPtr, validObjectives);
							scanHits++;
						}
					}
					logger::debug("[QuestScan] player=0x{:X} scan hits (suspected objectives array)={}", playerBase, scanHits);
				}
			}

			// 目标按从旧到新存储，逆序遍历以匹配日志顺序。
			for (int ageIndex = playerObjectives.size() - 1; ageIndex >= 0; ageIndex--)
			{
				RE::BGSInstancedQuestObjective* playerObjective = &playerObjectives[ageIndex];
				RE::BGSQuestObjective* questObjective = playerObjective->objective;
				if (!questObjective || !questObjective->ownerQuest)
				{
					continue;
				}

				for (int j = 0; j < questObjective->numTargets; j++)
				{
					auto questObjectiveTarget = questObjective->targets[j];
					if (!questObjectiveTarget)
					{
						continue;
					}

					bool directMatch = a_runtimeQuestTarget == questObjectiveTarget;

					bool aliasMatch = false;
					RE::TESObjectREFR* aliasRef = nullptr;
					RE::RefHandle aliasHandle = 0;

					if (!directMatch)
					{
						// VR 运行时包装对象可能与 QSTA 地址不同，用别名解析出的引用兜底匹配。
						// 句柄编码在 VR 上也可能与罗盘拿到的 a_refHandle 不一致，所以同时比较
						// 「解析出的句柄」和「解析出的引用指针」，两者任一命中即算匹配。
						RE::ObjectRefHandle objectiveHandle;
						questObjective->ownerQuest->CreateRefHandleByAliasID(objectiveHandle, questObjectiveTarget->alias);
						aliasHandle = objectiveHandle.native_handle();
						aliasRef = objectiveHandle.get().get();
						aliasMatch = (aliasHandle == a_refHandle) || (aliasRef && aliasRef == marker);
					}

					const bool targetMatches = directMatch || aliasMatch;

					if (diagThisMarker)
					{
						logger::debug("[QuestMatch]   quest'{}'(0x{:08X}) target[{}]=0x{:X} alias={} aliasHandle=0x{:08X} aliasRef=0x{:08X} directMatch={} aliasMatch={}",
									  questObjective->ownerQuest->GetFullName(), questObjective->ownerQuest->GetFormID(),
									  j, reinterpret_cast<std::uintptr_t>(questObjectiveTarget),
									  static_cast<int>(questObjectiveTarget->alias), aliasHandle,
									  aliasRef ? aliasRef->GetFormID() : 0u, directMatch, aliasMatch);
					}

					if (targetMatches)
					{
						RE::TESQuest* quest = questObjective->ownerQuest;
						CNO::HUDMarkerManager::GetSingleton()->ProcessQuestMarker(quest, playerObjective, ageIndex,
																				  marker, a_markerGotoFrame);
						return true;
					}
				}
			}

			if (diagThisMarker)
			{
				logger::debug("[QuestMatch] marker 0x{:08X} could not be linked to any quest objective -> falling back to distance-only (no title)", marker->GetFormID());
			}

			// 无法关联具体目标时仍加入聚焦列表，至少保留任务标记的距离显示。
			CNO::HUDMarkerManager::GetSingleton()->ProcessPlayerSetMarker(marker, a_markerGotoFrame);
			return true;
		}

		return false;
	}

}
