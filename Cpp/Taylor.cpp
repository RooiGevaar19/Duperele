#include <iostream>
#include <cmath>

using namespace std;

double f(double x, int i) {
    switch (i%4) {
        case 0 : return sin(x);
        case 1 : return cos(x);
        case 2 : return -sin(x);
        case 3 : return -cos(x);
    }
}


int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}

double power(double a, int f) {
    if (f == 0) return 1;
    return a * power(a, f-1);
}

double taylor(double x, double x0, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += (f(x0, i)/fact(i)) * power(x - x0, i);
    }
    return s;
}

int main() {
    double x = 3.15;
    for (double i = 0; i < 6.3; i += 0.1) {
        //printf("sin(%lf) = %lf\n", i, taylor(i, 1, 10));
        cout << "sin(" << i << ") = " << taylor(i, x/2, 10) << "\n";
    }
    return 0;
}