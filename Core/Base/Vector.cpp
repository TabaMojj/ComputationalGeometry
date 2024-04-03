#include "Vector.h"


CG::Vector3f CG::crossProduct3D(Vector3f a, Vector3f b)
{
    float x_, y_, z_;
    x_ = a[Y] * b[Z] - b[Y] * a[Z];
    y_ = -( b[Z] * a[X] - a[Z] * b[X]);
    z_ = a[X] * b[Y] - b[X] * a[Y];

    return Vector3f(x_, y_, z_);
}

float CG::crossProduct2D(CG::Vector2f a, CG::Vector2f b)
{
    return 0.0f;
}

float CG::scalarTripleProduct(Vector3f a, Vector3f b, Vector3f c)
{
    Vector3f b_cross_c = crossProduct3D(b, c);
    float value = dotProduct(a, b_cross_c);
    return value;
}

bool CG::orthogonal(Vector3f a, Vector3f b)
{
    float value = dotProduct(a, b);
    return CG::isEqualD(value, 0.0);
}

CG::Vector2f CG::perpendicular(Vector2f& vec)
{
    return Vector2f( vec[Y], -vec[X]);
}