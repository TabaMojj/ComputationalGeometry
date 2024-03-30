//
// Created by mojtaba on 3/29/24.
//
#pragma once

#include "../Base/Vector.h"
#include "Point.h"

#ifndef COMPUTATIONALGEOMETRY_PLANE_H
#define COMPUTATIONALGEOMETRY_PLANE_H

#endif //COMPUTATIONALGEOMETRY_PLANE_H

namespace CG {
    template<class coordinate_type>
    class Plane {
        Vector3f normal;
        float d = 0;

    public:
        Plane() = default;

        Plane(Vector3f &_normal, float _constant):normal(_normal), d(_constant){
            normal.normalize();
        }

        Plane(Point3d &_p1, Point3d &_p2, Point3d &_p3) {
            auto v12 = _p2 - _p1;
            auto v13 = _p3 - _p1;
            normal = crossProduct3D(v12, v13);
            normal.normalize();
            d = dotProduct(normal, _p1);
        }

        Vector3f getNormal() const {
            return normal;
        }

        float getD() const {
            return d;
        }
    };
    typedef Plane<float> Planef;
}