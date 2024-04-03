//
// Created by mojtaba on 3/29/24.
//

#pragma once
#ifndef COMPUTATIONALGEOMETRY_CORE_H
#define COMPUTATIONALGEOMETRY_CORE_H

#include <cmath>

namespace CG {

#define TOLERANCE 0.0000001

    static bool isEqualD(double x, double y){
        return fabs(x-y) < TOLERANCE;
    }

    enum RELATIVE_POSITION {
        LEFT, RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION
    };

    static bool _xor(bool x, bool y) {
        return x ^ y;
    }

    static double RadianceToDegrees(double radiance) {
        return radiance * 360 / (2 * M_PI);
    }

}

#endif //COMPUTATIONALGEOMETRY_CORE_H