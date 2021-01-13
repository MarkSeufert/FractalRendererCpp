#include "Renderer/Renderer.h"

#include <iostream>
using namespace std;

Renderer::Renderer(int windowWidth, int windowHeight, const char* name)
{
	// Update the private members based off the windowWidth and windowHeight
	windowWidth_ = windowWidth;
	windowHeight_ = windowHeight;
	aspectRatio_ = (double)windowHeight / (double)windowWidth;

	// Initialize memory for the fractal
	fractalMemory_ = new double* [windowWidth_];
	for (int i = 0; i < windowWidth_; i++)
	{
		fractalMemory_[i] = new double[windowHeight_];
	}

	// Initialize GLFW
	if (!glfwInit()) {
		cout << "GLFW was not initialized properly" << endl;
		return;
	}

	// Create a window with the specified width and height
	window_ = glfwCreateWindow(windowWidth, windowHeight, name, nullptr, nullptr);
	if (!window_)
	{
		cout << "Window was not created properly" << endl;
		glfwTerminate();
		return;
	}

	// Set the min and max sizes for this window
	// TODO: make the window resizable
	glfwSetWindowSizeLimits(window_, windowWidth_, windowHeight_, windowWidth_, windowHeight_);

	// Make this window appear in front of all other windows
	glfwMakeContextCurrent(window_);
}

void Renderer::SetFractal(FractalInterface* fractal)
{
	fractal_ = fractal;
}

void Renderer::SetColorScheme(ColoringInterface* colorScheme)
{
	colorScheme_ = colorScheme;
}

bool Renderer::Draw()
{
	// Calculate the min real/imaginary and max real/imaginary points to display on the screen
	double minReal = centerReal_ - widthReal_ / 2;
	double maxReal = centerReal_ + widthReal_ / 2;
	double minImaginary = centerImaginary_ - (widthReal_ * aspectRatio_ / 2);
	double maxImaginary = centerImaginary_ + (widthReal_ * aspectRatio_ / 2);

	// Calculate the increment distance between consecutive real/imaginary pixels
	double realIncrement = (maxReal - minReal) / windowWidth_;
	double imaginaryIncrement = (maxImaginary - minImaginary) / windowHeight_;

	// Set up the OpenGL screen to world mapping
	glLoadIdentity();
	glOrtho(minReal, maxReal, maxImaginary, minImaginary, 0, 1);
	glColor3f(0.8f, 0.8f, 0.8f); //Set the color of the line to grey
	glPointSize(1); //Set the size of the pixel we are drawing to 1
	glBegin(GL_POINTS);

	// Iterate through all the points on the screen
	for (double x = minReal; x < maxReal; x += realIncrement)
	{
		for (double y = minImaginary; y < maxImaginary; y += imaginaryIncrement)
		{
			// Get the mandelbrot result at this point
			double result = fractal_->Evaluate(x, y);
			// Get the RGB to color this point
			double r, g, b;
			colorScheme_->GetColor(result, r, g, b);

			glColor3f(r, g, b);
			glVertex2f(x, y);
		}
	}
	glEnd();
	
	// Double buffer
	glfwSwapBuffers(window_);

	//Poll for events, required to not stall the CPU
	glfwPollEvents();

	// Check if the user clicked the close window button
	if (glfwWindowShouldClose(window_))
		return false;
	return true;
}