// Zad 21
//#include <iostream>
//#include <cmath>
//
//using std::cout;
//using std::cin;
//using std::string;
//
//bool isPrime(int n) {
//    if (n <= 1) return false;
//    if (n == 2) return true;
//    for (int i = 2; i < (int)sqrt(n); i++) {
//        if (n%i == 0) return false;
//    }
//    return true;
//}
//
//int main() {
//    int n;
//    cout << "Podaj liczbę: "; cin >> n;
//    cout << "Ta liczba " << ((isPrime(n))?"jest":"nie jest") << " pierwsza.\n";
//    return 0;
//}

// Zad 22
//#include <iostream>
//
//using std::cout;
//using std::cin;
//
//int abs(int x) {
//    return ((x >= 0) ? x : -x);
//}
//
//int fact(int n) {
//    if (n == 0) return 1;
//    return n * fact(n-1);
//}
//
//int newton1(int n, int k) {
//    if (k == 0) return 1;
//    if (k == n) return 1;
//    return newton1(n-1, k-1) + newton1(n-1, k);
//}
//
//int newton2(int n, int k) {
//    if (k == 0) return 1;
//    if (k == n) return 1;
//    int up = 1, dn = 1;
//    for (int i = 0; i <= k-1; i++) {
//        up *= (n - i);
//    }
//    return up/fact(k);
//}
//
//int main() {
//    int n, k;
//    cout << "SYMBOL NEWTONA!!! (n k)\n";
//    cout << "     n = "; cin >> n; n = abs(n);
//    cout << "     k = "; cin >> k; k = abs(k);
//    cout << " (n k) = " << newton1(n, k) << "\n";
//    cout << " (n k) = " << newton2(n, k) << "\n";
//    return 0;
//}

// Zad 23
//#include <iostream>
//
//using std::cout;
//using std::cin;
//
//double f(int n) {
//    return (n*1.0)/(n+1); 
//}
//
//double S(int n) {
//    double s = 0.0;
//    for (int i = 1; i <= n; i++) s += f(i);
//    return s;
//}
//
//int main() {
//    int n;
//    cout << "Podaj liczbę: "; cin >> n;
//    cout << "Wynik: " << S(n) << "\n";
//    return 0;
//}

// Zad 24
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using std::cout;
//using std::cin;
//
//int main() {
//    srand(time(NULL));
//    int s;
//    int nold, nnew;
//    cout << "METODA do-while:\n";
//    s = 0;
//    nold = -1; 
//    nnew = rand()%21;
//    cout << nnew << "\t";
//    s += nnew;
//    do {
//        nold = nnew;
//        nnew = rand()%21;
//        cout << nnew << "\t";
//        s += nnew;
//    } while (nold != nnew);
//    cout << "\n" << s << "\n";
//
//    cout << "METODA while:\n";
//    s = 0;
//    nold = -1; 
//    while (nold != nnew) {
//        nold = nnew;
//        nnew = rand()%21;
//        cout << nnew << "\t";
//        s += nnew;
//    }
//    cout << "\n" << s << "\n";
//
//    return 0;
//}

// Zad 25
//#include <iostream>
//
//using std::cin;
//using std::cout;
//
//
//double power(int a, int n) {
//    double s = 1;
//    if (n < 0) {
//        for (int i = 1; i <= -n; i++) s /= a;
//    } else if (n > 0) {
//        for (int i = 1; i <= n; i++) s *= a;
//    }
//    return s;
//}
//
//int main() {
//    int a, n;
//    cout << "POTĘGA!!! (a^n)\n";
//    cout << "   a = "; cin >> a;
//    cout << "   n = "; cin >> n;
//    cout << " a^n = " << power(a,n) << "\n";
//    return 0;
//}

// Zad 26
//#include <iostream>
//
//using std::cin;
//using std::cout;
//
//int abs(int x) {
//    return ((x >= 0) ? x : -x);
//}
//
//int gcd(int a, int b) {
//    while (a != b) {
//        if (a > b) a -= b;
//        else b -= a;
//    }
//    return a;
//}
//
//int main() {
//    int a, b;
//    cout << "ALGORYTM EUKLIDESA - NWD(a, b)\n";
//    cout << "         a = "; cin >> a; a = abs(a);
//    cout << "         b = "; cin >> b; b = abs(b);
//    cout << " NWD(a, b) = " << gcd(a,b) << "\n";
//    return 0;
//}

// Zad 27
//#include <iostream>
//
//using std::cin;
//using std::cout;
//
//int abs(int x) {
//    return ((x >= 0) ? x : -x);
//}
//
//int gcd(int a, int b) {
//    while (a != b) {
//        if (a > b) a -= b;
//        else b -= a;
//    }
//    return a;
//}
//
//int lcm(int a, int b) {
//    return (a*b)/(gcd(a, b));
//}
//
//int main() {
//    int a, b;
//    cout << "         a = "; cin >> a; a = abs(a);
//    cout << "         b = "; cin >> b; b = abs(b);
//    cout << " NWD(a, b) = " << lcm(a,b) << "\n";
//    return 0;
//}

// Zad 28
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int abs(int x) {
    return ((x >= 0) ? x : -x);
}

bool isPerfect(int n) {
    int suma = 0;
    for (int p = sqrt(n); p > 1; p--) {
        if (n % p == 0) {
            suma += p;
            int p1 = n/p;
            if (p1 != p) {
                suma += p1;
            }
        }
    }
    if (suma+1 == n) return true;
    return false;
}

int main() {
    int n;
    cout << "Podaj liczbę: "; cin >> n; n = ((n>0)?n:0);
    cout << "Ta liczba " << ((isPerfect(n))?"jest":"nie jest") << " doskonała.\n";
    return 0;
}
