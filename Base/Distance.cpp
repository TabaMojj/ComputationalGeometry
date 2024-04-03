//
// Created by mojtaba on 3/30/24.
//

#include "Distance.h"

float CG::distance(Line& line, Point3D& C)
{
    Vector3f AC = C - line.point();
    auto t = dotProduct(line.direction(),AC);
    auto xt = line.point() + line.direction()*t;
    auto dist_vec = xt - C;
    return dist_vec.magnitude();
}

float CG::distance(CG::Planef &p, CG::Point3D &Q) {
   auto result = dotProduct(p.getNormal(), Q) - p.getD();
    return result;
}