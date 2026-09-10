// Original CNO test geometry. nifly is a build-only dependency, not shipped in the plugin.
#include "NifFile.hpp"
#include <iostream>
using namespace nifly;
int main(int argc, char** argv)
{
    if (argc != 2) return 2;
    NifFile file;
    file.Create(NiVersion(NiVersion::ToFile(20, 2, 0, 7), 12, 100));
    file.GetRootNode()->name.get() = "CNO_PalmTest_Asset";
    // XY plane, 24 by 12 Skyrim units, normal +Z. Double-sided for orientation diagnosis.
    std::vector<Vector3> v{{-12,-6,0},{12,-6,0},{12,6,0},{-12,6,0}};
    std::vector<Triangle> t{{0,1,2},{0,2,3}};
    std::vector<Vector2> uv{{0,1},{1,1},{1,0},{0,0}};
    std::vector<Vector3> n(4, Vector3(0,0,1));
    auto* shape = file.CreateShapeFromData("CNO_PalmTest_Surface", &v, &t, &uv, &n);
    if (!shape) return 3;
    file.DeleteShader(shape);
    auto shader = std::make_unique<BSEffectShaderProperty>();
    shader->shaderFlags1 = 0x80000000; // Z test: this probe is not an always-on-top overlay.
    shader->shaderFlags2 = 0x11;       // Z write + double sided; no skinning/vertex colors.
    shader->sourceTexture.get() = "textures\\CNO\\PalmTest.dds";
    shader->textureClampMode = 3;
    shader->baseColor = Color4(1,1,1,1);
    shader->baseColorScale = 1.0f;
    shape->ShaderPropertyRef()->index = file.GetHeader().AddBlock(std::move(shader));
    if (file.Save(argv[1]) != 0) return 4;
    NifFile check;
    if (check.Load(argv[1]) != 0 || check.GetShapes().size() != 1) return 5;
    const auto* readShape = check.GetShapes().front();
    if (readShape->GetNumVertices() != 4 || readShape->GetNumTriangles() != 2) return 6;
    std::cout << "Verified independent SSE/VR panel: 4 vertices, 2 triangles, 24x12 units\n";
    return 0;
}
