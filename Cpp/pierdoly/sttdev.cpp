#include <iostream>
#include <cmath>

using std::cout;

double f(double x[], double mu, double N) {
    double s = 0.0;
    for (int i = 1; i <= N; i++) {
        s += x[i]*x[i];
    }
    s /= N;
    s -= mu*mu;
    return sqrt(s);
}

int main() {
    double x[10] = {1, 4, 5, 6, 7, 2, 7, 9, 0, 12};
    double mu = 5.5;
    cout << f(x, mu, 10) << "\n";
    return 0;
}