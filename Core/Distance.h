//
// Created by mojtaba on 3/30/24.
//
#pragma once
#ifndef COMPUTATIONALGEOMETRY_DISTANCE_H
#define COMPUTATIONALGEOMETRY_DISTANCE_H

#include "../Primitive/Point.h"
#include "../Primitive/Line.h"
#include "../Primitive/Plane.h"

namespace CG {

    float distance(Line& line, Point3D& C);

    float distance(Planef &p, Point3D &Q);

}

#endif //COMPUTATIONALGEOMETRY_DISTANCE_H