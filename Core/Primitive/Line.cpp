//
// Created by mojtaba on 4/3/24.
//

#include "../Base/Vector.h"
#include "Line.h"

void CG::Line::setDirection(Vector3f& _dir)
{
    dir.assign(X, _dir[X]);
    dir.assign(Y, _dir[Y]);
    dir.assign(Z, _dir[Z]);
}

void CG::Line::setPoint(Point3D& _point)
{
    point_in_line.assign(X, _point[X]);
    point_in_line.assign(Y, _point[Y]);
    point_in_line.assign(Z, _point[Z]);
}

CG::Vector3f CG::Line::direction() const
{
    return dir;
}

CG::Point3D CG::Line::point() const
{
    return point_in_line;
}

CG::Vector2f CG::Line2d::direction() const
{
    return dir;
}

CG::Point2D CG::Line2d::point() const
{
    return point_in_line;
}

CG::Vector2f CG::Line2d::normal() const
{
    return normal_vec;
}