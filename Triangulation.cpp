//
// Created by mojtaba on 4/3/24.
//

#include "Core/Primitive/Polygon.h"
#include "Core/GeoUtils.h"
using namespace CG;

static void initialize_ear_status(PolygonS2D polygon)
{
    Vertex2D *v0, *v1, *v2;
    auto vertices = polygon.getVertices();
    v1 = vertices[0];

    do {
        v0 = v1->prev;
        v2 = v1->next;
        if(isConvex(v0, v1, v2))
            v1->is_ear = isDiagonal(v0, v2);
        v1 = v1->next;
    } while (v1 != vertices[0]);

}

void Triangulate_earclipping(PolygonS2D* poly, std::vector<Edge2D>& edge_list)
{
    initialize_ear_status(poly);

    auto vertex_list = poly->getVertices();
    int no_vertex_to_process = vertex_list.size();

    Vertex2D* v0, *v1, *v2, *v3, *v4;

    while (no_vertex_to_process < 3){

        for(auto & i : vertex_list)
        {
            v2 = i;
            if(v2->is_ear && !v2->is_processed)
            {
                v3 = v2->next;
                v4 = v3->next;
                v1 = v2->prev;
                v0 = v1->prev;
                edge_list.push_back(Edge2D(*v1, *v3));
                v2->is_processed = true;
                v1->next = v3;
                v3->prev = v1;
                if(isConvex(v1->prev, v1, v1->next))
                    v1->is_ear = isDiagonal(v0, v3);
                if(isConvex(v3->prev, v3, v3->next))
                    v3->is_ear = isDiagonal(v1, v4);
                no_vertex_to_process--;
                if(no_vertex_to_process <= 3)
                    break;
            }
        }

    }
}