#include "Surface.h"
#include "Scene.h"
#include "Pose.h"
#include "RE/B/BSModelDB.h"
#include "utils/Logger.h"

namespace CNO::PalmTest
{
    namespace { constexpr auto kModel = "CNO\\PalmTest.nif"; }

    void Surface::Hide()
    {
        if (panel) panel->SetAppCulled(true);
    }

    void Surface::Detach()
    {
        Hide();
        if (panel && panel->parent) panel->parent->DetachChild(panel.get());
        panel.reset();
        owner.reset();
    }

    bool Surface::EnsureAttached(RE::NiNode* parent)
    {
        if (panel) return true;
        if (assetFailed) return false;
        RE::NiPointer<RE::NiNode> model;
        const RE::BSModelDB::DBTraits::ArgsType args{};
        const auto result = RE::BSModelDB::Demand(kModel, model, args);
        if (!model) {
            logger::error("[PalmTest] Model load failed ({}). Disable/re-enable after installing meshes/CNO/PalmTest.nif", static_cast<int>(result));
            assetFailed = true;
            return false;
        }
        // Clone only OUR model, never clone or edit the shared compass HUD surface.
        RE::NiPointer<RE::NiObject> clone{model->Clone()};
        auto* node = clone ? clone->AsNode() : nullptr;
        if (!node) {
            logger::error("[PalmTest] Own model clone failed; leaving compass untouched");
            assetFailed = true;
            return false;
        }
        panel.reset(node);
        panel->name = "CNO_PalmTest_Independent";
        panel->SetAppCulled(true);
        owner.reset(parent);
        owner->AttachChild(panel.get(), true);
        logger::info("[PalmTest] Independent 24x12 mesh attached to RoomNode; no Compass/Palm writes");
        return true;
    }

    bool Surface::ApplyWorldPose(const RE::NiTransform& desired)
    {
        const auto local = MakeLocalPose(owner->world, desired);
        if (!Scene::Finite(local)) { Hide(); return false; }
        panel->local = local;
        panel->SetAppCulled(false);
        RE::NiUpdateData update{};
        panel->Update(update); // independent geometry transforms AND bounds
        return true;
    }
}
