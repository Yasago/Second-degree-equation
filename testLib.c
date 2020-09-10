//
// Created by Ilya Sazonov on 10.09.2020.
//

#include "equation.h"
#include <stdio.h>
#include <winnt.h>
#include <afxres.h>
#include <math.h>

void runAllTests() {
    // parameters: {expected roots number, coefficient a, b, c, expected root x1, expected root x2}
    // a*x^2 + b*x + c = 0
    double parameters[][6] = {
            {INF_NUM, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 0, 0, 3, 0, 0},
            {1, 0, 3, 0, 0, 0},
            {1, 0, 2, 3, -1.5, -1.5},
            {2, 2, 3, 1, -1, -0.5},
            {0, 2, 1, 3, 0, 0},
            {2, 2, 3, -35, -5, 3.5},
            {2, -3, -10, 13, -13.0/3, 1},
            {2, -3, 0, 9, -sqrt(3), sqrt(3)},
            {1, 3, 6, 3, -1, -1},
            {2, 6, 0, -7, -sqrt(7.0/6), sqrt(7.0/6)},
    };

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < sizeof(parameters) / sizeof(parameters[0]); ++i) {
        double  a = parameters[i][1],
                b = parameters[i][2],
                c = parameters[i][3],
               x1 = parameters[i][4],
               x2 = parameters[i][5];

        double realX1 = 0, realX2 = 0;
        int expectedRootsNum = (int)parameters[i][0];
        int rootsNum = countRoots(a, b, c, &realX1, &realX2);
        if (expectedRootsNum == rootsNum) {
            if (closeToZero(x1 - realX1) && closeToZero(x2 -realX2)) {
                SetConsoleTextAttribute(hConsole, (WORD) (2));
                printf("Test %d ok\n", i + 1);
            }
            else {
                SetConsoleTextAttribute(hConsole, (WORD) (4));
                printf("Test %d failed\nExpected roots: %lg and %lg  Actual root numbers: %lg and %lg\n",
                        i + 1, x1, x2, realX1, realX2);
                printf("\nNot all test has been passed successfully");
                exit(3);
            }
        }
        else {
            SetConsoleTextAttribute(hConsole, (WORD) (4));
            printf("Test %d failed\nExpected root numbers: %d  Actual root numbers: %d\n",
                    i + 1, expectedRootsNum, rootsNum);
            printf("\nNot all test has been passed successfully");
            exit(3);
        }
    }
    printf("All Tests Passed Successfully\n\n\n");
    SetConsoleTextAttribute(hConsole, (WORD) (0));
}
