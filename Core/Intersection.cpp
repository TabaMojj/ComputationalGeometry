//
// Created by mojtaba on 3/30/24.
//
#include "../Base/Core.h"
#include "Intersection.h"
#include "GeoUtils.h"

using namespace CG;

bool CG::intersect(CG::Line2d& l1, CG::Line2d& l2, CG::Point2D& pi){
    Vector2f l1p = l1.point();
    Vector2f l2p = l2.point();
    Vector2f l1d = l1.direction();
    Vector2f l2d = l2.direction();

    float a, b, c, d, e, f;

    a = l1d[X];
    b = -l2d[X];
    c = l2p[X] - l1p[X];
    d = l1d[Y];
    e = -l2d[Y];
    f = l2p[Y] - l1p[Y];

    Vector2f diff = l2p - l1p;
    auto prep_l2d = perpendicular(l2d);
    float dot_d0_prepd1 = dotProduct(l1d, prep_l2d);

    if (!isEqualD(dot_d0_prepd1, 0))
    {
        float denominator = a * e - b * d;
        float t_numerator = c * e - b * f;
        float s_numerator = a * f - c * a;

        float t = t_numerator / denominator;

        float x = l1p[X] + t * l1d[X];
        float y = l1p[Y] + t * l1d[Y];

        if ((x - l1p[X]) / l1d[X] < 0) return false;
        if ((y - l1p[Y]) / l1d[Y] < 0) return false;

        if ((x - l2p[X]) / l2d[X] < 0) return false;
        if ((y - l2p[Y]) / l2d[Y] < 0) return false;

        pi.assign(X, x);
        pi.assign(Y, y);
        return true;
    }
    else
    {
        return false;
    }
}

bool CG::intersect(const CG::Point2D& a, const CG::Point2D& b, const CG::Point2D& c, const CG::Point2D& d) {

    if (CG::orientation2D(a, b, c) == CG::BETWEEN
        || CG::orientation2D(a, b, d) == CG::BETWEEN
        || CG::orientation2D(c, d, a) == CG::BETWEEN
        || CG::orientation2D(c, d, b) == CG::BETWEEN )
    {
        return true;
    }

    return CG::_xor(CG::left(a,b,c), CG::left(a,b,d)) && CG::_xor(CG::left(c, d, a), CG::left(c, d, b));
}

bool CG::intersect(CG::Point2D& a, CG::Point2D& b , CG::Point2D& c , CG::Point2D& d , CG::Point2D& intersection)
{
    Vector2f AB = b - a;
    Vector2f CD = d - c;

    Vector2f n( CD[Y], -CD[X]);

    auto deno = dotProduct(n, AB);

    if (!isEqualD(deno, 0))
    {
        auto AC = c-a;
        auto nume = dotProduct(n, AC);
        auto t = nume / deno;

        auto x = a[X] + t * AB[X];
        auto y = a[Y] + t * AB[Y];

        intersection.assign(X, x);
        intersection.assign(Y, y);
        return true;
    }
    else
    {
        return false;
    }
}

bool CG::intersect(CG::Planef& plane, CG::Line& line, CG::Point3D& point){

    auto n = plane.getNormal();
    auto D = plane.getD();
    auto d = line.direction();
    auto p = line.point();

    auto denominator = dotProduct(n, d);

    if (!isEqualD(denominator, 0)){
        auto t = (-1 * dotProduct(n, p) + D) / denominator;
        point.assign(X, p[X] + t * d[X]);
        point.assign(Y, p[Y] + t * d[Y]);
        point.assign(Z, p[Z] + t * d[Z]);
        return true;
    }
    else{
        return false;
    }
}

bool CG::intersect(CG::Planef& p1, CG::Planef& p2, CG::Line& l) {

    auto n1 = p1.getNormal();
    auto n2 = p2.getNormal();
    auto d1 = p1.getD();
    auto d2 = p2.getD();

    auto direction = crossProduct3D(n1,n2);
    direction.normalize();

    if (isEqualD(direction.magnitude(), 0))
        return false;

    auto n1n2 = dotProduct(n1, n2);
    auto n1n2_2 = n1n2 * n1n2;

    auto a = (d2 * n1n2 - d1) / (n1n2_2 - 1);
    auto b = (d1 * n1n2 - d2) / (n1n2_2 - 1);

    auto point = n1*a + n2*b;

    l.setPoint(point);
    l.setDirection(direction);

    return true;
}
