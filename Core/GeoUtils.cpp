//
// Created by mojtaba on 3/29/24.
//

#include "GeoUtils.h"
#include "Base/Core.h"
#include "Intersection.h"

double CG::areaTriangle2D(const Point2D &a, const Point2D &b, const Point2D &c) {
    auto AB = b - a;
    auto AC = c -  a;
    auto result = crossProduct2D(AB, AC);
    return result/2;
}


int CG::orientation2D(const CG::Point2D &a, const CG::Point2D &b, const CG::Point2D &c) {
    auto area = areaTriangle2D(a, b, c);

    if (area > 0 && area < TOLERANCE)
        area = 0;
    if (area < 0 && area > TOLERANCE)
        area = 0;

    Vector2f ab = b - a;
    Vector2f ac = c - a;

    if (area > 0)
        return LEFT;
    if(area < 0)
        return RIGHT;

    if((ab[X]*ac[X] < 0) || (ab[Y] * ac[Y] < 0))
        return BEHIND;

    if(ab.magnitude() < ac.magnitude())
        return BEYOND;

    if (a == c)
        return ORIGIN;

    if (b == c)
        return DESTINATION;

    return BETWEEN;
}

int CG::orientation3D(const Point3D& a, const Point3D& b, const Point3D& c)
{
    double area = areaTriangle3D(a, b, c);

    if (area > 0 && area < TOLERANCE)
        area = 0;

    if (area < 0 && area > TOLERANCE)
        area = 0;

    Point3D p1 = b - a;
    Point3D p2 = c - a;

    double p1x, p1y, p2x, p2y;

    p1x = p1[X];
    p1y = p1[Y];
    p2x = p2[X];
    p2y = p2[Y];

    if (area > 0.0)
        return LEFT;
    if (area < 0.0)
        return RIGHT;
    if ((p1x * p2x < 0.0) || (p1y * p2y < 0.0))
        return BEHIND;
    if (p1.magnitude() < p2.magnitude())
        return BEYOND;
    if (a == c)
        return ORIGIN;
    if (b == c)
        return DESTINATION;
    return BETWEEN;
}

bool CG::collinear(const CG::Vector3f &a, const CG::Vector3f &b) {
    auto v1 = a[X] * b[Y] - a[Y] * b[X];
    auto v2 = a[Y] * b[Z] - a[Z] * b[Y];
    auto v3 = a[Z] * b[Z] - a[Z] * b[X];
    return isEqualD(v1, 0) && isEqualD(v2, 0) && isEqualD(v3, 0);
}

bool CG::collinear(const CG::Point3D &a, const CG::Point3D &b, const CG::Point3D &c) {
    auto AB = b - a;
    auto AC = c - a;
    return collinear(AB, AC);
}

bool CG::coplanar(const CG::Point3D &a, const CG::Point3D &b, const CG::Point3D &c, const CG::Point3D &d) {
    auto AB = b - a;
    auto AC = c - a;
    auto AD = d - a;
    return coplanar(AB, AC, AC);
}

bool CG::coplanar(const CG::Point3D &a, const CG::Point3D &b, const CG::Point3D &c) {
    float value = scalarTripleProduct(a, b, c);
    return isEqualD(value, 0);
}


bool CG::left(const Point2D& a, const Point2D& b, const Point2D& c)
{
    return orientation2D(a, b, c) == RELATIVE_POSITION::LEFT;
}

bool CG::left(const Line2d& l, const Point2D& p)
{
    auto line_normal = l.normal();
    auto value = dotProduct(line_normal, p);
    auto d = dotProduct(line_normal, l.point());
    return (dotProduct(line_normal, p) - d) >= 0;
}

bool CG::right(const Point3D& a, const Point3D& b, const Point3D& c)
{
    return orientation3D(a, b, c) == RELATIVE_POSITION::RIGHT;
}

bool CG::leftOrBeyond(const Point2D& a, const Point2D& b, const Point2D& c)
{
    int position = orientation2D(a, b, c);
    return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}

bool CG::leftOrBeyond(const Point3D& a, const Point3D& b, const Point3D& c)
{
    int position = orientation3D(a, b, c);
    return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BEYOND);
}

bool CG::leftOrBetween(const Point3D& a, const Point3D& b, const Point3D& c)
{
    int position = orientation3D(a, b, c);
    return (position == RELATIVE_POSITION::LEFT || position == RELATIVE_POSITION::BETWEEN);
}

static bool interiorCheck(const Vertex2D* v1, const Vertex2D* v2)
{
    if (CG::leftOrBeyond(v1->point, v1->next->point, v1->prev->point)) {
        return CG::left(v1->point, v2->point, v1->prev->point) &&
        CG::left(v2->point, v1->point, v1->next->point);
    }
    return !(CG::leftOrBeyond(v1->point, v2->point, v1->next->point) &&
    CG::leftOrBeyond(v2->point, v1->point, v1->prev->point));
}

bool CG::isDiagonal(const Vertex2D *v1, const Vertex2D *v2, PolygonS2D *poly) {
    bool prospect = true;
    std::vector<Vertex2D*> vertices;

    if(poly)
        vertices = poly->getVertices();
    else{
        auto vertex_ptr = v1->next;
        vertices.push_back((Vertex2D*)v1);
        while (vertex_ptr != v1){
            vertices.push_back(vertex_ptr);
            vertex_ptr = vertex_ptr->next;
        }
    }

    Vertex2D  *current, *next;
    current = vertices[0];
    do {
        next = current->next;
        if (current != v1 && next != v1 && current != v2 && next != v2
        && CG::intersect(v1->point, v2->point, current->point, next->point)) {
            prospect = false;
            break;
        }
        current = next;
    } while (current != vertices[0]);
    return prospect && interiorCheck(v1, v2) && interiorCheck(v2, v1);
}
