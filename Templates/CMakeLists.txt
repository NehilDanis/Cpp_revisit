project(template)

add_executable(template src/main.cpp)

install(TARGETS template RUNTIME DESTINATION bin)