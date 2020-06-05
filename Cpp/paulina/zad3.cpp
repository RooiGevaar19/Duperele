#include <iostream>

using namespace std;

void cube(int *x) {
    (*x) = (*x) * (*x) * (*x);
}

int main() {
    int x;
    cout << "Podaj x: ";
    cin >> x;
    cout << " x   = " << x << endl;
    cube(&x);
    cout << " x   = " << x << endl;
    return 0;
}