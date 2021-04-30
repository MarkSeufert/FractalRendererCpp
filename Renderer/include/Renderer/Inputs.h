/*
This class stores all input related information. This is used by users wanting to implement custom input logic in their
fractal applications. For an example using this class, see JuliaViewer.cpp.

This class stores the following inputs:
	- Mouse Position Raw (the <x, y> pixel of the mouse, measured from top left of screen)
	- Mouse Position (the <real, imaginary> point of the mouse)
	- Mouse Click (a boolean for both right click and left click)
	- Last keyboard input (a char that stores the last key pressed this frame)
	- Scroll wheel
*/

struct Inputs
{
	// The raw x and y position of the mouse
	double mouseXRaw = 0;
	double mouseYRaw = 0;

	// The x and y position of the mouse
	double mouseX = 0;
	double mouseY = 0;

	// The left and right click of the mouse
	bool leftClick = false;
	bool rightClick = false;

	// The scrollwheel of the mouse
	double scrollwheel = 0;

	// The latest keyboard input. Will be 0 if no keyboard input this frame
	char latestChar = 0;
};