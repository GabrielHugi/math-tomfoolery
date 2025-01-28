#include <stdio.h>
#include <stdbool.h>
#include "logic/logic.c"
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
    printf("--- The Handy Calculator ---\nV 1.0\nAuthor: Gabriel Hugi\n");
    while(running) {
        printfTextLinesWithDelay("Choose math topic or calculator mode;1 - Basic", 400);
        scanf("%hd", &topic);
    }
    return 0;
}