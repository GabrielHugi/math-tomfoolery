// Arctangent using Taylor series (for |x| <= 1)
double atan(double x) {
    double sum = x;
    double term = x;
    int sign = -1;
    for (int i = 3; i <= 49; i += 2) {
        term *= x*x;
        sum += sign * term / i;
        sign *= -1;
    }
    return sum;
}