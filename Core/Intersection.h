//
// Created by mojtaba on 3/30/24.
//
#pragma once
#ifndef COMPUTATIONALGEOMETRY_INTERSECTION_H
#define COMPUTATIONALGEOMETRY_INTERSECTION_H

#include "Primitive/Point.h"
#include "Primitive/Line.h"
#include "Primitive/Plane.h"

namespace CG {

    bool intersect(CG::Line&, CG::Line&, CG::Point3D&);

    bool intersect(CG::Line2d&,CG::Line2d&, CG::Point2D&);

    bool intersect(const CG::Point2D&, const CG::Point2D&, const CG::Point2D&, const CG::Point2D&);

    bool intersect(CG::Point2D&, CG::Point2D&, CG::Point2D&, CG::Point2D&, CG::Point2D&);

    bool intersect(CG::Planef&, CG::Line&, CG::Point3D&);

    bool intersect(CG::Planef&, CG::Planef&, CG::Line&);
}

#endif //COMPUTATIONALGEOMETRY_INTERSECTION_H

