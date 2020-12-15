#include <iostream>

using namespace std;

bool moznaZbudowacTrojkat(int a, int b, int c) {
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;
    return true;
}

int main() {

    // wpisujemy tablicę
    int n;
    cout << "Podaj ilość liczb: ";
    cin >> n;

    int T[n];
    for (int i = 0; i < n; i++) {
        cout << "Podaj " << i+1 << ". element: ";
        cin >> T[i];
    }

    // sprawdzamy
    bool flaga = true;
    for         (int i = 0;   i < n-2; i++) {
        for     (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n;   k++) {
                if (!moznaZbudowacTrojkat(T[i], T[j], T[k])) {
                    flaga = false;
                    break;
                }
            }
            if (!flaga) break;
        }
        if (!flaga) break;
    }

    // alternatywnie
    //for         (int i = 0;   i < n-2 && flaga; i++) {
    //    for     (int j = i+1; j < n-1 && flaga; j++) {
    //        for (int k = j+1; k < n   && flaga; k++) {
    //            if (!moznaZbudowacTrojkat(T[i], T[j], T[k])) {
    //                flaga = false;
    //            }
    //        }
    //    }
    //}

    // wypisujemy
    if (flaga) {
        cout << "Można ze wszystkich kombinacji boków zbudować trójkąt." << endl;
    } else {
        cout << "Istnieje kombinacja boków, z której nie zbudujemy trójkąta." << endl;
    }

	return 0;
}


// kombinacje różnych trójek w zbiorze N-elementowym
//
// 1,2,3   1,3,4   1,4,5   ...     1, N-1, N
// 1,2,4   1,3,5   1,4,6
// 1,2,5   1,3,6   1,4,7
// 1,2,6   1,3,7   ...
// 1,2,7   …       1,4,N
// …       1,3,N
// 1,2,N
// 
// 2,3,4   2,4,5   2,5,6   ...     2, N-1, N
// 2,3,5   2,4,6   2,5,7
// 2,3,6   2,4,7   ...
// 2,3,7   …       2,5,N
// …       2,4,N
// 2,3,N
// 
// 3,4,5   3,5,6   3,6,7   ...     3, N-1, N
// 3,4,6   3,5,7   ...
// 3,4,7   …       3,6,N
// …       3,5,N
// 3,4,N
// 
// ...
// 
// N-2, N-1, N