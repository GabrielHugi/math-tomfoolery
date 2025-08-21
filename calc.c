#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "references/math-operations.h"
#include "references/logic.h"
#include "references/global.h"
#ifdef __linux__
#include <unistd.h>
#endif
#ifdef WIN32
#include <windows.h>
#else
#ifdef _WIN32
#include <windows.h>
#endif
#endif

int main () {
    running = true;
    short int topic = 0;
    short int operation = 0;
    printf("--- Math Tomfoolery ---\nV 1.0\nAuthor: Gabriel Hugi\n");
    //while(running) {
    while (running) {
        printfTextLinesWithDelay("Choose the math topic;1 - Random number generators", 200);
        scanf("%hd", &topic);
        while (getchar() != '\n') {};
        // I hate switch statements but I was told its good or something idk


        // RNG ------------------
        if (topic == 1) {
            printfTextLinesWithDelay("Choose the operation;1 - generate x random positive integer numbers that will add up to y", 200);
            scanf("%hd", &operation);
            while (getchar() != '\n') {};


            // x positive ints that add up to y ----------
            if (operation == 1) {
                for (int i = 0; i != -1;) {
                    long long int x; long long int y;
                    printf("Insert X\n");
                    scanf("%lld", &x);
                    while (getchar() != '\n') {};
                    printf("Insert Y\n");
                    scanf("%lld", &y);
                    while (getchar() != '\n') {};
                    long long int storage[x];
                    generateXRandomAddUpToY(x, y, *&storage);
                    printf("Results:\n");
                    for (long long int i = 0; i < x; i++) {
                        printf("%lld\n", storage[i]);
                    }
                    int negative = 0;
                    long long int sumup = 0;
                    for (long long int i = 0; i < x; i++) {
                        sumup += storage[i];
                        if (storage[i] < 0) negative = 1;
                    }
                    printf("--- Stats ---\n");
                    printf("sum: %lld\n", sumup);
                    printf("negative: %d\n", negative);
                    
                    printf("Insert R to redo, insert anything else to go back to main menu\n");
                    char op;
                    scanf("%c", &op);
                    while (getchar() != '\n') {};
                    if (op != 'R' && op != 'r') {
                        i = -1;
                    }
                }
            }



        }
        // end of topic
    }
    return 0;
}