//
// Created by mojtaba on 3/29/24.
//
#include "../Primitive/Point.h"
#include "Core.h"
#include "Polygon.h"

#ifndef COMPUTATIONALGEOMETRY_GEOUTILS_H
#define COMPUTATIONALGEOMETRY_GEOUTILS_H
namespace CG {
    double areaTriangle2d(const Point2d &a, const Point2d &b, const Point2d &c);

    int orientation2D(const Point2d &a, const Point2d &b, const Point2d &c);

    bool collinear(const Vector3f &a, const Vector3f &b);

    bool collinear(const Point3d &a, const Point3d &b, const Point3d &c);

    bool coplanar(const Point3d &a, const Point3d &b, const Point3d &c, const Point3d &d);

    bool coplanar(const Point3d &a, const Point3d &b, const Point3d &c);

    bool isDiagonal(const Vertex2D *v1, const Vertex2D *v2, PolygonS2D *poly = nullptr);
}
#endif //COMPUTATIONALGEOMETRY_GEOUTILS_H