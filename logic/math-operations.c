#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Proposal: Make a algorithm that will generate x random positive integer numbers that will add up to y
    Example: y = 300; Output: 56, 244, 300
    Extra: give a range from x to y that the generated numbers must match;
    01/27/2025

    ey this is working vro
*/

int generateXRandomAddUpToY(long long int ammountOfNumbers, long long int addsUpTo, long long int *isStoredAt) {
    static time_t whenCalled;
    if (whenCalled != time(NULL)) {
    srand(time(NULL));
    whenCalled = time(NULL);
    }
    long long int *numbers = malloc(sizeof(long long int) * ammountOfNumbers);
    if (ammountOfNumbers == 1) {
        isStoredAt[0] = addsUpTo;
        return 1;
    }
    for (long long int i = 0; i < ammountOfNumbers; i++) {
        numbers[i] = rand() % (addsUpTo+1);
    }
    long long int sumup = 0;
    for (long long int i = 0; i < ammountOfNumbers; i++) {
        sumup += numbers[i];
    }
    long long int over = (long long int)((long long int)sumup / (long long int)addsUpTo);
    // smaller
    long long int overflow = sumup - addsUpTo;
    if (over == 0) {
        long long int remaining = addsUpTo - sumup;
        for (long long int i = 0; i < ammountOfNumbers; i++) {
            if (numbers[i] + remaining <= addsUpTo) {
                numbers[i] += remaining;
                break;
            }
        }
    }
    short int easyWayOut = 0;
    if (over >= 1 && overflow != 0) {
        for (long long int i = 0; i < ammountOfNumbers; i++) {
            long long int result = numbers[i] - overflow; 
            if (result >= 0) {
                numbers[i] -= overflow;
                easyWayOut = 1;
                break;
            }
        }
        if (easyWayOut != 1) {
            long long int numbersPosition = 0;
            while (overflow != 0) {
                if (numbersPosition == ammountOfNumbers) numbersPosition = 0;
                long long int remove = rand() % (numbers[numbersPosition] + 1);
                if (overflow - remove < 0) {
                    remove = overflow;
                }
                numbers[numbersPosition] -= remove;
                overflow -= remove;
                numbersPosition++;
            }
        }
    }
    for (long long int i = 0; i < ammountOfNumbers; i++) {
        isStoredAt[i] = numbers[i];
    }

    // free shit
    free(numbers);

    return 1;
}

/*
    Proposal: 
    Example: 
    Extra: 
*/