#include <iostream>
#include <cstring>

using namespace std;

int potega(int a, int f) {
    if (f == 0) return 1;
    else return a * potega(a, f-1); 
}

int konwertujNaDziesiatkowy(int T[], int n) {
    int wartosc = 0;
    int f = 0;
    for (int i = n-1; i >= 0; i--) {
        wartosc += T[i]*potega(5, f);
        f++;
    }
    return wartosc;
}

string wypiszOsemkowy(int wartosc) {
    string napis = "";
    do {
        int cyfra = wartosc % 8;
        napis = to_string(cyfra) + napis;
        wartosc /= 8;
    } while (wartosc > 0);
    return napis;
}

int main() {
    int n;
    cout << "Podaj długość naszej liczby: ";
    cin >> n;
    
    cout << "Podaj cyfry danej liczby po spacjach lub enterach: ";
    int T[n];
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int wartosc = konwertujNaDziesiatkowy(T, n);
    cout << "Wartość w systemie 10: " << wartosc << endl;

    cout << "Wartość w systemie 8:  " << wypiszOsemkowy(wartosc) << endl;

    return 0;
}