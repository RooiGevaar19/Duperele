#include <iostream>

using namespace std;

void bubblesort(int T[][2], int n) {
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

int main() {
    int n;
    cin >> n;
    int przedzialy[n][2];
    for (int i = 0; i < n; i++) {
        cin >> przedzialy[i][0] >> przedzialy[i][1];
    }
    bubblesort(przedzialy, n);

    int czesciWspolne = 0;
    for (int obecny = 1; obecny < n; obecny++) {
        for (int poprzednik = obecny-1; poprzednik >= 0; poprzednik--) {
            int a = przedzialy[poprzednik][0];
            int b = przedzialy[poprzednik][1];
            int c = przedzialy[obecny][0];
            int d = przedzialy[obecny][1];
            bool warunek1 = (a < c && b < c);
            bool warunek2 = (a > d && b > d);
            if (!(warunek1 || warunek2)) {
                czesciWspolne++;
            }
        }
    }

    cout << n - czesciWspolne << endl;

    return 0;
}