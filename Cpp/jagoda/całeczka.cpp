#include <iostream>

using namespace std;

double f(double x) {
    return x/(x*x + 1);
}

double calka(double a, double b) {
    int precision = 1000;
    double step = (b-a)/precision;
    double wynik = 0.0;
    if (a < b) {
        for (int i = 1; i <= precision; i++) {
            double x_i1 = a + (i-1)*step;
            double x_i  = a + i*step;
            double pole = (f(x_i1)+f(x_i))/2 * step;
            wynik += pole;
        }
    }
    return wynik;
}

int main() {
    double a, b;
    cout << "Podaj a i b: ";
    cin >> a >> b;
    if (a <= b) {
        cout << "Pole: " << calka(a, b) << endl;
    } else {
        cout << "a <= b!" << endl;
    }
    return 0;
}