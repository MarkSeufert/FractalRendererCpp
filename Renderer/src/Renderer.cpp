#include "Renderer/Renderer.h"

#include <thread>
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

bool Renderer::Draw()
{
	// Create numThreads_ to calculate the mandelbrot set in parallel
	thread* fractalThreads = new thread[numThreads_];

	// Spawn the threads with parameters corresponding to different sections of the fractal
	for (int i = 0; i < numThreads_; i++)
	{
		fractalThreads[i] = std::thread(&Renderer::ComputeFractalSegment, this, i);
	}

	// Wait for all the threads to finish computing
	for (size_t i = 0; i < numThreads_; i++)
		fractalThreads[i].join();

	// Set up the OpenGL screen to world mapping
	glLoadIdentity();
	glOrtho(0, windowWidth_, windowHeight_, 0, 0, 1);
	glPointSize(1); //Set the size of the pixel we are drawing to 1
	glBegin(GL_POINTS);

	// Iterate through all the points on the screen
	for (int x = 0; x < windowWidth_; x++)
	{
		for (int y = 0; y < windowHeight_; y++)
		{
			// Get the RGB to color this point
			double r, g, b;
			colorScheme_->GetColor(fractalMemory_[x][y], r, g, b);

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

void Renderer::ComputeFractalSegment(int offset)
{
	// Calculate the min real/imaginary and max real/imaginary points to display on the screen
	double minReal = centerReal_ - widthReal_ / 2;
	double minImaginary = centerImaginary_ - (widthReal_ * aspectRatio_ / 2);

	// Calculate the distance between consecutive real/imaginary pixels
	double realIncrement = widthReal_ / windowWidth_;
	double imaginaryIncrement = widthReal_ * aspectRatio_ / windowHeight_;

	// Iterate through all the points on the screen
	for (int x = offset; x < windowWidth_; x += numThreads_)
	{
		for (int y = 0; y < windowHeight_; y++)
		{
			// Get the mandelbrot result at this point
			fractalMemory_[x][y] = fractal_->Evaluate(minReal + x * realIncrement, minImaginary + y * imaginaryIncrement);
		}
	}
}