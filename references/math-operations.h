#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../logic/math-operations.c"

/*
    Proposal: Make a algorithm that will generate x random positive integer numbers that will add up to y
    Example: y = 300; Output: 56, 244, 300
    Extra: give a range from x to y that the generated numbers must match;
    01/27/2025
*/

int generateXRandomAddUpToY(size_t ammountOfNumbers, long long int addsUpTo, size_t *isStoredAt);