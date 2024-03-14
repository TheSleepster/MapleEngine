cmake_minimum_required(VERSION 3.27)

project(Maple)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file (GLOB test_SRC
    "*.h"
    "*.hpp"
    "*.cpp"
    "*.c"
)

add_executable(Maple ${test_SRC} "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/src/glad.c")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(FLECS_LIBRARY "C:/Program Files (x86)/flecs/lib/flecs_static.lib")

set(CGLM_LIBRARY "C:/Users/jal4dsox/lib/cglm/build/cglm.lib")
set(CGLM_INCLUDE_DIR "C:/Users/jal4dsox/lib/cglm/include/cglm")

set(GLFW_LIBRARY "C:/Program Files (x86)/GLFW/lib/glfw3.lib")
set(GLFW_INCLUDE_DIR "C:/Program Files (x86)/GLFW/include/GLFW")

target_include_directories(Maple
    PUBLIC ${FLECS_INCLUDE_DIRS}
    PUBLIC ${GLFW_INCLUDE_DIR}
    PRIVATE ${CGLM_INCLUDE_DIR}
)

target_link_libraries(Maple PUBLIC ${FLECS_LIBRARY} ${GLFW_LIBRARY} PRIVATE ${CGLM_LIBRARY})

include_directories(
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/include"
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/sokol"
    SYSTEM "C:/Program Files (x86)/flecs/include"
)

link_directories(
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/include"
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/sokol"
    SYSTEM "C:/Program Files (x86)/flecs/include"
)
