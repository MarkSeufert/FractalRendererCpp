# Add the ColoringScheme and Fractal include folders
include_directories(${CMAKE_SOURCE_DIR}/ColoringSchemes/include)
include_directories(${CMAKE_SOURCE_DIR}/Fractals/include)

# Link the Renderer library
link_libraries(Renderer_library)

# Add source to this project's executable
add_executable (MandelbrotViewer "MandelbrotViewer.cpp")
