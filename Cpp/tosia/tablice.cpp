#include <iostream>

using namespace std;

int max(float T[], int n) {
    int maksimum = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] > T[maksimum]) {
            maksimum = i;
        }
    }
    return maksimum;
}

int min(float T[], int n) {
    int minimum = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] < T[minimum]) {
            minimum = i;
        }
    }
    return minimum;
}

int sum(float T[], int n) {
    int s = T[0];
    for (int i = 1; i < n; i++) {
        s += T[i];
    }
    return s;
}

int product(float T[], int n) {
    int s = T[0];
    for (int i = 1; i < n; i++) {
        s *= T[i];
    }
    return s;
}

int main() {
    int n;
    cout << "Podaj dlugosc tablicy: ";
    cin >> n;

    float T[n];
    for (int i = 0; i <= n-1; i++) {
        cin >> T[i];
    }

    cout << "Wypisywanko!" << endl;
    for (int i = 0; i <= n-1; i++) {
        cout << T[i] << " ";
    }
    cout << endl;

    cout << endl;
    cout << "Maksimum: " << T[max(T, n)] << endl;
    cout << "Minimum : " << T[min(T, n)] << endl;
    cout << "Suma    : " << sum(T, n) << endl;
    cout << "Produkt : " << product(T, n) << endl;

    return 0;
}
