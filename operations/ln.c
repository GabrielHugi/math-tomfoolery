// Natural logarithm ln(x) using Newton-Raphson
double ln(double x) {
    if (x <= 0.0) {
        exit(1);
    }
    double y = x - 1.0; // initial guess
    for (int i = 0; i < 50; i++) {
        double fy = my_exp(y) - x;   // f(y) = e^y - x
        double fdy = my_exp(y);      // f'(y) = e^y
        y = y - fy / fdy;
    }
    return y;
}