#pragma once
#include <RE/Skyrim.h>

namespace CNO::PalmTest
{
    // Owns only the test surface. Never acquires ownership of the source compass.
    class Surface
    {
    public:
        void Detach();
        void Hide();
        void AllowLoadRetry() { assetFailed = false; }
        bool EnsureAttached(RE::NiNode* parent);
        bool ApplyWorldPose(const RE::NiTransform& desired);
        RE::NiNode* Parent() const { return owner.get(); }
        const RE::NiTransform& World() const { return panel->world; } // after successful ApplyWorldPose
    private:
        RE::NiPointer<RE::NiAVObject> panel;
        RE::NiPointer<RE::NiNode> owner;
        bool assetFailed{false};
    };
}
