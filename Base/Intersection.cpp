//
// Created by mojtaba on 3/30/24.
//
#include "Core.h"
#include "Intersection.h"
#include "GeoUtils.h"

bool CG::Intersection(const CG::Point2d &a, const CG::Point2d &b, const CG::Point2d &c, const CG::Point2d &d) {
    auto ab_c = CG::orientation2D(a, b, c);
    auto ab_d = CG::orientation2D(a, b, d);
    auto cd_a = CG::orientation2D(c, d, a);
    auto cd_b = CG::orientation2D(c, d, b);

    if (ab_c == BETWEEN || ab_c == ORIGIN || ab_c == DESTINATION
       || ab_d == BETWEEN || ab_d == ORIGIN || ab_d == DESTINATION
       || cd_a == BETWEEN || cd_a == ORIGIN || cd_a == DESTINATION
       || cd_b == BETWEEN || cd_b == ORIGIN || cd_b == DESTINATION
    )
        return true;

    return _xor(ab_c == LEFT, ab_d == LEFT) && _xor(cd_a == LEFT, cd_b == LEFT);
}

bool CG::Intersection(const CG::Point2d &a, const CG::Point2d &b, const CG::Point2d &c, const CG::Point2d &d, CG::Point2d &intersection) {

    Vector2f AB = b - a;
    Vector2f CD = d - c;
    Vector2f n(CD[Y], -CD[X]);
    auto deno = dotProduct(n, AB);
    if(!isEqualID(deno, 0)){
        auto AC = c - a;
        auto numer = dotProduct(n, AC);
        auto t = numer/deno;
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

bool CG::Intersection(const CG::Line2d &l1, const CG::Line2d &l2, CG::Point2d &intersection) {
    auto l1_start = l1.getPoint();
    auto l1_end = l1_start + l1.getDir();
    auto l2_start = l2.getPoint();
    auto l2_end = l2_start + l2.getDir();
    return Intersection(l1_start, l1_end, l2_start, l2_end, intersection);
}

bool CG::Intersection(const CG::Line3d &line, const CG::Planef &plane,  CG::Point3d &point) {
    auto n = plane.getNormal();
    auto D = plane.getD();
    auto d = line.getDir();
    auto p = line.getPoint();
    auto nd = dotProduct(n, d);

    if (!isEqualID(nd, 0)) {
        auto t = (-1 * dotProduct(n, p) + D) /nd;
        point.assign(X, p[X] + t * d[X]);
        point.assign(Y, p[Y] + t * d[Y]);
        point.assign(Z, p[Z] + t * d[Z]);
        return true;
    }
    else{
        return false;
    }
}

bool CG::Intersection(const CG::Planef &p1, CG::Planef &p2, CG::Line3d l) {
    auto n1 = p1.getNormal();
    auto n2 = p2.getNormal();
    auto d1 = p1.getD();
    auto d2 = p2.getD();
    auto direction = crossProduct3D(n1, n2);
    if(isEqualID(direction.magnitude(), 0))
        return false;
    auto n1n2 = dotProduct(n1, n2);
    auto n1n2_2 = n1n2 * n1n2;
    auto a = (d2 * n1n2 - d1) / (n1n2_2 - 1);
    auto b = (d1 * n1n2 - d2) / (n1n2_2 - 1);
    auto point = n1 * a + n2 * b;
    l.setPoint(point);
    direction.normalize();
    l.setDirection(direction);
    return true;

}
