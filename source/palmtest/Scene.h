#pragma once
#include <RE/Skyrim.h>
#include <vector>

namespace CNO::PalmTest::Scene
{
    // Read-only scene queries. No ownership or transform writes in this module.
    std::vector<RE::NiAVObject*> FindCompassCandidates(RE::VR_NODE_DATA& nodes);
    bool InCurrentScene(RE::NiAVObject* object, RE::VR_NODE_DATA& nodes);
    bool Visible(RE::NiAVObject* object);
    bool Finite(const RE::NiTransform& transform);
}
