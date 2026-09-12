#include "HUDMarkerManager.h"

#include "RE/B/BSTimer.h"
#include <array>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <unordered_set>

namespace CNO
{
	namespace
	{
		std::array<RE::NiAVObject*, 11> VRRoots(RE::VR_NODE_DATA& n)
		{
			return { n.PlayerWorldNode.get(), n.FollowNode.get(), n.RoomNode.get(),
				n.uiNode.get(), n.DialogueUINode.get(), n.HmdNode.get(), n.UprightHmdNode.get(),
				n.LeftWandNode.get(), n.RightWandNode.get(), n.NPCLHnd.get(), n.NPCRHnd.get() };
		}

		bool CompassPath(const RE::NiAVObject* object)
		{
			for (int depth = 0; object && depth < 64; ++depth, object = object->parent) {
				std::string name = object->name.c_str() ? object->name.c_str() : "";
				std::transform(name.begin(), name.end(), name.begin(),
					[](unsigned char c) { return static_cast<char>(std::tolower(c)); });
				if (name.find("skyvr_hmd_compass.nif") != std::string::npos) return true;
			}
			return false;
		}

		void FindVRCompass(RE::NiAVObject* object, int depth,
			std::unordered_set<RE::NiAVObject*>& visited, std::vector<RE::NiAVObject*>& matches)
		{
			if (!object || depth > 64 || visited.size() >= 8192 || !visited.insert(object).second) return;
			if (object->name == RE::BSFixedString("skyVR_HUD01") && CompassPath(object)) matches.push_back(object);
			if (auto* node = object->AsNode())
				for (auto& child : node->GetChildren()) FindVRCompass(child.get(), depth + 1, visited, matches);
		}
	}

	bool HUDMarkerManager::IsCompassVisible(const Compass* a_compass)
	{
		// A visible Flash object cannot override Palm Compass hiding the 3D
		// node (or any ancestor). Known hidden state always vetoes visibility.
		const RE::NiAVObject* node = FindCompassNode();
		// In VR, Flash alone cannot prove that the hand-mounted surface is visible.
		if (REL::Module::IsVR() && !node) return false;
		if (node && !IsNodeVisible(node))
		{
			return false;
		}

		if (a_compass)
		{
			const RE::GFxValue gfxVisible = a_compass->GetMember("_visible");
			const RE::GFxValue gfxAlpha = a_compass->GetMember("_alpha");
			if ((gfxVisible.IsBool() && !gfxVisible.GetBool()) ||
				(gfxAlpha.IsNumber() && gfxAlpha.GetNumber() <= 1.0))
			{
				return false;
			}

			// Non-VR retains the Flash fallback when no 3D node is available.
			return node != nullptr || (gfxVisible.IsBool() && gfxVisible.GetBool()) ||
				(gfxAlpha.IsNumber() && gfxAlpha.GetNumber() > 1.0);
		}
		return node != nullptr;
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

		if (REL::Module::IsVR() && player) {
			if (auto* nodes = player->GetVRNodeData()) {
				const auto roots = VRRoots(*nodes);
				int depth = 0;
				for (auto* p = a_node; p && depth++ < 64; p = p->parent) {
					if (std::find(roots.begin(), roots.end(), p) != roots.end()) return true;
				// Engine parent chains are acyclic; the generic path below is bounded.
					if (!p->parent) break;
				}
			}
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
			compassNode.reset();  // 3D rebuilt: invalidate the retry deadline too.
			compassSearchAfter = {};
		}

		const auto now = std::chrono::steady_clock::now();
		if (now < compassSearchAfter) return nullptr;
		compassSearchAfter = now + std::chrono::seconds(1);
		if (REL::Module::IsVR()) {
			std::vector<RE::NiAVObject*> matches;
			std::unordered_set<RE::NiAVObject*> visited;
			if (auto* nodes = player ? player->GetVRNodeData() : nullptr)
				for (auto* root : VRRoots(*nodes)) FindVRCompass(root, 0, visited, matches);
			// Do not guess between identically named HUD surfaces or select by visibility.
			if (matches.size() == 1) {
				compassNode.reset(matches.front());
				logger::info("[QuestListGaze] verified VR compass node found under skyvr_hmd_compass.nif: {:p}",
					static_cast<const void*>(compassNode.get()));
				return compassNode.get();
			}
			logger::debug("[QuestListGaze] VR compass unresolved: verifiedCandidates={} visited={}", matches.size(), visited.size());
			return nullptr;
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
			handSearchAfter = {};
		}

		const auto now = std::chrono::steady_clock::now();
		if (now < handSearchAfter) return nullptr;
		handSearchAfter = now + std::chrono::seconds(1);
		if (REL::Module::IsVR() && player) {
			if (auto* nodes = player->GetVRNodeData(); nodes && nodes->NPCRHnd) {
				handNode = nodes->NPCRHnd;
				return handNode.get();
			}
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
