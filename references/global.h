#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "../global.c"

extern bool running;
extern int operatingSystem;
extern void wait (int _num);
extern void Sleep (int sb);
extern void printfTextLinesWithDelay (char *_line, int _delayTime);