// Sine using Taylor series
double sin(double x) {
    double sum = x;
    double term = x;
    int sign = -1;
    for (int i = 3; i <= 25; i += 2) {
        term *= x*x / (i*(i-1));
        sum += sign * term;
        sign *= -1;
    }
    return sum;
}