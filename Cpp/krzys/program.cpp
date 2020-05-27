#include <iostream>

using namespace std;

int newton(int n, int k) {
    if (k == 0) return 1;
    if (k == n) return 1;
    return newton(n-1, k) + newton(n-1, k-1);
}

double potega(double a, int n) {
    if (n <= 0) return 1;
    return a * potega(a, n-1);
}


int silnia(int n) {
    if (n <= 0) return 1;
    return n * silnia(n-1);
}

int main() {
    int n = 20;
    double p = 1.0/4;
    double q = 1-p;
    int k = 10;

    double wynik1 = newton(n, k) * potega(p, k) * potega(q, n-k);
    cout << "P(X = 10) = " << wynik1 << endl;

    double wynik2 = 0;
    for (int i = 0; i <= 9; i++) {
        wynik2 += newton(n, i) * potega(p, i) * potega(q, n-i);
    }
    cout << "P(X <= 9) = " << wynik2 << endl;
    cout << "P(X >= 10) = " << 1-wynik2 << endl;
    return 0;
}