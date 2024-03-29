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