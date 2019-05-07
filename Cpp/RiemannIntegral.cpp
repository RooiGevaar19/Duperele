#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int abs(int x) {
    return ((x>=0)?x:-x);
}

double f(double x) {
    return sin(x);
}

double integral(double a, double b, int precision) {
    double s = 0.0;
    double length = b-a;
    double delta = length / precision;
    for (int i = 0; i < precision; i++) {
        double avg = (f(a + i*delta)+f(a + (i+1)*delta)) / 2;
        s += delta*avg;
    }
    return s;
}

int main() {
    double a, b; 
    int prec;
    cout << "Podaj lewy koniec przedziału całkowania  : "; cin >> a;
    cout << "Podaj prawy koniec przedziału całkowania : "; cin >> b;
    cout << "Podaj precyzję : "; cin >> prec; prec = abs(prec);
    if (a < b) cout << "Całka na [" << a << ", " << b << "] funkcji wynosi około " << integral(a,b,prec) << "\n";
    if (b < a) cout << "Całka na [" << a << ", " << b << "] funkcji wynosi około " << (-1)*integral(b,a,prec) << "\n";
    if (b == a) cout << "Całka na [" << a << ", " << b << "] funkcji wynosi 0\n";
    return 0;
}