#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

// ====== potęga i silnia

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
        s += (cos_derivative(x0, i) / factorial(i)) * power(x - x0, i);
    }
    return s;
}