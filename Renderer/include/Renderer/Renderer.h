#pragma once

#include "FractalInterface.h"
#include "ColoringInterface.h"
#include "UserInputs.h"
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
	void SetFractal(FractalInterface* fractal) { fractal_ = fractal; }

	/*
	Sets the coloring scheme that will be used to render the fractal
	*/
	void SetColorScheme(ColoringInterface* colorScheme) { colorScheme_ = colorScheme; }

	/*
	Sets the number of threads that will be used to calculate the fractal
	*/
	void SetNumberThreads(int numThreads) { numThreads_ = numThreads; }

	/*
	Draws the fractal to the OpenGL window and uses any mouse inputs to update the drawing.
	Returns false if the user clicked the closed window button.
	*/
	bool Draw();

private:
	/*
	Calculates a segment of the fractal, and saves it in fractalMemory_
	*/
	void ComputeFractalSegment(int offset);

	// The OpenGL window
	GLFWwindow* window_;

	// The width and height of the window, in pixels
	int windowWidth_ = 0;
	int windowHeight_ = 0;

	// The aspect ratio of the window
	double aspectRatio_;

	// The real/imaginary point that corresponds to the center of the window
	double centerReal_ = 0;
	double centerImaginary_ = 0;

	// The real value that corresponds to the width of the window, by default 4
	double widthReal_ = 4;

	// The fractal to render
	FractalInterface* fractal_;

	// The coloring scheme to color the fractal with
	ColoringInterface* colorScheme_;

	// Memory used by the threads to store the fractal information
	double** fractalMemory_;

	// The number of threads to use for computation, by default 8
	int numThreads_ = 8;
};