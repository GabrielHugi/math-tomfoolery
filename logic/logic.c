#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../references/global.h"
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

void removefgetsnewline (char *_str) {
    int x = 0;
    while (_str[x] != '\0') {
        x++;
    }
    _str[x-1] = '\0';
}

// separate lines with ";"
void printfTextLinesWithDelay (char *_line, int _delayTime) {
    int countOf = 0;
    for (size_t i = 0; i < strlen(_line); i++) {
        if (_line[i] == ';') countOf++;
    }
    char  _lines[countOf+1][100];
    for (int i = 0; i < countOf+1; i++) {
        for (int i2 = 0; i2 < 100; i2++) {
            _lines[i][i2] = 0;
        }
    }
    int trackingLine = 0;
    int posInLine = 0;
    for (int i = 0; i < strlen(_line); i++) {
        if (_line[i] != ';') _lines[trackingLine][posInLine] = _line[i];
        if (_line[i] == ';') {
            trackingLine++;
            posInLine = -1;
        }
        posInLine++;
    }
    for (int i = 0; i < countOf+1; i++) {
        printf("%s\n", _lines[i]);
        wait(_delayTime);
    }
}

void askForInput () {
    // this i didn't implement yet btw 
    char input[1000];
    printf("Please input your mathematical equation.\nInput %chelp%c for instructions on how to properly give your input. Input %cexit%c for instructions on how to properly give your input. \n", 34, 34, 34, 34);
    fgets(input, 1000, stdin);
    removefgetsnewline(input);
    // check input
    // in the case of strcmp, 0 means matching (true).
    if (strcmp("help", input) == 0) {
        printfTextLinesWithDelay("Formatting for operations:; - Addition: +; - Subtraction: -; - Multiplication: *; - Division: /; - Square root: sqrt(value to be processed); - Exponential: ^; - Logarithm: log(value to be processed)", 400);
        printf("\n --------------- \n\n");
        wait(1000);
    }
}