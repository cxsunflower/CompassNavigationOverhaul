#pragma once

namespace CNO::PalmTest
{
    // Kept independent of engine headers so the exact production composition can
    // be exercised by a small native test. Caller validates finite input/parent scale.
    template <class Transform, class Point>
    Transform MakeWorldPose(const Transform& anchor, const Point& offset, float width)
    {
        Transform result{};
        result.rotate = anchor.rotate;
        result.translate = anchor.translate + anchor.rotate * offset;
        result.scale = width / 24.0F;
        return result;
    }

    template <class Transform>
    Transform MakeLocalPose(const Transform& parent, const Transform& world)
    {
        return parent.Invert() * world;
    }
}
