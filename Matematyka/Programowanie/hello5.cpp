// Zad 29
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//void print_tree(int h) {
//    for (int i = h; i >= 0; i--) {
//        for (int j = 0; j < i; j++) printf(" ");
//        for (int j = i; j < h+(h-i-1); j++) printf("*");
//        printf("\n");
//    }
//}
//
//int main() {
//    int h;
//    printf("Podaj wysokość choinki: "); scanf("%i", &h);
//    print_tree(h);
//    return 0;
//}

// Zad 30
//#include <cstdio>
//
//int main() {
//    int h;
//    printf("Podaj liczbę: "); scanf("%i", &h);
//    for (int i = 1; i <= h; i++) {
//        for (int j = 1; j <= i; j++) {
//            printf("%i\t", j*i);
//        }
//        printf("\n");
//    }
//    return 0;
//}

// Zad 31
//#include <cstdio>
//#include <cmath>
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
//    printf("Podaj liczbę: "); scanf("%i", &n);
//    if (n >= 2) {
//        printf("[");
//        for (int i = 2; i <= n; i++) {
//            if (isPrime(i)) {
//                printf("%i, ", i);
//            }
//        }
//        printf("\b\b]\n");
//    } else {
//        printf("[]\n");
//    }
//    return 0;
//}

// Zad 32
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
//double avg(int T[], int n) {
//    double s = 0.0;
//    for (int i = 0; i < n; i++) s += T[i];
//    return s/n;
//}
//
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 100;
//    int tab[n];
//    fill_random(tab, n, a, b);
//    printf("Avg: %lf\n", avg(tab, 100));
//    return 0;
//}

// Zad 33
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
//int count(int T[], int n, int cat) {
//    int s = 0;
//    for (int i = 0; i < n; i++) s += ((T[i] == cat)?1:0);
//    return s;
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
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 100;
//    int tab[100];
//    fill_random(tab, n, a, b);
//
//    int cat;
//    printf("Podaj liczbę    : "); scanf("%i", &cat);
//    printf("Liczba wystąpień: %i\n", count(tab, n, cat));
//    printf("Tablica         : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

// Zad 34
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
//int countOdd(int T[], int n) {
//    int s = 0;
//    for (int i = 0; i < n; i++) s += ((T[i] % 2 != 0) ? 1 :0);
//    return s;
//}
//
//int sumOdd(int T[], int n) {
//    int s = 0;
//    for (int i = 0; i < n; i++) s += ((T[i] % 2 != 0) ? T[i] : 0);
//    return s;
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
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 100;
//    int tab[100];
//    fill_random(tab, n, a, b);
//
//    printf("Ilość liczb nieparzystych: %i\n", countOdd(tab, n));
//    printf("Suma liczb nieparzystych : %i\n", sumOdd(tab, n));
//    printf("Tablica                  : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

// Zad 35
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
//void squareAll(int T[], int n) {
//    for (int i = 0; i < n; i++) T[i] = T[i]*T[i];
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
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 10;
//    int tab[100];
//    fill_random(tab, n, a, b);
//
//    printf("Before: "); show_table(tab, n);
//    printf("\n");
//    squareAll(tab, n);
//    printf("After : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

// Zad 36
#include <ctime>
#include <cstdlib>
#include <cstdio>

void fill_random(int T[], int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        T[i] = rand()%(b-a+1)+a;
    }
}

bool inRange(int x, int a, int b) {
    if (a < b && x >= a && x <= b) return true;
    return false;    
}

void show_table(int T[], int n) {
    if (n >= 1) {
        printf("[");
        for (int i = 0; i < n; i++) printf("%i, ", T[i]);
        printf("\b\b]");
    } else {
        printf("[]");
    }
}

void show_table_modified(int T[], int n, int a, int b) {
    if (n >= 1) {
        printf("[");
        for (int i = 0; i < n; i++)
            if (inRange(T[i], a, b)) printf("%i, ", T[i]);
        printf("\b\b]");
    } else {
        printf("[]");
    }
}

int main() {
    srand(time(NULL));
    int n = 100, a = 0, b = 10, c = 5, d = 8;
    int tab[100];
    fill_random(tab, n, a, b);

    printf("Before: "); show_table(tab, n);
    printf("\n");
    printf("After : "); show_table_modified(tab, n, c, d);
    printf("\n");
    return 0;
}