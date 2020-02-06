#include <iostream>
#include <cstring>

using namespace std;

void wypiszTablice(int T[], int n) {
    for (int i = 0; i <= n-1; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
}

string wypiszTablice1(int T[], int n) {
    if (n == 0) return "[]";

    string wynik = "[";
    for (int i = 0; i <= n-1; i++) {
        wynik += to_string(T[i]) + ", ";
    }
    wynik += "\b\b]";
    return wynik;
}

int main() {
    int n;
    cout << "Podaj rozmiar tabeli: ";
    cin >> n;
    int T[n];
    cout << "Podaj tabelę: ";
    for (int i = 0; i <= n-1; i++) {
        cin >> T[i];
    }

    cout << "Wypisujemy:\t";
    wypiszTablice(T, n);

    int delta[n];
    delta[0] = T[0];
    for (int i = 1; i <= n-1; i++) {
        delta[i] = T[i] - T[i-1];
    }
    cout << "Delta:   \t";
    wypiszTablice(delta, n);

    int suma[n];
    suma[0] = delta[0];
    for (int i = 1; i <= n-1; i++) {
        suma[i] = suma[i-1] + delta[i];
    }
    cout << "Wysumowanie:\t";
    cout << wypiszTablice1(suma, n) << "\n";
    

    return 0;
}