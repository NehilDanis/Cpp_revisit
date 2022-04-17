project(template)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_DIR includes)
set(HEADER_FILES ${HEADER_DIR}/Template.hpp)

add_executable(template src/main.cpp ${HEADER_FILES})

install(TARGETS template RUNTIME DESTINATION bin)