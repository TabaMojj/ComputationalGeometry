//
// Created by mojtaba on 3/30/24.
//

#include "Angle.h"

template<class T, size_t dimensions >
static float getAngle(CG::Vector<T, dimensions> v1, CG::Vector<T, dimensions> v2)
{
    auto dot = dotProduct(v1, v2);
    auto theta = acos(fabs(dot));
    return CG::RadianceToDegrees(theta);
}

float CG::AngleLines2D(const Line2d& l1, const Line2d l2)
{
    return getAngle(l1.direction(), l2.direction());
}

float CG::AngleLines3D(const Line& l1, const Line& l2)
{
    return getAngle(l1.direction(), l2.direction());
}

float CG::AngleLinePlane(const Line& l, const Planef p)
{
    auto theta = getAngle(l.direction(), p.getNormal());
    return 90 - theta;
}

float CG::AnglePlanes(const Planef p1, const Planef p2)
{
    return getAngle(p1.getNormal(), p2.getNormal());
}