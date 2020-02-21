#include <iostream>

using namespace std;

int potega(int n) {
    if (n == 0) return 1;
    else {
        switch (n%4) {
            case 0 : return 6;
            case 1 : return 2;
            case 2 : return 4;
            case 3 : return 8;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << potega(n) << endl;
    return 0;
}