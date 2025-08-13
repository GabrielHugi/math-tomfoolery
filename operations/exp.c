// Exponential e^x using Taylor series
double exp(double x) {
    double sum = 1.0;
    double term = 1.0;
    for (int i = 1; i <= 50; i++) { // Taylor series
        term *= x / i;
        sum += term;
    }
    return sum;
}