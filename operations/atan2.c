// Arctangent 2-argument approximation
double atan2(double y, double x) {
    if (x > 0) return my_atan(y/x);
    if (x < 0 && y >= 0) return my_atan(y/x) + 3.141592653589793;
    if (x < 0 && y < 0) return my_atan(y/x) - 3.141592653589793;
    if (x == 0 && y > 0) return 3.141592653589793/2.0;
    if (x == 0 && y < 0) return -3.141592653589793/2.0;
    return 0; // x=0, y=0 undefined, return 0
}