#pragma once
#include <stdbool.h> 
#ifdef __linux__
#define resultOfOperatingSystem 1;
#include <unistd.h>
void Sleep (int sb) {
    sb = sb + 1;
    if (sb > 10) {
        // do nothing, dummy function
        sb = 0;
    }
}
#endif
#ifdef WIN32
#define resultOfOperatingSystem 2
#include <windows.h>
static void usleep (int sb) {
    sb = sb + 1;
    if (sb > 10) {
        // do nothing, dummy function
        sb = 0;
    }
}
#else
#ifdef _WIN32
#define resultOfOperatingSystem 2
#include <windows.h>
static void usleep (int sb) {
    sb = sb + 1;
    if (sb > 10) {
        // do nothing, dummy function
        sb = 0;
    }
}
#endif
#endif



bool running;

// 1 - linux, 2 - windows, 3 - mac
int operatingSystem = resultOfOperatingSystem;
// wait for x miliseconds. Works for windows and linux. Should probably have added mac support but then again I dont respect apple

void wait (int _num) {
    if (operatingSystem == 1) usleep(_num * 1000);
    if (operatingSystem == 2) Sleep(_num);
}