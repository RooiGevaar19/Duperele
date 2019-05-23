// Zad 44
//#include <cstdio>
//#include <cmath>
//
//double sqrt4(double x) {
//    return sqrt(sqrt(x));
//}
//
//double sqr(double x) {
//    return x*x;
//}
//
//double f(double x) {
//    return sqrt4(x*x + sqr(x+3)) + 5*sqrt4(sqr(3*x)+100);
//}
//
//int main() {
//    double x;
//    printf("x    = "); scanf("%lf", &x);
//    printf("f(x) = %lf\n", f(x));
//    return 0;
//}

//Zad 45
//#include <cstdio>
//#include <cmath>
//
//int iloczyn(int a, int b);
//int iloczyn();
//void iloczyn2(int a, int b);
//void iloczyn2();
//
//int main() {
//    int a, b;
//    printf("====== TEST 1\n");
//    printf("Podaj a: "); scanf("%i", &a);
//    printf("Podaj b: "); scanf("%i", &b);
//    printf("%i\n", iloczyn(a, b));
//
//    printf("====== TEST 2\n");
//    printf("%i\n", iloczyn());
//
//    printf("====== TEST 3\n");
//    printf("Podaj a: "); scanf("%i", &a);
//    printf("Podaj b: "); scanf("%i", &b);
//    iloczyn2(a, b);
//
//    printf("====== TEST 4\n");
//    iloczyn2();
//
//    return 0;
//}
//
//int iloczyn(int a, int b) {
//    return a*b;
//}
//int iloczyn() {
//    int a, b;
//    printf("Podaj a: "); scanf("%i", &a);
//    printf("Podaj b: "); scanf("%i", &b);
//    return a*b;
//}
//
//void iloczyn2(int a, int b) {
//    printf("%i\n", a*b);
//}
//void iloczyn2() {
//    int a, b;
//    printf("Podaj a: "); scanf("%i", &a);
//    printf("Podaj b: "); scanf("%i", &b);
//    printf("%i\n", a*b);
//}

// Zad 46
#include <iostream>
using namespace std;

float potega(float a, int f) {
    int s = 1;
    for (int i = 1; i <= f; i++) s *= a;
    return s;
}

int main() {
    float a,b,c,n;
    cout<<"Podaj kolejno liczby a,b,c,n:";
    cin>>a>>b>>c>>n;
    float wynik = (potega(a,n)+potega(b,n+5))/potega(c, 2*n+1);
    cout<<"Wartosc wyrazenia to "<<wynik<<"\n";
}