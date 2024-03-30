//
// Created by mojtaba on 3/29/24.
//
#include "../Primitive/Point.h"
#include "Core.h"
#ifndef COMPUTATIONALGEOMETRY_GEOUTILS_H
#define COMPUTATIONALGEOMETRY_GEOUTILS_H

#endif //COMPUTATIONALGEOMETRY_GEOUTILS_H

namespace CG {
    double areaTriangle2d(const Point2d &a, const Point2d &b, const Point2d &c);

    int orientation2D(const Point2d &a, const Point2d &b, const Point2d &c);

    bool collinear(const Vector3f &a, const Vector3f &b);

    bool collinear(const Point3d &a, const Point3d &b, const Point3d &c);

    bool coplanar(const Point3d &a, const Point3d &b, const Point3d &c, const Point3d &d);

    bool coplanar(const Point3d &a, const Point3d &b, const Point3d &c);

}