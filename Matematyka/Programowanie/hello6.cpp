// Zad 37
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
//void show_table_modified(int T[], int n, int p) {
//    if (n >= 1) {
//        printf("[");
//        for (int i = 0; i < n; i++)
//            if (T[i] % p == 0) printf("%i, ", T[i]);
//        printf("\b\b]");
//    } else {
//        printf("[]");
//    }
//}
//
//int main() {
//    srand(time(NULL));
//    int n = 100, a = 0, b = 10, p;
//    int tab[100];
//    fill_random(tab, n, a, b);
//
//    printf("Podaj liczbę p [1, %i]: ", b); scanf("%i", &p);
//
//    if (p >= 1 && p <= b) {
//        printf("Before: "); show_table(tab, n);
//        printf("\n");
//        printf("After : "); show_table_modified(tab, n, p);
//        printf("\n");
//    } else {
//        printf("Zjebałeś. XD\n");
//    }
//    return 0;
//}

// Zad 38
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
//int findMin(int T[], int n) {
//    int index = 0, val = T[0];
//    for (int i = 0; i < n; i++) 
//        if (T[i] < val) {
//            index = i;
//            val = T[i];
//        }
//    return index;
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
//    printf("Element min - indeks  : %i\n", findMin(tab, n));
//    printf("Element min - wartość : %i\n", tab[findMin(tab, n)]);
//    printf("Tablica               : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

// Zad 39
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
//int findMaxSum(int T[], int n) {
//    int index = 0, val = T[0]+T[1];
//    for (int i = 1; i < n-1; i++) 
//        if (T[i]+T[i+1] > val) {
//            index = i;
//            val = T[i]+T[i+1];
//        }
//    return index;
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
//    int tab[n];
//    fill_random(tab, n, a, b);
//
//    printf("Elementy o max sumie : %i, %i\n", tab[findMaxSum(tab, 100)], tab[findMaxSum(tab, 100)+1]);
//    printf("Tablica              : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

// Zad 40
#include <ctime>
#include <cstdlib>
#include <cstdio>

struct coords {
    int x, y;
};

void fillMatrix_random(int **T, int m, int n, int a, int b) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = rand()%(b-a+1)+a;
        }
    }
}

coords findMaxSum(int **T, int m, int n) {
    coords index = {0, 0};
    int val = T[index.x][index.y];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (T[i][j] > val) {
                index.x = i;
                index.y = j;
                val = T[i][j];
            }
    return index;
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
    int m = 10, n = 10, a = 0, b = 100;
    
    int** tab = new int*[m];
    for (int i = 0; i < m; ++i)
        tab[i] = new int[n];

    fillMatrix_random(tab, m, n, a, b);

    printf("Element max - indeks  : %i, %i\n", findMaxSum(tab,m,n).x+1, findMaxSum(tab,m,n).y+1);
    printf("Element max - wartość : %i\n", tab[findMaxSum(tab,m,n).x][findMaxSum(tab,m,n).y]);
    printf("\n");
    showMatrix(tab, m, n);

    for (int i = 0; i < m; ++i)
        delete [] tab[i];
    delete [] tab;

    return 0;
}