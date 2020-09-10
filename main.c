#include "equation.h"
#include "testLib.h"
#include <stdio.h>

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

            // this loop will "eat" every character that's left in input buffer
            while (getchar() != '\n') {
            }
        }
    }

    double x1 = 0;
    double x2 = 0;
    int rootsNumber = countRoots(coefficient[0], coefficient[1], coefficient[2], &x1, &x2);
    printEquation(rootsNumber, coefficient[0], coefficient[1], coefficient[2], &x1, &x2);

    return 0;
}