//
// Created by mojtaba on 3/29/24.
//
#ifndef COMPUTATIONALGEOMETRY_GEOUTILS_H
#define COMPUTATIONALGEOMETRY_GEOUTILS_H

#include "../Primitive/Point.h"
#include "../Base/Core.h"
#include "../Primitive/Polygon.h"
#include "../Primitive/Line.h"

namespace CG {
    double areaTriangle2D(const Point2D &a, const Point2D &b, const Point2D &c);

    double areaTriangle3D(const Point3D& a, const Point3D& b, const Point3D& c);

    int orientation2D(const Point2D &a, const Point2D &b, const Point2D &c);

    int orientation3D(const Point3D& a, const Point3D& b, const Point3D& c);

    bool collinear(const Vector3f &a, const Vector3f &b);

    bool collinear(const Point3D &a, const Point3D &b, const Point3D &c);

    bool coplanar(const Point3D &a, const Point3D &b, const Point3D &c, const Point3D &d);

    bool coplanar(const Point3D &a, const Point3D &b, const Point3D &c);

    bool isDiagonal(const Vertex2D *v1, const Vertex2D *v2, PolygonS2D *poly = nullptr);

    bool left(const Point3D& a, const Point3D& b, const Point3D& c);

    bool left(const Point2D& a, const Point2D& b, const Point2D& c);

    bool left(const Line2dStd& l, const Point2D& p);

    bool left(const Line2d& l, const Point2D& p);

    bool right(const Point3D& a, const Point3D& b, const Point3D& c);

    bool leftOrBeyond(const Point2D& a, const Point2D& b, const Point2D& c);

    bool leftOrBeyond(const Point3D& a, const Point3D& b, const Point3D& c);

    bool leftOrBetween(const Point3D& a, const Point3D& b, const Point3D& c);

}
#endif //COMPUTATIONALGEOMETRY_GEOUTILS_H