cmake_minimum_required (VERSION 3.8)

project (MandelbrotViewer)

## Include sub-projects.
# Third-party library that simplifies OpenGL rendering
include_directories(glfw/include)
add_subdirectory (glfw)
# Rendering library that is used for rendering a fractal
include_directories(Renderer/include)
add_subdirectory (Renderer)
# Adds different coloring schemes for rendering
include_directories(ColoringSchemes/include)
# Adds the fractals available for rendering
include_directories(Fractals/include)
# Adds executable examples
add_subdirectory (Examples)
