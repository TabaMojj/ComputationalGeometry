//
// Created by mojtaba on 3/29/24.
//

#include "Vector.h"

float CG::crossProduct2D(CG::Vector2f v1, CG::Vector2f v2) {
    return v1[X]*v2[Y] - v1[Y]*v2[X];
}

CG::Vector3f CG::crossProduct3D(CG::Vector3f v1, CG::Vector3f v2) {
    float x_, y_, z_;

    x_ = v1[Y] * v2[Z] - v1[Z] * v2[Y];
    y_ = - (v2[Z] * v1[X] - v1[Z] * v2[X]);
    z_ = v1[X] * v2[Y] - v2[X] * v1[Y];

    return {x_, y_, z_};
}

float CG::scalarTripleProduct(CG::Vector3f v1, CG::Vector3f v2, CG::Vector3f v3) {
    auto bc_cross = crossProduct3D(v2, v3);
    return dotProduct(v1, bc_cross);
}