"""Compile actual visibility method bodies against minimal engine test doubles."""
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]


def body(source, signature):
    start = source.index('{', source.index(signature))
    depth = 1
    pos = start + 1
    while depth:
        if source[pos] == '{': depth += 1
        elif source[pos] == '}': depth -= 1
        pos += 1
    return source[start + 1:pos - 1]


def native_fixture():
    scene = (ROOT / 'source/hud/SceneNodes.cpp').read_text(encoding='utf-8-sig')
    gaze = (ROOT / 'source/hud/Gaze.cpp').read_text(encoding='utf-8-sig')
    visible = body(scene, 'bool HUDMarkerManager::IsCompassVisible(')
    node = body(scene, 'bool HUDMarkerManager::IsNodeVisible(')
    # Only the early gate is under test here; angle maths is deliberately excluded.
    early = body(gaze, 'bool HUDMarkerManager::IsLookingAtCompass(').split('RE::NiPoint3 forward', 1)[0]
    return r'''
#include <iostream>
#include <string_view>
namespace REL {struct Module {static bool IsVR(){return vr;} static inline bool vr=false;};}
namespace RE {
struct GFxValue {
 int type=0; double value=0;
 bool IsBool() const{return type==1;} bool GetBool() const{return value!=0;}
 bool IsNumber() const{return type==2;} double GetNumber() const{return value;}
};
struct NiAVObject {
 enum class Flag{kHidden};
 struct Flags{bool hidden=false; bool all(Flag) const{return hidden;}} flags;
 bool culled=false; const NiAVObject* parent=nullptr;
 bool GetAppCulled() const{return culled;}
};
}
namespace settings::questlist {bool requireLookingAtCompass=true;bool requireCompassVisible=true;}
struct Compass {
 RE::GFxValue visible{1,1},alpha{2,100};
 RE::GFxValue GetMember(std::string_view name) const{return name=="_visible"?visible:alpha;}
};
struct HUDMarkerManager {
 RE::NiAVObject* node=nullptr; bool compassGazeActive=true; bool compassVisibilityPassed=false;
 RE::NiAVObject* FindCompassNode(){return node;}
 bool IsCompassVisible(const Compass*);
 bool IsNodeVisible(const RE::NiAVObject*) const;
 bool IsLookingAtCompass(const Compass*);
};
''' + '\nbool HUDMarkerManager::IsCompassVisible(const Compass* a_compass){' + visible + '}\n' + \
        'bool HUDMarkerManager::IsNodeVisible(const RE::NiAVObject* a_node) const{' + node + '}\n' + \
        'bool HUDMarkerManager::IsLookingAtCompass(const Compass* a_compass){' + early + 'return compassVisible;}\n' + r'''
#define CHECK(x) do{if(!(x)){std::cerr<<"FAIL: " #x<<"\n";return 1;}}while(false)
int main(){
 HUDMarkerManager m;RE::NiAVObject n,parent;Compass c;m.node=&n;
 n.culled=true;CHECK(!m.IsCompassVisible(&c));
 n.culled=false;n.parent=&parent;parent.culled=true;CHECK(!m.IsCompassVisible(&c));
 parent.culled=false;parent.flags.hidden=true;CHECK(!m.IsCompassVisible(&c));
 parent.flags.hidden=false;CHECK(m.IsCompassVisible(&c));
 c.visible.value=0;CHECK(!m.IsCompassVisible(&c));
 c.visible.value=1;c.alpha.value=0;CHECK(!m.IsCompassVisible(&c));
 c.alpha.value=100;CHECK(m.IsCompassVisible(&c));
 m.node=nullptr;CHECK(m.IsCompassVisible(&c));REL::Module::vr=true;CHECK(!m.IsCompassVisible(&c));REL::Module::vr=false;c.visible.value=0;CHECK(!m.IsCompassVisible(&c));
 c.visible={};c.alpha={};CHECK(!m.IsCompassVisible(&c));
 m.node=&n;c.visible={1,1};c.alpha={2,100};
 settings::questlist::requireLookingAtCompass=false;n.culled=true;
 CHECK(!m.IsLookingAtCompass(&c));CHECK(!m.compassGazeActive);
 settings::questlist::requireCompassVisible=false;CHECK(m.IsLookingAtCompass(&c));
 settings::questlist::requireCompassVisible=true;n.culled=false;CHECK(m.IsLookingAtCompass(&c));
 settings::questlist::requireLookingAtCompass=true;n.culled=true;CHECK(!m.IsLookingAtCompass(&c));
 std::cout<<"PASS 16 native visibility and independent-gate checks\n";
}
'''


class CompassVisibilityTests(unittest.TestCase):
    def test_fixture_reads_production_methods(self):
        text = native_fixture()
        self.assertIn('FindCompassNode()', text)
        self.assertIn('GetAppCulled()', text)
        self.assertIn('requireLookingAtCompass', text)

    @unittest.skipUnless(shutil.which('cl') or shutil.which('c++'), 'Run under the VS developer environment for native regression')
    def test_native_visibility_and_independent_gates(self):
        with tempfile.TemporaryDirectory(prefix='cno-visibility-') as tmp:
            directory = Path(tmp)
            cpp = directory / 'visibility.cpp'
            cpp.write_text(native_fixture(), encoding='utf-8')
            binary = directory / ('visibility.exe' if shutil.which('cl') else 'visibility')
            if shutil.which('cl'):
                command = ['cl', '/nologo', '/std:c++17', '/EHsc', '/utf-8', str(cpp), '/Fe:' + str(binary), '/Fo:' + str(directory / 'visibility.obj')]
            else:
                command = ['c++', '-std=c++17', str(cpp), '-o', str(binary)]
            build = subprocess.run(command, capture_output=True, text=True)
            self.assertEqual(build.returncode, 0, build.stdout + build.stderr)
            result = subprocess.run([str(binary)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            print(result.stdout.strip())


if __name__ == '__main__':
    unittest.main()
