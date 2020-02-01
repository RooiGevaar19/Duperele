#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.1415926535;

int main() {
    double r;
    cin >> r;

    double pole = PI*r*r;
    double obwod = 2*PI*r;

    cout << setprecision(3) << fixed;
    cout << pole << endl;
    cout << obwod << endl;

    return 0;
}