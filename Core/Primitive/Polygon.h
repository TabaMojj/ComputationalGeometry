//
// Created by mojtaba on 4/2/24.
//
#pragma once
#ifndef COMPUTATIONALGEOMETRY_POLYGON_H
#define COMPUTATIONALGEOMETRY_POLYGON_H

#include "../Base/Vector.h"
#include "Point.h"
#include <list>
#include <vector>

template<class T, size_t dim>
struct Vertex {
    CG::Vector<T, dim> point;
    Vertex *next = nullptr;
    Vertex *prev = nullptr;
    bool is_ear = false;
    bool is_processed = false;

    Vertex(CG::Vector<T, dim> &_point, Vertex<T, dim> *_next, Vertex<T, dim> *_prev)
    :point(_point), next(_next), prev(_prev){

    }
};

typedef Vertex<float, DIM2> Vertex2D;
typedef Vertex<float, DIM3> Vertex3D;

template<class T, size_t dim = DIM3>
class Polygon {
    std::vector<Vertex<T, dim>*> vertex_list;
public:
    Polygon(std::list<CG::Vector<T, dim>> &points) {
        const int size = points.size();

        if (size < 3){
            std::cout << "Not enough points to construct a polygon\n";
        }

        for (auto _point : points) {
            vertex_list.push_back(new Vertex(_point));
        }

        for (size_t i = 0; i < size; i++){
            vertex_list[i].next = &vertex_list[(i+1) % size];
            if(i != 0)
                vertex_list[i].prev = &vertex_list[i - 1];
            else
                vertex_list[i].prev = &vertex_list[size - 1];
        }


    }

    std::vector<Vertex<T, dim>*> getVertices() {
        return vertex_list;
    }
};

typedef Polygon<float, DIM3> PolygonS3D;
typedef Polygon<float, DIM2> PolygonS2D;

template<class T, size_t dim>
struct Edge {
    Vertex<T, dim> v1;
    Vertex<T, dim> v2;

    Edge(Vertex<T, dim> _v1, Vertex<T, dim> _v2): v1(_v1), v2(_v2) {

    }
};

typedef Edge<float, DIM2> Edge2D;
#endif //COMPUTATIONALGEOMETRY_POLYGON_H
