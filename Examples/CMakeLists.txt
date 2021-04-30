# Add the ColoringScheme and Fractal include folders
include_directories(${CMAKE_SOURCE_DIR}/ColoringSchemes/include)
include_directories(${CMAKE_SOURCE_DIR}/Fractals/include)

# Link the Renderer library
link_libraries(Renderer_library)

# Create an executable for each file in this folder
add_executable (MandelbrotViewer "MandelbrotViewer.cpp")
add_executable (JuliaViewer "JuliaViewer.cpp")

