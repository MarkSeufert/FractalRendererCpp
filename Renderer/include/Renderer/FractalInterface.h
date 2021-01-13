#pragma once

/*
This class creates an interface that a fractal implementation must follow.
*/

class FractalInterface
{
public:
	/*
	Calculates this fractal's algorithm given a (real,imaginary) point. Must return a value
	between 0 and 1, where a value closer to 1 means closer to being inside the fractal. A value
	equal to 1 means the point is inside the set.
	*/
	virtual double Evaluate(double real, double imaginary) = 0;

	/*
	Sets the max number of iterations that the Evaluate() method can complete before returning.
	*/
	void SetMaxIterations(int maxIterations)
	{
		maxIterations_ = maxIterations;
	}

protected:
	int maxIterations_ = 100;
};