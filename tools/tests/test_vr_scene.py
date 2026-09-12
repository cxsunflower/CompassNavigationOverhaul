"""Exercise production VR root/path discovery with a minimal scene graph."""
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest
from test_compass_visibility import body, ROOT


def fixture():
    s = (ROOT / 'source/hud/SceneNodes.cpp').read_text(encoding='utf-8-sig')
    helpers = s[s.index('\t\tstd::array<RE::NiAVObject*, 11> VRRoots'):s.index('\n\tbool HUDMarkerManager::IsCompassVisible')]
    helpers = helpers.rsplit('\n\t}', 1)[0]
    return r'''
#include <array>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
namespace REL {struct Module {static bool IsVR(){return true;}};}
namespace RE {
using BSFixedString=std::string;
struct NiAVObject;
struct Ptr {NiAVObject* p=nullptr;NiAVObject* get()const{return p;}};
struct NiAVObject {
 std::string name;NiAVObject* parent=nullptr;std::vector<Ptr> children;
 NiAVObject* AsNode(){return this;} auto& GetChildren(){return children;}
 void Add(NiAVObject& n){children.push_back({&n});n.parent=this;}
};
struct VR_NODE_DATA {Ptr PlayerWorldNode,FollowNode,RoomNode,uiNode,DialogueUINode,HmdNode,UprightHmdNode,LeftWandNode,RightWandNode,NPCLHnd,NPCRHnd;};
}
''' + helpers + r'''
struct Player {RE::VR_NODE_DATA nodes;RE::VR_NODE_DATA* GetVRNodeData(){return &nodes;} RE::NiAVObject* Get3D1(bool){return nullptr;}};
struct Camera {RE::Ptr cameraRoot;};
struct HUDMarkerManager {Player* player=nullptr;Camera* playerCamera=nullptr;bool IsNodeFromCurrentRoots(const RE::NiAVObject*) const;};
bool HUDMarkerManager::IsNodeFromCurrentRoots(const RE::NiAVObject* a_node){BODY}
'''.replace('const RE::NiAVObject* a_node){BODY}', 'const RE::NiAVObject* a_node) const{' + body(s, 'bool HUDMarkerManager::IsNodeFromCurrentRoots') + '}') + r'''
#define CHECK(x) do {if(!(x)){std::cerr<<"FAIL " #x;return 1;}}while(false)
int main(){
 RE::NiAVObject world{"World"},room{"Room"},nif{"skyVR_HMD_Compass.nif"},mesh{"skyVR_HUD01"},other{"skyVR_HUD01"},outer{"Scene"};
 outer.Add(world);world.Add(room);room.Add(nif);nif.Add(mesh);world.Add(other);
 Player player;player.nodes.PlayerWorldNode={&world};player.nodes.RoomNode={&room};
 HUDMarkerManager manager;manager.player=&player;
 std::unordered_set<RE::NiAVObject*> visited;std::vector<RE::NiAVObject*> found;
 for(auto* root:VRRoots(player.nodes)) FindVRCompass(root,0,visited,found);
 CHECK(found.size()==1);CHECK(found[0]==&mesh);CHECK(!CompassPath(&other));
 CHECK(manager.IsNodeFromCurrentRoots(&mesh));
 // Root matching must accept a VR root partway along the ancestor chain.
 CHECK(manager.IsNodeFromCurrentRoots(&room));
 RE::NiAVObject replacement{"NewWorld"};player.nodes.PlayerWorldNode={&replacement};player.nodes.RoomNode={};
 CHECK(!manager.IsNodeFromCurrentRoots(&mesh));
 RE::NiAVObject nif2{"SKYVR_HMD_COMPASS.NIF"},mesh2{"skyVR_HUD01"};world.Add(nif2);nif2.Add(mesh2);
 visited.clear();found.clear();FindVRCompass(&world,0,visited,found);CHECK(found.size()==2);
 visited.clear();found.clear();FindVRCompass(&world,65,visited,found);CHECK(found.empty());
 std::cout<<"PASS 8 production VR discovery/cache checks\n";
}
'''


class VRSceneTests(unittest.TestCase):
    def test_discovery_policy_and_independent_retry_deadlines(self):
        s = (ROOT / 'source/hud/SceneNodes.cpp').read_text(encoding='utf-8-sig')
        self.assertIn('if (matches.size() == 1)', s)
        self.assertIn('if (REL::Module::IsVR() && !node) return false;', s)
        self.assertNotIn('nodeRetryTime', s)
        self.assertIn('now < compassSearchAfter', s)
        self.assertIn('now < handSearchAfter', s)

    @unittest.skipUnless(shutil.which('cl'), 'Run under the VS developer environment')
    def test_actual_discovery_and_current_scene_validation(self):
        with tempfile.TemporaryDirectory(prefix='cno-vr-scene-') as tmp:
            p = Path(tmp)
            source = p/'scene.cpp'
            source.write_text(fixture(), encoding='utf-8')
            exe = p/'scene.exe'
            result = subprocess.run(['cl','/nologo','/std:c++17','/EHsc','/utf-8',str(source),'/Fe:'+str(exe),'/Fo:'+str(p/'scene.obj')],capture_output=True,text=True)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            result = subprocess.run([str(exe)],capture_output=True,text=True)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            print(result.stdout.strip())

if __name__ == '__main__':
    unittest.main()
