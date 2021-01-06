# Add the ColoringScheme and Fractal include folders
include_directories(${CMAKE_SOURCE_DIR}/ColoringSchemes/include)
include_directories(${CMAKE_SOURCE_DIR}/Fractals/include)

# Add source to this project's executable
add_executable (MandelbrotViewer "MandelbrotViewer.cpp")

# Link the Renderer
target_link_libraries(MandelbrotViewer 
	Renderer_library 
	glfw
)
