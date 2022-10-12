project(strategyPattern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

add_executable(strategyPattern ${SOURCES})

install(TARGETS strategyPattern RUNTIME DESTINATION bin)