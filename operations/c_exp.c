#pragma once
#include "../structs/complex.h"

Complex c_exp(Complex z) {
    // e^(a+bi) = e^a * (cos b + i sin b)
    double ea = my_exp(z.real);
    Complex r = {ea * my_cos(z.imag), ea * my_sin(z.imag)};
    return r;
}