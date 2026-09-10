// Runs the production Pose.h templates with a minimal affine-transform test type.
#include "../../source/palmtest/Pose.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
struct Point {
    float x{},y{},z{};
    Point operator+(Point p) const { return {x+p.x,y+p.y,z+p.z}; }
    Point operator*(float s) const { return {x*s,y*s,z*s}; }
};
struct Matrix {
    float m[3][3]{{1,0,0},{0,1,0},{0,0,1}};
    Point operator*(Point p) const {
        return {m[0][0]*p.x+m[0][1]*p.y+m[0][2]*p.z,
            m[1][0]*p.x+m[1][1]*p.y+m[1][2]*p.z,
            m[2][0]*p.x+m[2][1]*p.y+m[2][2]*p.z};
    }
    Matrix operator*(const Matrix& r) const {
        Matrix out{};
        for(int i=0;i<3;++i) for(int j=0;j<3;++j) {
            out.m[i][j]=0;
            for(int k=0;k<3;++k) out.m[i][j]+=m[i][k]*r.m[k][j];
        }
        return out;
    }
    Matrix transpose() const { Matrix r{};for(int i=0;i<3;++i)for(int j=0;j<3;++j)r.m[i][j]=m[j][i];return r; }
};
struct Transform {
    Matrix rotate{};Point translate{};float scale{1};
    Transform operator*(const Transform& r) const {
        return {rotate*r.rotate,translate+(rotate*r.translate)*scale,scale*r.scale};
    }
    Transform Invert() const {
        const auto rot=rotate.transpose();
        return {rot,(rot*translate)*(-1/scale),1/scale};
    }
};
void near(float a,float b) { if(std::abs(a-b)>0.002f)throw std::runtime_error("pose mismatch"); }
void same(const Transform&a,const Transform&b) {
    near(a.scale,b.scale);near(a.translate.x,b.translate.x);near(a.translate.y,b.translate.y);near(a.translate.z,b.translate.z);
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)near(a.rotate.m[i][j],b.rotate.m[i][j]);
}
int main() {
    int cases=0;
    for(float palmScale:{0.01f,0.05f,0.12f,0.5f,1.f,10.f})
    for(float parentScale:{0.05f,0.12f,1.f,4.f})
    for(float width:{4.f,24.f,48.f,80.f})
    for(float angle:{0.f,0.5f,1.8f}) {
        Matrix rot{{{std::cos(angle),-std::sin(angle),0},{std::sin(angle),std::cos(angle),0},{0,0,1}}};
        Transform anchor{rot,{23,-52,80},palmScale};
        Transform parent{rot,{-19,33,42},parentScale};
        Point offset{3,-14,2};
        const auto anchorBefore=anchor;
        const auto world=CNO::PalmTest::MakeWorldPose(anchor,offset,width);
        const auto local=CNO::PalmTest::MakeLocalPose(parent,world);
        same(parent*local,world);
        same(anchor,anchorBefore);
        near(world.scale,width/24);
        anchor.scale=1;
        same(CNO::PalmTest::MakeWorldPose(anchor,offset,width),world);
        ++cases;
    }
    std::cout<<cases<<" native pose cases passed (scale-independent pose and spacing; parent cancellation; no source writes)\n";
}
