//
// Created by Ilya Sazonov on 07.09.2020.
//

#include "equation.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countRoots(double a, double b, double c, double* x1, double* x2) {
    if (closeToZero(a)) {
        if (closeToZero(b)) {
            if (closeToZero(c)) {
                return INF_NUM;
            }
            else {
                return 0;
            }
        }

        *x1 = -c / b;
        removeNegativeZero(x1);
        *x2 = *x1;

        return 1;
    }
    else {
        double discr = b * b - 4 * a * c;

        // case of negative discriminant
        if (discr < 0) {
            return 0;
        }

        // case of zero-discriminant
        if (closeToZero(discr)) {
            *x1 = -b / (2 * a);
            removeNegativeZero(x1);
            *x2 = *x1;

            return 1;
        }

        *x1 = (-b - sqrt(discr)) / (2 * a);
        removeNegativeZero(x1);
        *x2 = (-b + sqrt(discr)) / (2 * a);
        removeNegativeZero(x2);
        if (*x2 < *x1) {
            double cop = *x2;
            *x2 = *x1;
            *x1 = cop;
        }

        return 2;
    }
}

bool closeToZero(double number) {
    return fabs(number) <= EPS;
}

void removeNegativeZero(double* value) {
    if (closeToZero(*value))
        *value = 0;
}

void printEquation(int rootsNumber, double a, double b, double c, const double *x1, const double *x2) {
    printf("\nSecond-degree equation: %lg*x^2 + %lg*x + %lg = 0\n", a, b, c);
    printf("Number of roots of your second-degree equation: %d\n", rootsNumber);
    switch (rootsNumber) {
        case INF_NUM:
            printf("Infinite numbers of roots\n");
            break;

        case 0:
            printf("There is no roots\n");
            break;

        case 1:
            printf("Root: x = %lg\n", *x1);
            break;

        case 2:
            printf("Roots: x1 = %lg \t x2 = %lg\n", *x1, *x2);
            break;

        default:
            printf("Something went wrong in function printEquation()\n");
            exit(-1);
    }
}
