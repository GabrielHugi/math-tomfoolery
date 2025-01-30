#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logic/logic.c"
#include "logic/math-operations.c"
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
        if (topic == 1) {
            printfTextLinesWithDelay("Choose the operation;1 - generate x random positive integer numbers that will add up to y", 200);
            scanf("%hd", &operation);
            while (getchar() != '\n') {};
            if (operation == 1) {
                for (int i = 0; i != -1;) {
                    size_t x; size_t y;
                    printf("Insert X\n");
                    scanf("%ld", &x);
                    while (getchar() != '\n') {};
                    printf("Insert Y\n");
                    scanf("%ld", &y);
                    while (getchar() != '\n') {};
                    size_t storage[x];
                    generateXRandomAddUpToY(x, y, *&storage);
                    printf("Results:\n");
                    for (size_t i = 0; i < x; i++) {
                        printf("------\n");
                        printf("%ld\n", storage[i]);
                    }
                    printf("------\n");
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
    }
    return 0;
}