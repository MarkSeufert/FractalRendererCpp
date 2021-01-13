add_library(Renderer_library src/Renderer.cpp)

target_link_libraries(Renderer_library
	glfw
	libglew_static
)