#include <iostream>

using namespace std;

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

    return 0;
}