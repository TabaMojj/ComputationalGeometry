//
// Created by mojtaba on 3/30/24.
//
#include "Distance.h"

float CG::distance(Line3d &line, Point3d &p) {
    auto AC = p - line.getPoint();
    auto t = dotProduct(line.getDir(), AC);
    auto xt = line.getPoint() + line.getDir() * t;
    auto dist_vec = xt - p;
    return dist_vec.magnitude();
}

float CG::distance(CG::Planef &p, CG::Point3d &Q) {
   auto result = dotProduct(p.getNormal(), Q) - p.getD();
    return result;
}

