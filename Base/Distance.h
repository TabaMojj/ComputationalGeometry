//
// Created by mojtaba on 3/30/24.
//
#include "../Primitive/Point.h"
#include "../Primitive/Line.h"
#include "../Primitive/Plane.h"
#ifndef COMPUTATIONALGEOMETRY_DISTANCE_H
#define COMPUTATIONALGEOMETRY_DISTANCE_H

#endif //COMPUTATIONALGEOMETRY_DISTANCE_H

namespace CG {

    float distance(Line3d &line, Point3d &p);

    float distance(Planef &p, Point3d &Q);
}