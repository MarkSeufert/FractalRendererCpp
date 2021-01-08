#include "Renderer/Renderer.h"

#include <iostream>
using namespace std;

Renderer::Renderer(int windowWidth, int windowHeight, const char* name)
{
	// Update the private members based off the windowWidth and windowHeight
	windowWidth_ = windowWidth;
	windowHeight_ = windowHeight;
	aspectRatio_ = (double)windowWidth / (double)windowHeight;

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

void Renderer::Draw()
{
	//TODO: Render the fractal

	//Poll for events
	glfwPollEvents();
}