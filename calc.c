#include <stdio.h>
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
    long long int wrongs = 0;
    for (int i = 0; i < 1000000; i++) {
        //printfTextLinesWithDelay("Choose math topic or calculator mode;1 - Basic", 400);
        //scanf("%hd%*c", &topic);
        //while ((getchar()) != '\n');
        size_t bullshit[400];
        generateXRandomAddUpToY(3, 600, *&bullshit);
        long long int bigboy = 0;
        for (size_t i = 0; i < 3; i++) {
            bigboy += bullshit[i];
        }
        if (bigboy != 600) {
            wrongs++;
        }
        printf("\nseparation\n");
        for (int i = 0; i < 3; i++) {
            printf("%ld\n", bullshit[i]);
        }
        printf("%lld\n", bigboy);
        if (i == 999999) {
            printf("\n\nErrors = %lld", wrongs);
        }
    }
    return 0;
}