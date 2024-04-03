cmake_minimum_required(VERSION 3.27)
project(ComputationalGeometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputationalGeometry
        Base/Vector.h
        Base/Core.h
        Base/Vector.cpp
        Core/GeoUtils.h
        Primitive/Point.h
        Core/GeoUtils.cpp
        Primitive/Line.h
        Primitive/Plane.h
        Core/Intersection.h
        Core/Intersection.cpp
        Core/Angle.h
        Core/Angle.cpp
        Core/Distance.h
        Core/Distance.cpp
        Primitive/Polygon.h
        Primitive/Line.cpp
        Primitive/Polygon.cpp
)
