#pragma once
#include <stdlib.h>

// Square root using Newton-Raphson
double sqrt(double x) {
    if (x < 0) {
        exit(1);
    }
    double guess = x / 2.0;
    for (int i = 0; i < 50; i++) {
        guess = 0.5 * (guess + x / guess);
    }
    return guess;
}