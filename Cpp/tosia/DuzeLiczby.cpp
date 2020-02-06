#include <iostream>

using namespace std;

int m, n;
int ceny[1000][1000];

int porownajSklepy(int sklep1, int sklep2) {
    int wynik = 0;
    for (int produkt = 0; produkt < n; produkt++) {
        int cena1 = ceny[sklep1][produkt];
        int cena2 = ceny[sklep2][produkt];
        wynik += (cena1 < cena2) ? cena1 : cena2;
    }
    return wynik;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //cout << i << "\t" << j << "\t";
            cin >> ceny[i][j];

        }
    }

    int sumaMin = porownajSklepy(0, 1);
    for (int sklepA = 0; sklepA <= m-1; sklepA++) {
        for (int sklepB = 0; sklepB <= m-1; sklepB++) {
            if (sklepA >= sklepB) continue;
            int wynik = porownajSklepy(sklepA, sklepB);
            if (wynik < sumaMin) sumaMin = wynik;
        }
    }

    cout << sumaMin << endl;

    return 0;
}