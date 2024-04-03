cmake_minimum_required(VERSION 3.27)
project(ComputationalGeometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputationalGeometry
        Core/Base/Vector.h
        Core/Base/Core.h
        Core/Base/Vector.cpp
        Core/GeoUtils.h
        Core/Primitive/Point.h
        Core/GeoUtils.cpp
        Core/Primitive/Line.h
        Core/Primitive/Plane.h
        Core/Intersection.h
        Core/Intersection.cpp
        Core/Angle.h
        Core/Angle.cpp
        Core/Distance.h
        Core/Distance.cpp
        Core/Primitive/Polygon.h
        Core/Primitive/Line.cpp
        Core/Primitive/Polygon.cpp
        Triangulation.cpp
        Triangulation.h
)
