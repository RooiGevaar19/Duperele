#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Podaj stopień wielomianu: ";
    cin >> n;

    int A[n+1];
    for (int i = n; i >= 0; i--) {
        cout << "Podaj współczynnik wielomianu przy potedze " << i << ": ";
        cin >> A[i];
    }

    int x;
    cout << "Podaj argument wielomianu: ";
    cin >> x;

    int wynik = A[n];
    for (int i = n-1; i >= 0; i--) {
        wynik = wynik*x + A[i];
    }

    cout << "W(" << x << ") = " << wynik << endl;

    return 0;
}