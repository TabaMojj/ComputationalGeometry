cmake_minimum_required(VERSION 3.27)
project(ComputationalGeometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputationalGeometry
        Base/Vector.h
        Base/Core.h
        Base/Vector.cpp
        Base/GeoUtils.h
        Primitive/Point.h
        Base/GeoUtils.cpp
)
