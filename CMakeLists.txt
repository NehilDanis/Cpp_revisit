cmake_minimum_required(VERSION 3.23)
project(cpp_revisit)

set(CMAKE_C_COMPILER /usr/bin/x86_64-linux-gnu-gcc-11 CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++-11 CACHE PATH "" FORCE)

add_subdirectory(Templates)
add_subdirectory(designPatterns/StructuralDesignPatterns/builderPattern)