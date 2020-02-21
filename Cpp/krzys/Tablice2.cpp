#include <iostream>
#include <cstring>

using namespace std;

string printTable(int T[], int n) {
    if (n == 0) return "[]";

    string wynik = "[";
    for (int i = 0; i <= n-1; i++) {
        wynik += to_string(T[i]) + ", ";
    }
    wynik += "\b\b]";
    return wynik;
}

int sum(int T[], int n) {
    int wynik = T[0];
    for (int i = 1; i < n; i++) {
        wynik += T[i];
    }
    return wynik;
}

double avg(int T[], int n) {
    double wynik = T[0];
    for (int i = 1; i < n; i++) {
        wynik += T[i]*1.0;
    }
    return wynik/n;
}

int product(int T[], int n) {
    int wynik = T[0];
    for (int i = 1; i < n; i++) {
        wynik *= T[i];
    }
    return wynik;
}

int min(int T[], int n) {
    int minimum = 0;
    for (int i = 1; i < n; i++) {
        if (T[i] < T[minimum]) {
            minimum = i;
        }
    }
    return minimum;
}

int max(int T[], int n) {
    int maximum = 0;
    for (int i = 1; i < n; i++) {
        if (T[i] > T[maximum]) {
            maximum = i;
        }
    }
    return maximum;
}


int main()
{
    int n;
    cout << "Podaj liczbe elementów: ";
    cin >> n;
    int T[n];
    for (int i = 0; i < n; i++) {
        cout << "T[" << i+1 << "] = ";
        cin >> T[i];
    }
    cout << "Tablica: " << printTable(T, n) << endl;
    cout << "Suma:    " << sum(T, n) << endl;
    cout << "Srednia: " << avg(T, n) << endl;
    cout << "Produkt: " << product(T, n) << endl;
    cout << "Min:     " << T[min(T, n)] << endl;
    cout << "Max:     " << T[max(T, n)] << endl;


    return 0;
}
