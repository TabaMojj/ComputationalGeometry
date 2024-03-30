//
// Created by mojtaba on 3/29/24.
//

#include "GeoUtils.h"
#include "Core.h"
double CG::areaTriangle2d(const CG::Point2d &a, const CG::Point2d &b, const CG::Point2d &c) {
    auto AB = b - a;
    auto AC = c -  a;
    auto result = crossProduct2D(AB, AC);
    return result/2;
}

int CG::orientation2D(const CG::Point2d &a, const CG::Point2d &b, const CG::Point2d &c) {
    auto area = areaTriangle2d(a, b, c);

    if (area > 0 && area < TOLERANCE)
        area = 0;
    if (area < 0 && area > TOLERANCE)
        area = 0;

    Vector2f ab = b - a;
    Vector2f ac = c - a;

    if (area > 0)
        return LEFT;
    if(area < 0)
        return RIGHT;

    if((ab[X]*ac[X] < 0) || (ab[Y] * ac[Y] < 0))
        return BEHIND;

    if(ab.magnitude() < ac.magnitude())
        return BEYOND;

    if (a == c)
        return ORIGIN;

    if (b == c)
        return DESTINATION;

    return BETWEEN;
}

bool CG::collinear(const CG::Vector3f &a, const CG::Vector3f &b) {
    auto v1 = a[X] * b[Y] - a[Y] * b[X];
    auto v2 = a[Y] * b[Z] - a[Z] * b[Y];
    auto v3 = a[Z] * b[Z] - a[Z] * b[X];
    return isEqualID(v1, 0) && isEqualID(v2, 0) && isEqualID(v3, 0);
}

bool CG::collinear(const CG::Point3d &a, const CG::Point3d &b, const CG::Point3d &c) {
    auto AB = b - a;
    auto AC = c - a;
    return collinear(AB, AC);
}

bool CG::coplanar(const CG::Point3d &a, const CG::Point3d &b, const CG::Point3d &c, const CG::Point3d &d) {
    auto AB = b - a;
    auto AC = c - a;
    auto AD = d - a;
    return coplanar(AB, AC, AC);
}

bool CG::coplanar(const CG::Point3d &a, const CG::Point3d &b, const CG::Point3d &c) {
    float value = scalarTripleProduct(a, b, c);
    return isEqualID(value, 0);
}
