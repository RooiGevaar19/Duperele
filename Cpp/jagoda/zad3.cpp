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

    int suma = T[0]; 
    int min = 0;
    int max = 0;

    for (int i = 1; i <= n-1; i++) {
        suma += T[i];
        if (T[i] < T[min]) min = i;
        if (T[i] > T[max]) max = i;
    }

    cout << "Suma:     " << suma << endl;
    cout << "Minimum:  " << T[min] << endl;
    cout << "Maksimum: " << T[max] << endl;

    return 0;
}