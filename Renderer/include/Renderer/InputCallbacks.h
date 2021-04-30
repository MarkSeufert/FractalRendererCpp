#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <functional>

/*
Global variables to store information from the callbacks.
*/
static bool mouseButtonDown_ = false; // Whether the left mouse button is currently pressed down
static bool mouseButtonDownR_ = false; // Whether the right mouse button is currently pressed down
static double scrollWheel_ = 0; // The value read from the mouse's scrollwheel
static char keyboardInput_ = 0; // Any key read from the keyboard

/*
This class contains the input callbacks, that is used by the renderer.cpp file. The input callbacks are defined using 
static functions, and it stores the information from the callbacks inside the three static members above.
*/
class InputCallbacks
{
public:
	/*
	The callback function for when the mouse button is clicked
	*/
	static void MouseCallback(GLFWwindow* window, int button, int action, int mods)
	{
		//If the left click has been pressed
		if (button == GLFW_MOUSE_BUTTON_LEFT)
		{
			if (action == GLFW_PRESS)
			{
				mouseButtonDown_ = true;
			}
			else if (action == GLFW_RELEASE)
			{
				mouseButtonDown_ = false;
			}
		}

		//If the right click has been pressed
		if (button == GLFW_MOUSE_BUTTON_RIGHT)
		{
			if (action == GLFW_PRESS)
			{
				mouseButtonDownR_ = true;
			}
			else if (action == GLFW_RELEASE)
			{
				mouseButtonDownR_ = false;
			}
		}
	}

	/*
	The callback function for when the scrollwheel is used
	*/
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		scrollWheel_ = yoffset;
	}

	/*
	The callback function for when a keyboard key is pressed
	*/
	static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			keyboardInput_ = (char)key;
	}
};