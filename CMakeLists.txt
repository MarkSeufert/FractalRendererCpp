cmake_minimum_required (VERSION 3.8)

project (FractalRenderer)

## Include sub-projects.
# Third-party libraries that simplifies OpenGL rendering
include_directories(glfw/include)
add_subdirectory (glfw)
include_directories(glew/include)
add_subdirectory(glew)
# Rendering library that is used for rendering a fractal
include_directories(Renderer/include)
add_subdirectory (Renderer)
# Adds different coloring schemes for rendering
include_directories(ColoringSchemes/include)
# Adds the fractals available for rendering
include_directories(Fractals/include)
# Adds executable examples
add_subdirectory (Examples)
