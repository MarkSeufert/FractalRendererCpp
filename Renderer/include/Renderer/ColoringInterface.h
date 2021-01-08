#pragma once

/*
This class creates an interface that is used to create custom coloring schemes.
*/

class ColoringInterface
{
public:
	/* 
	Given the iterationRatio, returns the RGB values by reference used to color this point. The iterationRatio 
	is a value between 0 and 1, where a value closer to 1 means it is closer to being inside the fractal.
	*/
	virtual void GetColor(double iterationRatio, double& r, double& g, double& b) = 0;
};