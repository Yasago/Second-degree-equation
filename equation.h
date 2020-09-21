//
// Created by Ilya Sazonov on 07.09.2020.
//

#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H

#define EPS 1e-6;
#define INF_NUM -1

#include <stdbool.h>

///
/// Count roots of second-degree equation
/// \param a first coefficient of equation
/// \param b second coefficient of equation
/// \param c third coefficient of equation
/// \param x1 first variable to possible root of equation
/// \param x2 second variable to possible root of equation
/// \return number of roots of equation
int countRoots(double a, double b, double c, double* x1, double* x2);

///
/// Check if number is near to zero
/// \param number
/// \return
bool closeToZero(double number);

/// Removes negative zero, if value has this case
/// \param value
void removeNegativeZero(double* value);

///
/// Count roots of second-degree equation
/// \param rootsNumber number of roots of the equation
/// \param a first coefficient of equation
/// \param b second coefficient of equation
/// \param c third coefficient of equation
/// \param x1 first variable to possible root of equation
/// \param x2 second variable to possible root of equation
void printEquation(int rootsNumber, double a, double b, double c, const double* x1, const double* x2);

#endif //EQUATION_EQUATION_H
