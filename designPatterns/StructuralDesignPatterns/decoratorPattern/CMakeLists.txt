project(decoratorPattern)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_DIR include)
set(HEADER_FILES ${HEADER_DIR}/decorator.hpp)

set(SOURCE_DIR src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

add_executable(decoratorPattern ${SOURCES} ${HEADER_FILES})

install(TARGETS decoratorPattern RUNTIME DESTINATION bin)