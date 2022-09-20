project(compositePattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

add_executable(compositePattern ${SOURCES})

install(TARGETS compositePattern RUNTIME DESTINATION bin)