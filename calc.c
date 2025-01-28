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
    printf("--- The Handy Calculator ---\nV 1.0\nAuthor: Gabriel Hugi\nFunctions:\n - Basic math operations\n - Analysis and breakdown of expresions\n\n---------------------\n\n");
    while(running) {
        askForInput();
        printfTextLinesWithDelay("skibid or not;tu skibidornot;eskebedi", 400);
    }
    return 0;
}