#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;

    int T[n];
    for (int i = 0; i <= n-1; i++) {
        cout << "Podaj T[" << i+1 << "]: ";
        cin >> T[i];
    }

    // sortowanie bąbelkowe (bubblesort)
    for (int zakres = n-1; zakres >= 1; zakres--) {
        for (int i = 0; i <= zakres; i++) {
            if (T[i] > T[i+1]) {
                int pom = T[i];
                T[i] = T[i+1];
                T[i+1] = pom;
            }
        }
    }

    // wypisz tablicę
    cout << "Tablica: ";
    for (int i = 0; i <= n-1; i++) {
        cout << T[i] << " ";
    }
    cout << endl;

    return 0;
}