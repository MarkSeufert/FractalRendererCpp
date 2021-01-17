#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

/*
Global variables to store the information from the callbacks
*/
static bool mouseButtonDown_; // Whether the left mouse button is currently pressed down
static double scrollWheel_; // The value read from the mouse's scrollwheel

/*
This class defines static functions to be used as callback functions for all user inputs.
It stores the information from the callbacks inside static methods, which can be accessed.
*/
class UserInputs
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
	}

	/*
	The callback function for when the scrollwheel is used
	*/
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		scrollWheel_ = yoffset;
	}

	/*
	Returns whether the mouse's left button is clicked
	*/
	static bool IsMouseButtonDown() { return mouseButtonDown_; }

	/*
	Returns the scrollwheel value from the mouse
	*/
	static double ScrollWheelValue() { return scrollWheel_; }

	/*
	Resets the scrollwheel value back to 0
	*/
	static void ResetScrollWheel() { scrollWheel_ = 0; }
};