//
// Created by mojtaba on 3/29/24.
//
#pragma once

#include "../Base/Vector.h"

#ifndef COMPUTATIONALGEOMETRY_LINE_H
#define COMPUTATIONALGEOMETRY_LINE_H

#endif //COMPUTATIONALGEOMETRY_LINE_H

namespace CG{
    template <class coordinate_type, size_t dim=DIM3>
    class Line {

        Vector<coordinate_type, dim> point;
        Vector<coordinate_type, dim> dir;

    public:
        Line() = default;
        Line(Vector<coordinate_type, dim> &p1, Vector<coordinate_type, dim> &p2) {
            dir = p2 - p1;
            point = p1;
        }

        Vector<coordinate_type, dim> getPoint();

        Vector<coordinate_type, dim> getDir();


    };

    template<class coordinate_type, size_t dim>
    inline Vector<coordinate_type, dim> Line<coordinate_type, dim>::getDir() {
        return dir;
    }

    template<class coordinate_type, size_t dim>
    inline Vector<coordinate_type, dim> Line<coordinate_type, dim>::getPoint() {
        return point;
    }
}