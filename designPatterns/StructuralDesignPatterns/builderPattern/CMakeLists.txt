project(builderPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_DIR include)
set(HEADER_FILES ${HEADER_DIR}/Person.h)

set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp
            ${SOURCE_DIR}/Person.cpp)

add_executable(builderPattern ${SOURCES} ${HEADER_FILES})

install(TARGETS builderPattern RUNTIME DESTINATION bin)