#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Proposal: Make a algorithm that will generate x random positive integer numbers that will add up to y
    Example: y = 300; Output: 56, 244, 300
    Extra: give a range from x to y that the generated numbers must match;
    01/27/2025
*/

int generateXRandomAddUpToY(size_t ammountOfNumbers, size_t addsUpTo, size_t *isStoredAt) {
    static time_t whenCalled;
    if (whenCalled != time(NULL)) {
    srand(time(NULL));
    whenCalled = time(NULL);
    }
    size_t numbers[ammountOfNumbers];
    if (ammountOfNumbers == 1) {
        isStoredAt[0] = addsUpTo;
        return 1;
    }
    for (size_t i = 0; i < ammountOfNumbers; i++) {
        numbers[i] = rand() % (addsUpTo+1);
    }
    size_t sumup = 0;
    for (size_t i = 0; i < ammountOfNumbers; i++) {
        sumup += numbers[i];
    }
    size_t over = sumup / addsUpTo;
    if (over == 0) {
        long double remaining = addsUpTo - sumup;
        for (size_t i = 0; i < ammountOfNumbers; i++) {
            if (numbers[i] + remaining <= addsUpTo) {
                numbers[i] += remaining;
                i = ammountOfNumbers;
            }
        }
    }
    if (over >= 1) {
        size_t overflow = sumup - addsUpTo;
        short int easyWayOut = 0;
        for (size_t i = 0; i < ammountOfNumbers; i++) {
            long long int result = numbers[i] - overflow;
            if (result >= 0) {
                numbers[i] -= overflow;
                i = ammountOfNumbers;
                easyWayOut = 1;
            }
        }
        if (easyWayOut != 1) {
            size_t numbersPosition = 0;
            for (size_t i = 0; i < overflow; i++) {
                if (numbersPosition == ammountOfNumbers) numbersPosition = 0;
                long long int result = numbers[numbersPosition] - 1;//overflow divided by overflow
                if (result >= 0) {
                    numbers[numbersPosition] -= 1;
                }
                else {
                    i--;
                }   
                numbersPosition++;
            }
        }
    }
    for (size_t i = 0; i < ammountOfNumbers; i++) {
        isStoredAt[i] = numbers[i];
    }
    return 1;
}