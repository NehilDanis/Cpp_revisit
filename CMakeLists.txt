cmake_minimum_required(VERSION 3.23)
project(cpp_revisit)

set(CMAKE_C_COMPILER /usr/bin/x86_64-linux-gnu-gcc-11 CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-linux-gnu-g++-11 CACHE PATH "" FORCE)

add_subdirectory(Templates)

# structural design patterns
add_subdirectory(designPatterns/StructuralDesignPatterns/bridgePattern)
add_subdirectory(designPatterns/StructuralDesignPatterns/compositePattern)
add_subdirectory(designPatterns/StructuralDesignPatterns/decoratorPattern)

#behavioral design patterns
add_subdirectory(designPatterns/BehavioralDesignPatterns/StrategyDesignPattern)