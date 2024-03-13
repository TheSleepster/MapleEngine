cmake_minimum_required(VERSION 3.27)

project(Maple)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file (GLOB test_SRC
    "*.c"
    "*.cpp"
    "*.h"
    "*.hpp"
)

add_executable(Maple ${test_SRC} "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/src/glad.c")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SDL_IMAGE_LIBRARY "C:/Program Files(x86)/SDL3_Image")
set(SDL_IMAGE_INCLUDE_DIR "C:/Program Files(x86)/SDL3_Image/include")

set(CGLM_LIBRARY "C:/Users/jal4dsox/lib/cglm/build/cglm.lib")
set(CGLM_INCLUDE_DIR "C:/Users/jal4dsox/lib/cglm/include/cglm")

set(FLECS_LIBRARY "C:/Program Files (x86)/flecs/lib/flecs_static.lib")
set(FLECS_INCLUDE_DIR "C:/Program Files (x86)/flecs/include")

set(SOKOL_INCLUDE_DIR "C:/Users/jal4dsox/C++Stuff/Maple/include/sokol")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

target_include_directories(Maple
    PUBLIC ${SDL3_INCLUDE_DIRS}
    PUBLIC ${SDL3IMAGE_INCLUDE_DIRS}
    PUBLIC ${FLECS_INCLUDE_DIR}
    PRIVATE ${CGLM_INCLUDE_DIR}
)

target_link_libraries(Maple PUBLIC ${SDL3_LIBRARIES} SDL3_image::SDL3_image ${FLECS_LIBRARY}  PRIVATE ${CGLM_LIBRARY})

include_directories(
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/include"
    SYSTEM "C:/Users/jal4dsox/C++Stuff/Maple/include/sokol"
)

link_directories(
    "C:/Users/jal4dsox/C++Stuff/Maple/include/glad/include"
    "C:/Users/jal4dsox/C++Stuff/Maple/include/sokol"
)
