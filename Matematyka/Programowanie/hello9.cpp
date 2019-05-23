//// Zad 47
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
//    for (int i = 2; i <= (int)sqrt(n); i++) {
//        if (n%i == 0) return false;
//    }
//    return true;
//}
//
//int main() {
//    int n;
//    cout << "Podaj liczbe n: "; cin >> n;
//    if (n >= 2) {
//        cout << "[";
//        for (int i = 2; i <= n; i++) {
//            if (isPrime(i)) cout << i << ", ";
//        }
//        cout << "\b\b]\n";
//    }
//    return 0;
//}

// Zad 48
//#include<iostream>
//using namespace std;
//void F1(int &i);
//void F2(int i);
//
//int main() {
//    int n = 2;
//    cout<<n<<endl;
//    F2(n);
//    cout<<n<<"\n";
//    F1(n);
//    cout<<n<<"\n";
//}
//
//void F1(int &i) {
//    i=i+5;
//}
//
//void F2(int i) {
//    i=i+5;
//}

//// Zad 49
//#include <cstdio>
//#include <iostream>
//
//using std::cin;
//using std::cout;
//
//int czarymary(int &a, int &b) {
//    a *= 2;
//    b += 100;
//}
//
//int main() {
//    int x, y;
//    cout << "Podaj pierwsza liczbe : "; cin >> x;
//    cout << "Podaj druga liczbe    : "; cin >> y;
//    czarymary(x,y);
//    cout << "CZARY MARY!\n";
//    cout << "Pierwsza liczba : " << x << "\n";
//    cout << "Druga liczba    : " << y << "\n";
//    return 0;
//}

//// Zad 50
//#include <iostream>
//#include <cstdio>
//
//using std::cin;
//using std::cout;
//
//float prost(float dlug, float szer, float wys, float &objetosc);
//
//int main() {
//    float a, b, c, S, V;
//    cout << "Podaj pierwszą krawędź : "; cin >> a;
//    cout << "Podaj drugą krawędź    : "; cin >> b;
//    cout << "Podaj trzecią krawędź  : "; cin >> c;
//    S = prost(a,b,c,V);
//    cout << "Pole powierzchni       : " << S << "\n";
//    cout << "Objętość               : " << V << "\n";
//    return 0;
//}
//
//float prost(float dlug, float szer, float wys, float &objetosc) {
//    objetosc = dlug*szer*wys;
//    return 2*(dlug*szer + dlug*wys + szer*wys);
//}

//// Zad 51
//#include <cstdio>
//
//int max2(int a, int b) {
//    return (a >= b) ? a : b;
//}
//
//int max3(int a, int b, int c) {
//    if (a >= max2(b, c)) {
//        return a;
//    } else if (b >= max2(a, c)) {
//        return b;
//    } else {
//        return c;
//    }
//}
//
//int main() {
//    int a,b,c;
//    printf("Podaj wspolczynnik a: "); scanf("%i", &a);
//    printf("Podaj wspolczynnik b: "); scanf("%i", &b);
//    printf("Podaj wspolczynnik c: "); scanf("%i", &c);
//    if (a != b && b != c && c != a) {
//        printf("max = %i\n", max3(a,b,c));
//    } else {
//        printf("Liczby mają być różne!\n");
//    }
//    return 0;
//}

// Zad 52
//#include<iostream>
//#include<ctime>
//using namespace std;
//void dane(int &n, int tab[]);
//void wyswietl(int n, int tab[]);
//
//int main() {
//    int X[10],Y[10], n;
//    srand(time(NULL));
//    dane(n,X);
//    wyswietl(n,X);
//    dane(n,Y);
//    wyswietl(n,Y);
//}
//void dane(int &n, int tab[]) {
//    cout<<"Podaj rozmiar wektora (n<=10): ";
//    cin>>n;
//    for(int i = 0; i <= n-1; i++)
//        tab[i]=rand()%10;
//}
//void wyswietl(int n,int tab[]) {
//    for(int i = 0; i <= n-1; i++) {
//        cout<<tab[i]<<" ";
//    }
//    cout<<endl;
//}

//// Zad 53
//#include <ctime>
//#include <cstdlib>
//#include <cstdio>
//
//void fill_random(int T[], int n, int a, int b) {
//    for (int i = 0; i < n; i++) {
//        T[i] = rand()%(b-a+1)+a;
//    }
//}
//
//void show_table(int T[], int n) {
//    if (n >= 1) {
//        printf("[");
//        for (int i = 0; i < n; i++) printf("%i, ", T[i]);
//        printf("\b\b]");
//    } else {
//        printf("[]");
//    }
//}
//
//int skalarny(int n, int X[], int Y[]) {
//    int s = 0;
//    for (int i = 0; i < n; i++) { 
//        s += X[i]*Y[i];
//    }
//    return s;
//}
//
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 5;
//    int T[n], U[n];
//    fill_random(T, n, a, b);
//    fill_random(U, n, a, b);
//    printf("Wektor 1         : "); show_table(T, n); printf("\n");
//    printf("Wektor 2         : "); show_table(U, n); printf("\n");
//    printf("Iloczyn skalarny : %i\n", skalarny(n, T, U));
//    return 0;
//}

// Zad 54
#include <ctime>
#include <cstdlib>
#include <cstdio>

void fillMatrix_random(int **T, int m, int n, int a, int b) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = rand()%(b-a+1)+a;
        }
    }
}

int findSum(int **T, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += T[i][i];
    }
    return s;
}

void showMatrix(int **T, int m, int n) {
    for (int j = 0; j < m; j++) {
        if (n >= 1) {
            printf("[");
            for (int i = 0; i < n; i++) printf("%i\t", T[j][i]);
            printf("\b\b]\n");
        } else {
            printf("[]\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int m = 5, n = m, a = 0, b = 100;
    
    int** tab = new int*[m];
    for (int i = 0; i < m; ++i)
        tab[i] = new int[n];

    fillMatrix_random(tab, m, n, a, b);

    printf("Suma na przekątnej : %i\n", findSum(tab, n));
    printf("\n");
    showMatrix(tab, m, n);

    for (int i = 0; i < m; ++i)
        delete [] tab[i];
    delete [] tab;

    return 0;
}