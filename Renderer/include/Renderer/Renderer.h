#pragma once

#include "FractalInterface.h"
#include "ColoringInterface.h"
#include "InputCallbacks.h" // Remove this from the include folder and put into src
#include "Inputs.h"
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
	Draws the fractal to the OpenGL window and uses any mouse inputs to update the drawing.
	Returns false if the user clicked the closed window button.
	*/
	bool Draw();

	/*
	Sets the number of threads that will be used to calculate the fractal
	*/
	void SetNumberThreads(int numThreads) { numThreads_ = numThreads; }

	/*
	Returns an object that contains information about user inputs. Useful for custom input logic.
	*/
	Inputs* GetInputs() { return &userInputs_; }

private:
	// The OpenGL window
	GLFWwindow* window_;

	// The fractal to render
	FractalInterface* fractal_;

	// The coloring scheme to color the fractal with
	ColoringInterface* colorScheme_;

	// The width and height of the window, in pixels
	int windowWidth_ = 0;
	int windowHeight_ = 0;

	// The aspect ratio of the window (windowHeight_ / windowWidth_)
	double aspectRatio_;

	// The real/imaginary point that corresponds to the center of the window, by default 0 + 0i
	double centerReal_ = 0;
	double centerImaginary_ = 0;

	// The range of real values to render, by default from -2 to 2 (width of 4)
	double widthReal_ = 4;

	// The number of threads to use for computation, by default 8
	int numThreads_ = 8;

	// Memory that the threads store the fractal information inside of
	double** fractalMemory_;

	// Memory that the threads store their smallest mandelbrot value inside of 
	// (used for normalizing values between 0 and 1)
	double* smallestValueFromThread_;

	// Class used for storing all inputs received from user (ex: key presses, mouse position)
	Inputs userInputs_;

	/*
	Calculates a segment of the fractal from a thread, and saves it in fractalMemory_
	*/
	void ComputeFractalSegment(int offset);
};