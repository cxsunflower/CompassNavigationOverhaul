#include "Scene.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <string>
#include <unordered_set>

namespace CNO::PalmTest::Scene
{
    namespace
    {
        bool Named(RE::NiAVObject* object, std::string_view text, bool substring = false)
        {
            std::string name = object->name.c_str() ? object->name.c_str() : "";
            std::transform(name.begin(), name.end(), name.begin(),
                [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
            return substring ? name.find(text) != std::string::npos : name == text;
        }

        void Find(RE::NiAVObject* object, bool inCompass, int depth,
            std::unordered_set<RE::NiAVObject*>& visited,
            std::vector<RE::NiAVObject*>& found)
        {
            if (!object || depth > 64 || visited.size() >= 8192 || !visited.insert(object).second) return;
            if (Named(object, "cno_palmtest", true)) return;
            inCompass = inCompass || Named(object, "skyvr_hmd_compass.nif", true);
            if (Named(object, "skyvr_hud01")) {
                bool verified = inCompass;
                auto* ancestor = object->parent;
                for (int i = 0; ancestor && i < 64; ++i, ancestor = ancestor->parent)
                    verified = verified || Named(ancestor, "skyvr_hmd_compass.nif", true);
                if (verified) found.push_back(object);
            }
            if (auto* node = object->AsNode()) {
                for (auto& child : node->GetChildren()) Find(child.get(), inCompass, depth + 1, visited, found);
            }
        }

    }

    std::array<RE::NiAVObject*, 11> Roots(RE::VR_NODE_DATA& nodes)
    {
        return {nodes.PlayerWorldNode.get(), nodes.FollowNode.get(), nodes.RoomNode.get(),
            nodes.uiNode.get(), nodes.DialogueUINode.get(), nodes.HmdNode.get(),
            nodes.UprightHmdNode.get(), nodes.LeftWandNode.get(), nodes.RightWandNode.get(),
            nodes.NPCLHnd.get(), nodes.NPCRHnd.get()};
    }

    bool InCurrentScene(RE::NiAVObject* object, RE::VR_NODE_DATA& nodes)
    {
        const auto roots = Roots(nodes);
        for (int i = 0; object && i < 64; ++i, object = object->parent) {
            if (std::find(roots.begin(), roots.end(), object) != roots.end()) return true;
        }
        return false;
    }

    bool Visible(RE::NiAVObject* object)
    {
        for (int depth = 0; object && depth < 64; ++depth, object = object->parent) {
            if (object->GetAppCulled() || object->flags.all(RE::NiAVObject::Flag::kHidden)) return false;
            if (!object->parent) return true;
        }
        return false;
    }

    bool Finite(const RE::NiTransform& transform)
    {
        if (!std::isfinite(transform.scale) || transform.scale <= 0.000001F) return false;
        const auto& p = transform.translate;
        if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z)) return false;
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col)
                if (!std::isfinite(transform.rotate.entry[row][col])) return false;
        return true;
    }

    std::vector<RE::NiAVObject*> FindCompassCandidates(RE::VR_NODE_DATA& nodes)
    {
        std::unordered_set<RE::NiAVObject*> visited;
        std::vector<RE::NiAVObject*> found;
        for (auto* root : Roots(nodes)) Find(root, false, 0, visited, found);
        return found;
    }
}
