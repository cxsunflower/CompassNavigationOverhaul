#include "HUDMarkerManager.h"

#include "RE/B/BSTimer.h"

namespace CNO
{
	bool HUDMarkerManager::IsCompassVisible(const Compass* a_compass)
	{
		if (a_compass)
		{
			// VRIK / 菜单可能在 Scaleform 侧隐藏罗盘。
			const RE::GFxValue gfxVisible = a_compass->GetMember("_visible");
			if (gfxVisible.IsBool() && gfxVisible.GetBool())
			{
				return true;
			}

			// Scaleform _alpha 是 0-100 的百分比。
			const RE::GFxValue gfxAlpha = a_compass->GetMember("_alpha");
			if (gfxAlpha.IsNumber() && gfxAlpha.GetNumber() > 1.0)
			{
				return true;
			}
		}

		// Palm Compass VR 只搬 3D 节点：节点可见即罗盘显示中。
		if (const RE::NiAVObject* node = FindCompassNode())
		{
			if (IsNodeVisible(node))
			{
				return true;
			}
		}

		return false;
	}

	bool HUDMarkerManager::IsNodeVisible(const RE::NiAVObject* a_node) const
	{
		for (const RE::NiAVObject* node = a_node; node != nullptr; node = node->parent)
		{
			if (node->flags.all(RE::NiAVObject::Flag::kHidden))
			{
				return false;
			}
			if (node->GetAppCulled())
			{
				return false;
			}
		}

		return true;
	}

	bool HUDMarkerManager::IsNodeFromCurrentRoots(const RE::NiAVObject* a_node) const
	{
		if (!a_node)
		{
			return false;
		}

		// 沿 parent 走到场景根，比对当前三根（读档/3D 重建后旧缓存必然失配）。
		const RE::NiAVObject* root = a_node;
		for (int depth = 0; depth < 64 && root->parent != nullptr; ++depth)
		{
			root = root->parent;
		}
		if (root->parent != nullptr)
		{
			return false;  // 链过深：视为失效，触发重找
		}

		if (playerCamera && playerCamera->cameraRoot.get() == root)
		{
			return true;
		}

		if (player && (player->Get3D1(false) == root || player->Get3D1(true) == root))
		{
			return true;
		}

		return false;
	}

	RE::NiAVObject* HUDMarkerManager::FindCompassNode()
	{
		if (compassNode.get())
		{
			if (IsNodeFromCurrentRoots(compassNode.get()))
			{
				return compassNode.get();
			}
			compassNode.reset();  // 3D 已重建（读档/切场景）：立即重找
		}
		else
		{
			// 从未找到：1 秒重试一次，避免每帧遍历场景。
			nodeRetryTime += timeManager->realTimeDelta;
			if (nodeRetryTime < 1.0F)
			{
				return nullptr;
			}
			nodeRetryTime = 0.0F;
		}

		auto tryRoot = [this](RE::NiAVObject* a_root, const char* a_rootName) -> RE::NiAVObject* {
			if (!a_root)
			{
				return nullptr;
			}

			static const RE::BSFixedString nodeName{ "skyVR_HUD01" };
			if (RE::NiAVObject* found = a_root->GetObjectByName(nodeName))
			{
				compassNode.reset(found);
				logger::info("[QuestListGaze] compass node 'skyVR_HUD01' found under {}", a_rootName);
				return compassNode.get();
			}

			return nullptr;
		};

		if (playerCamera)
		{
			if (RE::NiAVObject* found = tryRoot(playerCamera->cameraRoot.get(), "cameraRoot"))
			{
				return found;
			}
		}

		if (player)
		{
			if (RE::NiAVObject* found = tryRoot(player->Get3D1(false), "player-3rd"))
			{
				return found;
			}
			if (RE::NiAVObject* found = tryRoot(player->Get3D1(true), "player-1st"))
			{
				return found;
			}
		}

		logger::debug("[QuestListGaze] compass node 'skyVR_HUD01' not found under camera/player roots");
		return nullptr;
	}

	RE::NiAVObject* HUDMarkerManager::FindHandNode()
	{
		if (handNode.get())
		{
			if (IsNodeFromCurrentRoots(handNode.get()))
			{
				return handNode.get();
			}
			handNode.reset();
		}
		else
		{
			nodeRetryTime += timeManager->realTimeDelta;
			if (nodeRetryTime < 1.0F)
			{
				return nullptr;
			}
			nodeRetryTime = 0.0F;
		}

		if (!player)
		{
			return nullptr;
		}

		// 右手节点候选名：原版/XPMSE 骨骼 + VRIK/HIGGS 常见变体，命中即记日志。
		static constexpr const char* candidateNames[] = {
			"NPC R Hand [RHand]",
			"NPC RHand [RHand]",
			"NPC RightHand [RHand]",
			"RHand",
			"RightHand",
			"VRIK_RightHand",
		};
		static constexpr std::size_t candidateCount = sizeof(candidateNames) / sizeof(candidateNames[0]);

		RE::NiAVObject* const roots[] = { player->Get3D1(false), player->Get3D1(true) };
		for (std::size_t i = 0; i < candidateCount; ++i)
		{
			const RE::BSFixedString name{ candidateNames[i] };
			for (RE::NiAVObject* root : roots)
			{
				if (root)
				{
					if (RE::NiAVObject* found = root->GetObjectByName(name))
					{
						handNode.reset(found);
						logger::info("[QuestListGaze] right-hand node '{}' found", candidateNames[i]);
						return handNode.get();
					}
				}
			}
		}

		logger::debug("[QuestListGaze] right-hand node not found (tried {} names)", candidateCount);
		return nullptr;
	}
}
