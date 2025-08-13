#pragma once
#include "../structs/complex.h"
#include "c_log.h"
#include "c_exp.h"


Complex my_pow(double base, double exp) {
    // Zero base handling
    if (base == 0.0) {
        if (exp == 0.0) {
            Complex r = {0.0/0.0, 0.0/0.0};
            return r;
        }
        if (exp < 0.0) {
            Complex r = {0.0/0.0, 0.0/0.0};
            return r;
        }
        Complex r = {0.0, 0.0};
        return r;
    }

    Complex z;
    if (base > 0.0) {
        z.real = base; z.imag = 0.0;
    } else {
        // Negative base becomes complex
        z.real = base; z.imag = 0.0;
    }

    Complex ln_z = c_log(z);           // ln(z)
    Complex exp_ln = {exp * ln_z.real, exp * ln_z.imag};
    return c_exp(exp_ln);              // e^(exp*ln(z))
}