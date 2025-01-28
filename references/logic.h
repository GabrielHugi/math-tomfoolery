#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "../logic/logic.c"

extern void removefgetsnewline (char *_str);
// separate lines with ";"
void printfTextLinesWithDelay (char *_line, int _delayTime);
extern void askForInput ();