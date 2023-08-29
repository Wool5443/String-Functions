//! @file

#ifndef SOLVE_QUADRATIC_H
#define SOLVE_QUADRATIC_H

const int NUMBER_OF_COEFFICIENTS = 3, MAX_NUMBER_OF_ROOTS = 2, COEFF_SHIFT_FOR_LINEAR = 2;

enum NumberOfRoots { INFINITE_ROOTS = -1, ZERO_ROOTS, ONE_ROOT, TWO_ROOTS };

/**
 * @brief Contains equation's coefficients, roots and nubmer of roots.
 */
struct Equation
{
	double coefficients[NUMBER_OF_COEFFICIENTS];
	double roots[MAX_NUMBER_OF_ROOTS];
	NumberOfRoots numberOfRoots;
};

/**
 * @brief Solves a given linear or quadratic equation and stores the roots in it.
 *
 * @param [in, out] equation - the equation to solve which contains coefficients. The roots are stored inside.
 */
void SolveEquation(Equation* equation);

/**
 * @brief Takes coefficients from user and stores them in the equation.
 *
 * @param [out] equation to store the coefficients in.
 *
 * @return wheter it went fine.
 */
void InputEquation(Equation* equation); //takes input from user and stores it in a, b, c

/**
 * @brief Prints the roots of the equation.
 *
 * @param [in] equation
 *
 * @return whether it went fine @see ErrorCodes
 */
void PrintAnswer(const Equation* equation); //prints all the roots of the equation if given an Answer

#endif