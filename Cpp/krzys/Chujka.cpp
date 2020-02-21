#include <iostream>

using namespace std;

void wypiszRzadek(int middle, int i, int stars) {
    for (int j = 0; j <= middle - i; j++) {
        cout << " ";
    }
    for (int j = 1; j <= stars; j++) {
        cout << "*";
    }
    cout << endl;
}

void wypiszGore(int n) {
    int middle = n-1;
    int stars = 1;
    for (int i = 1; i <= n; i++) {
        wypiszRzadek(middle, i, stars);
        stars += 2;
    }
}

void wypiszPien(int n) {
    int middle = n-1;
    wypiszRzadek(middle, 1, 1);
    wypiszRzadek(middle, 1, 1);
}

int main() {
    int n;
    cin >> n;
    wypiszGore(n);
    wypiszPien(n);
    return 0;
}