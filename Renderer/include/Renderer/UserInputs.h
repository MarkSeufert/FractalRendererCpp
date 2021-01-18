#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

/*
Global variables to store the information from the callbacks
*/
static bool mouseButtonDown_ = false; // Whether the left mouse button is currently pressed down
static double scrollWheel_ = 0; // The value read from the mouse's scrollwheel
static char keyboardInput_ = 0; // Any key read from the keyboard

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
	The callback function for when a keyboard key is pressed
	*/
	static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (action == GLFW_PRESS)
			keyboardInput_ = (char) key;
	}

	/*
	Returns whether the mouse's left button is clicked
	*/
	static bool IsMouseButtonDown() { return mouseButtonDown_; }

	/*
	Returns the scrollwheel value from the mouse, and set it to zero
	*/
	static double ScrollWheelValue() 
	{
		double scrollWheel_tmp = scrollWheel_;
		scrollWheel_ = 0;
		return scrollWheel_tmp;
	}

	/*
	Returns the last key press received from the keyboard and clears it.
	If no last key, returns 0
	*/
	static char GetKeyboardValue() 
	{ 
		char keyboardInput_tmp = keyboardInput_;
		keyboardInput_ = 0;
		return keyboardInput_tmp;
	}
};