//// Zad 56
//#include <iostream>
//using namespace std;
//int main () {
//    int n, k;
//    cout << "Podaj kolejno n i k: " << endl;
//    cin >> n >> k;
//
//    int sn = 1;
//    for (int i = 2;i<=n; i++)
//        sn = sn*i;
//
//    int sk = 1;
//    for (int i = 2;i<=k; i++)
//        sk = sk*i;
//
//    int snk = 1;
//    for (int i = 2;i<=n-k; i++)
//        snk = snk*i;
//    
//    int *x = &sn, *y = &sk, *z = &snk;
//
//    cout << "Symbol Newtona n nad k wynosi " << *x / (*y * *z) << "\n";
//    return 0;
//}

// Zad 57
//#include <iostream>
//#include <ctime>
//#include <cstdlib>
//using namespace std;
//int main() {
//    srand(time(NULL));
//    int tab[10];
//    int n;
//    int *wtab = tab;
//    int *wn = &n;
//    cout << "Podaj rozmiar tablicy (n <= 10): ";
//    cin >> *wn;
//    for (int i = 0; i < *wn; i++) {
//        *wtab = rand()%10;
//        wtab++;
//    }
//    wtab = tab;
//    for (int i = 0; i < *wn; i++) {
//        cout << *(wtab + i) << " ";
//    }
//
//    int *min = &tab[0];
//    for (int i = 0; i < *wn; i++) {
//        if (*(wtab + i) < *min) {
//            min = wtab+i;
//        }
//    }
//
//    cout << endl << "Minimalny element tablicy to " << *min << endl;
//    return 0;
//}

// Zad 58
