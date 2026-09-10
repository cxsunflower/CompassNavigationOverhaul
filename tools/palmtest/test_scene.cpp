#include "../../source/palmtest/Scene.h"
#include <iostream>
#include <limits>
#include <stdexcept>

int main()
{
    using namespace CNO::PalmTest;
    int checks=0;
    const auto check=[&](bool ok) { ++checks; if(!ok) throw std::runtime_error("scene check " + std::to_string(checks)); };
    RE::NiNode root, nif, other, probe;
    RE::NiAVObject compass, unrelated, second, probeChild;
    root.name="RoomNode";nif.name="Meshes/skyVR_HMD_Compass.nif";
    compass.name="skyVR_HUD01";unrelated.name="skyVR_HUD01";second.name="skyVR_HUD01";
    probe.name="CNO_PalmTest_Independent";probeChild.name="skyVR_HUD01";
    root.Add(nif);nif.Add(compass);root.Add(unrelated);nif.Add(probe);probe.Add(probeChild);
    RE::VR_NODE_DATA nodes;nodes.RoomNode=&root;nodes.uiNode=&nif;
    auto found=Scene::FindCompassCandidates(nodes);
    check(found.size()==1 && found.front()==&compass); // dedupe overlapping roots, reject generic HUD, skip probe
    check(Scene::InCurrentScene(&compass,nodes));
    check(!Scene::InCurrentScene(&other,nodes));
    check(Scene::Visible(&compass));
    nif.culled=true;check(!Scene::Visible(&compass));nif.culled=false;
    root.flags.hidden=true;check(!Scene::Visible(&compass));root.flags.hidden=false;
    check(!Scene::Visible(nullptr));
    nif.Add(second);check(Scene::FindCompassCandidates(nodes).size()==2); // runtime must not guess
    RE::VR_NODE_DATA detached;detached.RoomNode=&other;
    check(!Scene::InCurrentScene(&compass,detached));
    // Root discovery beginning beneath the named NIF still checks the candidate's ancestors.
    RE::VR_NODE_DATA inner;inner.PlayerWorldNode=&compass;
    check(Scene::FindCompassCandidates(inner).size()==1);
    RE::NiTransform t;
    check(Scene::Finite(t));
    t.scale=0;check(!Scene::Finite(t));t.scale=1;
    t.translate.x=std::numeric_limits<float>::infinity();check(!Scene::Finite(t));t.translate.x=0;
    t.rotate.entry[1][2]=std::numeric_limits<float>::quiet_NaN();check(!Scene::Finite(t));
    std::cout<<checks<<" production scene-query checks passed using test-only nodes (not engine ABI/render proof)\n";
}
