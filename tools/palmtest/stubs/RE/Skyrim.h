#pragma once
// Test-only scene model. This include directory is NEVER supplied to the game DLL target.
#include <string>
#include <vector>

namespace RE
{
    struct NiPoint3 { float x{}, y{}, z{}; };
    struct NiTransform
    {
        struct Matrix { float entry[3][3]{{1,0,0},{0,1,0},{0,0,1}}; } rotate;
        NiPoint3 translate;
        float scale{1};
    };
    template <class T> struct NiPointer
    {
        T* value{};
        NiPointer() = default;
        NiPointer(T* p) : value(p) {}
        T* get() const { return value; }
    };
    class NiNode;
    class NiAVObject
    {
    public:
        enum class Flag { kHidden };
        struct Flags { bool hidden{}; bool all(Flag) const { return hidden; } } flags;
        std::string name;
        NiAVObject* parent{};
        bool culled{};
        virtual ~NiAVObject() = default;
        virtual NiNode* AsNode() { return nullptr; }
        bool GetAppCulled() const { return culled; }
    };
    class NiNode : public NiAVObject
    {
    public:
        std::vector<NiPointer<NiAVObject>> children;
        NiNode* AsNode() override { return this; }
        auto& GetChildren() { return children; }
        void Add(NiAVObject& c) { children.emplace_back(&c); c.parent = this; }
    };
    struct VR_NODE_DATA
    {
        NiPointer<NiAVObject> PlayerWorldNode, FollowNode, RoomNode, uiNode, DialogueUINode,
            HmdNode, UprightHmdNode, LeftWandNode, RightWandNode, NPCLHnd, NPCRHnd;
    };
}
