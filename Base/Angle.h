//
// Created by mojtaba on 3/30/24.
//
#include "../Primitive/Line.h"
#include "../Primitive/Plane.h"
#ifndef COMPUTATIONALGEOMETRY_ANGLE_H
#define COMPUTATIONALGEOMETRY_ANGLE_H

#endif //COMPUTATIONALGEOMETRY_ANGLE_H

namespace CG {

     double AngleLines2D(const Line2d &l1, const Line2d &l2);

     double AngleLines3D(const Line3d &l1, const Line3d &l2);

     double AngleLinePlane(const Line3d &l1, const Planef &p);

     double AnglePlanes(const Planef &p1, const Planef &p2);
}