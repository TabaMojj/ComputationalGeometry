//
// Created by mojtaba on 3/30/24.
//

#include "Angle.h"

template <class T, size_t dim>
static double getAngle(CG::Vector<T, dim> v1, CG::Vector<T, dim> v2){
    auto dot = dotProduct(v1, v2);
    auto theta = acos(fabs(dot));
    return CG::RadianceToDegrees(theta);
}
double CG::AngleLines2D(const CG::Line2d &l1, const CG::Line2d &l2) {
    return getAngle(l1.getDir(), l2.getDir());
}

double CG::AngleLines3D(const CG::Line3d &l1, const CG::Line3d &l2) {
    return getAngle(l1.getDir(), l2.getDir());
}

double CG::AngleLinePlane(const CG::Line3d &l1, const CG::Planef &p) {
    auto angle = getAngle(l1.getDir(), p.getNormal());
    return 90 - angle;
}

double CG::AnglePlanes(const CG::Planef &p1, const CG::Planef &p2) {
    return getAngle(p1.getNormal(), p2.getNormal());
}