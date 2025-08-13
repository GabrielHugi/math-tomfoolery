#pragma once
#include "../structs/complex.h"

Complex c_mul(Complex a, Complex b) {
    Complex r = {a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real};
    return r;
}