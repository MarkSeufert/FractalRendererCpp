#pragma once

#include "Renderer/FractalInterface.h"

/*
This class contains the mathematical implementation of the Julia sets. 
A Julia set requires a complex point to be generated around, which is set using the SetPoint(double, double) method.
For more details about these fractals, see: https://en.wikipedia.org/wiki/Julia_set
*/

class Julia : public FractalInterface
{
public:
	// The constructor takes in the complex point that the Julia set is generated around
	Julia(double real = 0, double imaginary = 0)
	{
		real_ = real;
		imaginary_ = imaginary;
	}

	double Evaluate(double real, double imaginary)
	{
		// At a high level, compute (zn+1 = zn ^ 2 + c) until zn+1 has a magnitude > 2 or until max iterations
		double zn_real = real, zn_imag = imaginary;
		double znplus1_real = 0, znplus1_imag = 0;
		for (double i = 0; i < maxIterations_; i++) {
			// Calculate zn+1 as zn ^ 2 + c
			znplus1_real = (zn_real * zn_real) - (zn_imag * zn_imag) + real_;
			znplus1_imag = 2 * zn_real * zn_imag + imaginary_;

			// Set zn equal to zn+1
			zn_real = znplus1_real;
			zn_imag = znplus1_imag;

			// Check if the magnitude of zn is greater than 2
			// Which is equal to if the square magnitude is greater than 4 (more efficient)
			if ((zn_real * zn_real) + (zn_imag * zn_imag) > 4) {
				return i / maxIterations_;
			}
		}

		// If after maxIterations the point did not return, it is in the set
		return 1;
	}

private:
	// The complex point to generate the Julia set around
	double real_ = 0, imaginary_ = 0;
};