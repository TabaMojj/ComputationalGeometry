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