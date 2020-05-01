cmake_minimum_required(VERSION 3.0)
project(beginning-opengl)

option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_INSTALL OFF)
add_subdirectory(lib/glfw)

add_subdirectory(lib/freetype)

include_directories(lib/glfw/include lib/glfw-window lib/glee lib/freetype/include)

add_library(glfw-window lib/glfw-window/glfwwindow.cpp lib/glfw-window/examplecallback.h)
add_library(glee lib/glee/GLee.c)

add_subdirectory(chapter_1/simple)

add_subdirectory(chapter_2/first_app)

add_subdirectory(chapter_3/draw_arrays)
add_subdirectory(chapter_3/lines)
add_subdirectory(chapter_3/pointy_example)
add_subdirectory(chapter_3/polygon_mode)
add_subdirectory(chapter_3/shared_vertices)
add_subdirectory(chapter_3/simple_line)
add_subdirectory(chapter_3/simple_point)
add_subdirectory(chapter_3/simple_triangle)

add_subdirectory(chapter_4/projection_example)
add_subdirectory(chapter_4/robot_example)
add_subdirectory(chapter_4/square_rotation)
add_subdirectory(chapter_4/square_scaling)
add_subdirectory(chapter_4/square_translation)

add_subdirectory(chapter_5/terrain_extensions_glee)
add_subdirectory(chapter_5/terrain_extensions_manual)

add_subdirectory(chapter_6/robot_kazmath_example)
add_subdirectory(chapter_6/terrain_glsl)

add_subdirectory(chapter_7/terrain_simple_texture)
add_subdirectory(chapter_7/texture_wrap_modes)

add_subdirectory(chapter_8/blending)
add_subdirectory(chapter_8/multiple_lights)
add_subdirectory(chapter_8/point_light)
add_subdirectory(chapter_8/point_light_per_pixel)
add_subdirectory(chapter_8/simple_fog)
add_subdirectory(chapter_8/spot_light)
add_subdirectory(chapter_8/terrain_lighting)

add_subdirectory(chapter_9/alpha_test)
add_subdirectory(chapter_9/cube_mapping)
add_subdirectory(chapter_9/multitexture)

add_subdirectory(chapter_10/frustum_culling)

add_subdirectory(chapter_11/freetype_fonts)
add_subdirectory(chapter_11/texturemapped_fonts)

add_subdirectory(chapter_12/stencil_reflection)

add_subdirectory(chapter_13/ogro_invasion)
