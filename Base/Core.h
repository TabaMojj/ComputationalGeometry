//
// Created by mojtaba on 3/29/24.
//

#pragma once

#include <cmath>

#ifndef COMPUTATIONALGEOMETRY_CORE_H
#define COMPUTATIONALGEOMETRY_CORE_H

#endif //COMPUTATIONALGEOMETRY_CORE_H

namespace CG {

    #define TOLERANCE 0.0000001

    static bool isEqualID(double x, double y){
        return fabs(x-y) < TOLERANCE;
    }

    enum RELATIVE_POSITION {
        LEFT, RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION
    };

    static bool _xor(bool x, bool y) {
        return x ^ y;
    }

}



