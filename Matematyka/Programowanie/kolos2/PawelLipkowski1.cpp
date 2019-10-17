\include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;
using std::setprecision;

// ====== potęga i silnia

double abs(double a) {
    return (a >= 0) ? a : -a;
}

double power(double a, int f) {
    if (f == 0) return 1;
    return a * power(a, f-1);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}

int product_between(int a, int b) {
    int s = 1;
    for (int i = a; i <= b; i++) s *= i;
    return s;
}

// ====== pochodne

double exp_derivative(double x, int i) {
    return exp(x); // i jest zbędne, guess why :P
}

double sin_derivative(double x, int i) {
    switch (i%4) {
        case 0 : return sin(x);
        case 1 : return cos(x);
        case 2 : return -sin(x);
        case 3 : return -cos(x);
    }
}

double cos_derivative(double x, int i) {
    switch (i%4) {
        case 0 : return cos(x);
        case 1 : return -sin(x);
        case 2 : return -cos(x);
        case 3 : return sin(x);
    }
}

double poly_derivative(double x, int i) {
    if (i == 0) return pow(x, 10);
    double s = 0;
    for (int f = 0; f < i && f < 10; f++) {
        s = product_between(10-f, 10) * pow(x, 10-f);
    }
    return s;
}

// ====== wzory Taylora

double exp_taylor(double x, double x0, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += (exp_derivative(x0, i) / factorial(i)) * power(x - x0, i);
    }
    return s;
}

double sin_taylor(double x, double x0, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += (sin_derivative(x0, i) / factorial(i)) * power(x - x0, i);
    }
    return s;
}

double cos_taylor(double x, double x0, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += (cos_derivative(x0, i) / factorial(i)) * power(x - x0, i);
    }
    return s;
}

double poly_taylor(double x, double x0, int n) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += (poly_derivative(x0, i) / factorial(i)) * power(x - x0, i);
    }
    return s;
}

int main() {
    cout << "expr\tapprox\t\tcmath\t\tdelta\n";
    cout << "exp(x)\t" << setw(13) << setprecision(12) << exp_taylor(0.01, 0, 3) << "\t" << exp(0.01)      << "\t" << exp_taylor(0.01, 0, 3) - exp(0.01) << "\n";
    cout << "sin(x)\t" << setw(13) << setprecision(12) << sin_taylor(0.1, 0, 3)  << "\t" << sin(0.1)       << "\t" << sin_taylor(0.1, 0, 3) - sin(0.1) << "\n";
    cout << "cos(x)\t" << setw(13) << setprecision(12) << cos_taylor(0.1, 0, 3)  << "\t" << cos(0.1)       << "\t" << cos_taylor(0.1, 0, 3) - cos(0.1) << "\n";
    cout << "x^10  \t" << setw(13) << setprecision(12) << poly_taylor(1.1, 1, 3) << "\t" << power(1.1, 10) << "\t" << poly_taylor(1.1, 1, 3) - power(1.1, 10) << "\n";
    return 0;
}