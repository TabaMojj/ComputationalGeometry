//
// Created by mojtaba on 3/30/24.
//
#pragma once
#include "../Primitive/Point.h"
#include "../Primitive/Line.h"

#ifndef COMPUTATIONALGEOMETRY_INTERSECTION_H
#define COMPUTATIONALGEOMETRY_INTERSECTION_H

#endif //COMPUTATIONALGEOMETRY_INTERSECTION_H

namespace CG {

    bool Intersection(const Point2d &a, const Point2d &b, const Point2d &c, const Point2d &d);

    bool Intersection(const Point2d &a, const Point2d &b, const Point2d &c, const Point2d &d, Point2d &intersection);

    bool Intersection(const Line2d &l1, const Line2d &l2, Point2d &intersection);

}