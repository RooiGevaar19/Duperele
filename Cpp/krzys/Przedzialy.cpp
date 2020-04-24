#include <iostream>

using namespace std;

void bubblesort_poczatek(int T[][2], int n) {
    for (int zasieg = n-1; zasieg > 0; zasieg--) {
        for (int i = 0; i < zasieg; i++) {
            // porównujemy początki przedziałów
            if (T[i][0] > T[i+1][0]) {
                // zamiana wartości początków przedziałów
                int pom1 = T[i][0];
                T[i][0] = T[i+1][0];
                T[i+1][0] = pom1;

                // zamiana wartości końców przedziałów
                int pom2 = T[i][1];
                T[i][1] = T[i+1][1];
                T[i+1][1] = pom2;
            }
        }
    }
}

void bubblesort_koniec(int T[][2], int n) {
    for (int zasieg = n-1; zasieg > 0; zasieg--) {
        for (int i = 0; i < zasieg; i++) {
            // porównujemy początki przedziałów
            if (T[i][1] > T[i+1][1]) {
                // zamiana wartości początków przedziałów
                int pom1 = T[i][0];
                T[i][0] = T[i+1][0];
                T[i+1][0] = pom1;

                // zamiana wartości końców przedziałów
                int pom2 = T[i][1];
                T[i][1] = T[i+1][1];
                T[i+1][1] = pom2;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int przedzialy[n][2];
    for (int i = 0; i < n; i++) {
        cin >> przedzialy[i][0] >> przedzialy[i][1];
    }
    bubblesort_poczatek(przedzialy, n);
    bubblesort_koniec(przedzialy, n);

    int czesciWspolne = 0;
    int szpary = 0;
    for (int obecny = 1; obecny < n; obecny++) {
        for (int poprzednik = obecny-1; poprzednik >= 0; poprzednik--) {
            int a = przedzialy[poprzednik][0];
            int b = przedzialy[poprzednik][1];
            int c = przedzialy[obecny][0];
            int d = przedzialy[obecny][1];
            // warunki na czesci wspolne
            bool warunek1 = (a <= c && b <= c);
            bool warunek2 = (a >= d && b >= d);
            // warunki na szpary
            bool warunek3 = (a < c && b+1 == c);
            bool warunek4 = (c < a && d+1 == a);
            if (!(warunek1 || warunek2)) {
                czesciWspolne++;
            }
            //if (warunek3 || warunek4) {
            //    szpary++;
            //}
        }
    }

    cout << n - czesciWspolne - szpary << endl;

    return 0;
}