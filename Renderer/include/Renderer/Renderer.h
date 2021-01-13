#pragma once

#include "FractalInterface.h"
#include "ColoringInterface.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

/*
This class defines a rendering engine used to render fractals.
The responsibilities of this class are:
	- Creating a window with a width/height
	- Loading a fractal to render + a coloring scheme
	- Rendering the fractal
	- Collecting mouse inputs to traverse
*/
class Renderer
{
public:
	/*
	Initializes the renderer and creates an OpenGL window with a given width, height, and
	optionally the window name
	*/
	Renderer(int windowWidth, int windowHeight, const char* name = "Fractal Viewer");

	/*
	Sets the fractal that will be rendered
	*/
	void SetFractal(FractalInterface* fractal);

	/*
	Sets the coloring scheme that will be used to render the fractal
	*/
	void SetColorScheme(ColoringInterface* colorScheme);

	/*
	Draws the fractal to the OpenGL window and uses any mouse inputs to update the drawing.
	Returns false if the user clicked the closed window button.
	*/
	bool Draw();

private:
	// The OpenGL window
	GLFWwindow* window_;

	// The width and height of the window, in pixels
	int windowWidth_ = 0;
	int windowHeight_ = 0;

	// The aspect ratio of the window
	double aspectRatio_;

	// The real/imaginary point that corresponds to the center of the window
	double centerReal_ = -0.5;
	double centerImaginary_ = 0;

	// The real value that corresponds to the width of the window
	double widthReal_ = 3;

	// The fractal to render
	FractalInterface* fractal_;

	// The coloring scheme to color the fractal with
	ColoringInterface* colorScheme_;

	// Memory to store the fractal information
	double** fractalMemory_;
};