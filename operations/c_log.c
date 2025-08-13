#pragma once
#include "../structs/complex.h"

Complex c_log(Complex z) {
    // ln(z) = ln(|z|) + i * arg(z)
    double magnitude = my_sqrt(z.real*z.real + z.imag*z.imag);
    double angle = my_atan2(z.imag, z.real);
    Complex r = {my_ln(magnitude), angle};
    return r;
}