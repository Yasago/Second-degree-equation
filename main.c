#include "equation.h"
#include "testLib.h"
#include <stdio.h>
#include <math.h>

const int MAX_VALUE = 2147483647;

///
/// @brief Entry point
///
/// Execution of the program
/// starts here.
///
/// @return Program exit status
int main() {
    runAllTests();
    printf("Please, enter coefficient A, B and C of your second-degree equation:\n");
    double coefficient[3];
    int return_value;
    for (int i = 0; i < 3; ++i) {
        return_value = 0;
        while (!return_value) {
            printf("Enter first coefficient %c:\n", 'A' + i);
            return_value = scanf("%lg", &coefficient[i]);
            if (fabs(coefficient[i]) > MAX_VALUE) {
                return_value = 0;
            }
            else
                removeNegativeZero(&coefficient[i]);

            // this loop will "eat" every character that's left in input buffer
            int c = getchar();
            while (c != '\n') {
                if (c != ' ')
                    return_value = 0;
                c = getchar();
            }
        }
    }

    double x1 = 0;
    double x2 = 0;
    int rootsNumber = countRoots(coefficient[0], coefficient[1], coefficient[2], &x1, &x2);
    printEquation(rootsNumber, coefficient[0], coefficient[1], coefficient[2], &x1, &x2);

    return 0;
}