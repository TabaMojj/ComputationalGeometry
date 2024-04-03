//
// Created by mojtaba on 4/3/24.
//
#pragma once
#ifndef COMPUTATIONALGEOMETRY_TRIANGULATION_H
#define COMPUTATIONALGEOMETRY_TRIANGULATION_H

#include "Core/Primitive/Polygon.h"
#include "Core/GeoUtils.h"

void Triangulate_earclipping(PolygonS2D* poly, std::vector<Edge2D>& edge_list);

#endif //COMPUTATIONALGEOMETRY_TRIANGULATION_H
