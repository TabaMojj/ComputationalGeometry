//
// Created by mojtaba on 3/29/24.
//

#pragma once

#include <cmath>

#define TOLERANCE 0.0000001

#ifndef COMPUTATIONALGEOMETRY_CORE_H
#define COMPUTATIONALGEOMETRY_CORE_H

#endif //COMPUTATIONALGEOMETRY_CORE_H


static bool isEqualID(double x, double y){
    return fabs(x-y) < TOLERANCE;
}

enum class RELATIVE_POSITION {
    LEFT, RIGHT, BEHIND, BEYOND, BETWEEN, ORIGIN, DESTINATION
};