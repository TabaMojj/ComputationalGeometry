//
// Created by mojtaba on 3/30/24.
//

#pragma once
#ifndef COMPUTATIONALGEOMETRY_ANGLE_H
#define COMPUTATIONALGEOMETRY_ANGLE_H

#include "Primitive/Line.h"
#include "Primitive/Plane.h"

namespace CG {

    float AngleLines2D( const Line2d& l1, const Line2d l2);

    float AngleLines3D(const Line& l1, const Line& l2);

    float AngleLinePlane(const Line& l, const Planef p);

    float AnglePlanes(const Planef p1, const Planef p2);
}

#endif //COMPUTATIONALGEOMETRY_ANGLE_H