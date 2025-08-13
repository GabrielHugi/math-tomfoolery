#include <stdint.h>

#define MAX_DIGITS 1000
typedef struct {
    uint8_t digits[(MAX_DIGITS + 1) / 2];
    int length;
} BigInt;
// this allows us to store arbitrarily long integers
// oops im out of time, will continue later