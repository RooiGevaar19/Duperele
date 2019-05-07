// zad 1
/*
#include <iostream>

int main() {
    printf("Hello world!\n");
    return 0;
}
*/

//zad 2
//#include <iostream>
//#include <cmath>
//#define _USE_MATH_DEFINES
//
//int main() {
//    double rad;
//    printf("Podaj liczbe w stopniach: ");
//    scanf("%lf", &rad);
//    printf("Miara w radianach: %lf\n", rad*(M_PI/180));
//    return 0;
//}

// zad 3
//#include <iostream>
//#include <cmath>
//#define _USE_MATH_DEFINES
//
//int main() {
//    double deg;
//    printf("Podaj temperature w stopniach: ");
//    scanf("%lf", &deg);
//    printf("Miara w radianach: %lf\n", 1.8*deg+32);
//    return 0;
//}

// zad 4
//#include <iostream>
//#include <cmath>
//#define _USE_MATH_DEFINES
//
//double f(double x) {
//    return x*x*x*x*x + 3*cos(x) + exp(4*x-7);
//}
//
//int main() {
//    double x;
//    printf("x = ");
//    scanf("%lf", &x);
//    printf("f(x) = %lf\n", f(x));
//    return 0;
//}

// zad 5
//#include <iostream>
//#include <cmath>
//
//double f(double a, double b, double c, double d, double x) {
//    return (a*x+b)*(c+d);
//}
//
//int main() {
//    double a, b, c, d, x;
//    printf("Podaj odpowiednio współczynniki a,b,c,d i argument x, oddzielone spacjami: ");
//    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &x);
//    printf("f(x) = %lf\n", f(a,b,c,d,x));
//    return 0;
//}

// zad 6
//#include <iostream>
//#include <cmath>
//
//int main() {
//    double x;
//    printf("x       = ");
//    scanf("%lf", &x);
//    printf("sqrt(x) = %lf\n", sqrt(x));
//    return 0;
//}

// zad 7
//#include <iostream>
//
//int main() {
//    int x, y;
//    printf("x   = "); scanf("%d", &x);
//    printf("y   = "); scanf("%d", &y);
//    if (x > 0 && y > 0) {
//        printf("x+y = %d\n", x+y);
//    } else {
//        printf("Któraś z tych liczb jest ujemna\n");
//    }
//    return 0;
//}

// zad 8
//#include <iostream>
//
//int main() {
//    double x;
//    printf("Podaj x: "); scanf("%lf", &x);
//    if (x > 0) {
//        printf("Liczba jest dodatnia\n");
//    } else if (x == 0) {
//        printf("Liczba jest równa zero.\n");
//    } else {
//        printf("Liczba jest ujemna.\n");
//    }
//    return 0;
//}

// zad 9
/*
#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    printf("RÓWNANIA KWADRATOWE !!!!!!!!1\n");
    printf("Podaj wspolczynnik a: "); scanf("%lf", &a);
    printf("Podaj wspolczynnik b: "); scanf("%lf", &b);
    printf("Podaj wspolczynnik c: "); scanf("%lf", &c);
    if (a == 0) {
        printf("To jest równanie liniowe!\n");
        if (b == 0) {
            if (c == 0) {
                printf("dowolny x rzeczywisty\n");
            } else {
                printf("brak rozwiązań\n");
            }
        } else {
            printf("x0 = %lf\n", -c/b);
        }
    } else {
        double delta = b*b - 4*a*c;
        if (delta < 0) {
            printf("brak rozwiązań rzeczywistych (są zespolone)\n");
        } else if (delta == 0) {
            printf("x0 = %lf\n", -b/(2*a));
        } else {
            printf("x1 = %lf\n", (-b-sqrt(delta))/(2*a));
            printf("x2 = %lf\n", (-b+sqrt(delta))/(2*a));
        }
    }
    return 0;
}
*/

// zad 10
#include <iostream>

double det(int a, int b, int c, int d) {
    return a*d - b*c;
}

int main() {
    double a, b, c, d, e, f;
    printf("{ ax + by = e\n");
    printf("{ cx + dy = f\n");
    printf("Podaj wspolczynnik a: "); scanf("%lf", &a);
    printf("Podaj wspolczynnik b: "); scanf("%lf", &b);
    printf("Podaj wspolczynnik c: "); scanf("%lf", &c);
    printf("Podaj wspolczynnik d: "); scanf("%lf", &d);
    printf("Podaj wspolczynnik e: "); scanf("%lf", &e);
    printf("Podaj wspolczynnik f: "); scanf("%lf", &f);
    
    double W = det(a, b, c, d);
    double Wx = det(e, b, f, d);
    double Wy = det(a, e, c, f);
    if (W == 0) {
        if (Wx == 0 && Wy == 0) {
            printf("Układ nieoznaczony\n");
        } else {
            printf("Układ sprzeczny\n");
        }
    } else {
        printf("x = %lf\n", Wx/W);
        printf("y = %lf\n", Wy/W);
    }
    return 0;
}

// zad 11
/*
#include <iostream>

int max3(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int a,b,c;
    printf("Podaj wspolczynnik a: "); scanf("%i", &a);
    printf("Podaj wspolczynnik b: "); scanf("%i", &b);
    printf("Podaj wspolczynnik c: "); scanf("%i", &c);
    if (a != b && b != c && c != a) {
        printf("max = %i\n", max3(a,b,c));
    } else {
        printf("Liczby mają być różne!\n");
    }
    return 0;
}
*/
