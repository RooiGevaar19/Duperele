#include <iostream>

using namespace std;

int main() {
    int n, k, k1, m;
    cout << "MNOŻENIE MACIERZY!" << endl;
    cout << "Podaj ilość wierszy w macierzy A: ";
    cin >> n;
    cout << "Podaj ilość kolumn w macierzy A: ";
    cin >> k;
    cout << "Podaj ilość wierszy w macierzy B: ";
    cin >> k1;
    cout << "Podaj ilość kolumn w macierzy B: ";
    cin >> m;

    cout << endl;

    if (k != k1) {
        cout << "Liczba kolumn A ma być równa liczbie wierszy B!" << endl;
    } else {
        int A[n][k];
        int B[k][m];

        // podaj macierze A i B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cout << "Podaj wyraz (" << i+1 << ", " << j+1 << ") macierzy A: ";
                cin >> A[i][j];
            }
        }
        cout << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Podaj wyraz (" << i+1 << ", " << j+1 << ") macierzy B: ";
                cin >> B[i][j];
            }
        }

        // zadeklaruj macierz wynikową S
        int S[n][m];

        // wyzeruj macierz wynikową
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                S[i][j] = 0;
            }
        }

        // dla każdego wiersza S
        for (int i=0; i<n; i++) {
            // dla każdej kolumny S
            for (int j=0; j<m; j++) {
                // S[i][j] = i-ty wiersz A * j-ta kolumna B
                for (int step=0; step<k; step++) {
                    S[i][j] += A[i][step] * B[step][j];
                }
            }
        }
    
        // wypisz macierz S
        cout << "WYNIK:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "[ ";
            for (int j = 0; j < m; j++) {
                cout << S[i][j] << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}