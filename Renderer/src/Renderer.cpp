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
	smallestValueFromThread_ = new double[numThreads_];

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

	// Set up the OpenGL screen to world mapping
	glLoadIdentity();
	glOrtho(0, windowWidth_, windowHeight_, 0, 0, 1);
	glPointSize(1); //Set the size of the pixel we are drawing to 1

	// Set up the callbacks for user inputs
	glfwSetMouseButtonCallback(window_, UserInputs::MouseCallback);
	glfwSetScrollCallback(window_, UserInputs::ScrollCallback);
	glfwSetKeyCallback(window_, UserInputs::KeyboardCallback);
}

bool Renderer::Draw()
{
	/*
	Create numThreads_ to calculate the fractal in parallel
	*/
	// Spawn the threads with parameters corresponding to different sections of the fractal
	thread* fractalThreads = new thread[numThreads_];
	for (int i = 0; i < numThreads_; i++)
	{
		fractalThreads[i] = std::thread(&Renderer::ComputeFractalSegment, this, i);
	}

	// Wait for all the threads to finish computing
	for (size_t i = 0; i < numThreads_; i++)
		fractalThreads[i].join();

	/*
	Get the smallest value found from the threads
	*/
	double smallest = 1;
	for (int i = 0; i < numThreads_; i++)
	{
		if (smallestValueFromThread_[i] < smallest)
			smallest = smallestValueFromThread_[i];
	}
	// Calculate the amount to scale each value by
	double scale = 1.0 / (1.0 - smallest);


	/*
	Render the results from the threads to the screen
	*/
	glBegin(GL_POINTS);
	double r, g, b;
	for (int x = 0; x < windowWidth_; x++)
	{
		for (int y = 0; y < windowHeight_; y++)
		{
			// Scale the point using the previously found smallest and scale, then get the RGB to color it
			colorScheme_->GetColor((fractalMemory_[x][y] - smallest) * scale, r, g, b);

			glColor3f(r, g, b);
			glVertex2f(x, y);
		}
	}
	glEnd();
	
	// Double buffer
	glfwSwapBuffers(window_);

	//Poll for events, required to not stall the CPU
	glfwPollEvents();

	/*
	Handle inputs from the user
	*/
	// Handle moving the center of the fractal when the mouse button is down
	static double oldMouseX, oldMouseY;
	double mouseX, mouseY;
	glfwGetCursorPos(window_, &mouseX, &mouseY);
	if (UserInputs::IsMouseButtonDown())
	{
		// Update the center of the fractal from the mouse's x diff and y diff
		double changeInPositionX = (mouseX - oldMouseX) / windowWidth_;
		double changeInPositionY = (mouseY - oldMouseY) / windowHeight_;

		centerReal_ -= changeInPositionX * widthReal_;
		centerImaginary_ -= changeInPositionY * widthReal_ * aspectRatio_;
	}
	oldMouseX = mouseX;
	oldMouseY = mouseY;

	// Handle scrolling in and out of the fractal
	double zoomAmount = 1 - (UserInputs::ScrollWheelValue() * 0.1);
	widthReal_ *= zoomAmount;

	// Handle 'q' and 'w' inputs for increasing/decreasing iterations
	char keyboard = UserInputs::GetKeyboardValue();
	static double iterationMultiplier = 1;
	if (keyboard == 'Q')
		iterationMultiplier *= 1.25;
	if (keyboard == 'W')
		iterationMultiplier /= 1.25;
	fractal_->SetMaxIterations(iterationMultiplier * 15 * pow(log10(windowWidth_ / widthReal_), 1.8));

	// Handle 'r' input for resetting the fractal
	if (keyboard == 'R')
	{
		centerReal_ = 0;
		centerImaginary_ = 0;
		widthReal_ = 4;

		iterationMultiplier = 1;
	}
	
	/*
	Return true or false based off whether the user clicked the close window button
	*/
	if (glfwWindowShouldClose(window_))
		return false;
	return true;
}

void Renderer::ComputeFractalSegment(int offset)
{
	// Calculate the min real/imaginary points to display on the screen
	double minReal = centerReal_ - widthReal_ / 2;
	double minImaginary = centerImaginary_ - (widthReal_ * aspectRatio_ / 2);

	// Calculate the distance between consecutive real/imaginary pixels
	double realIncrement = widthReal_ / windowWidth_;
	double imaginaryIncrement = widthReal_ * aspectRatio_ / windowHeight_;

	// Iterate through all the points on the screen
	double result; // Used to store intermediate result
	double smallestValue = 1; // Used to store the smallest value found
	for (int x = offset; x < windowWidth_; x += numThreads_)
	{
		for (int y = 0; y < windowHeight_; y++)
		{
			// Get the mandelbrot result at this point
			result = fractal_->Evaluate(minReal + x * realIncrement, minImaginary + y * imaginaryIncrement);
			fractalMemory_[x][y] = result;
			if (result < smallestValue)
				smallestValue = result;
		}
	}

	// Store the smallest value found inside memory
	smallestValueFromThread_[offset] = smallestValue;
}