project(templatedMethodPattern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

add_executable(templatedMethodPattern ${SOURCES})

install(TARGETS templatedMethodPattern RUNTIME DESTINATION bin)