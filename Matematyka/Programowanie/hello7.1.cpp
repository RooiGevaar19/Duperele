//// Zad dodatkowe 1
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
//int findSecondMax(int T[], int n) {
//    int index1 = 0, index2 = 0;
//    for (int i = 1; i < n; i++) 
//        if (T[i] > T[index1]) {
//            index2 = index1;
//            index1 = i;
//        }
//    return index2;
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
//    printf("Element drugi największy - indeks  : %i\n", findSecondMax(tab, n));
//    printf("Element drugi największy - wartość : %i\n", tab[findSecondMax(tab, n)]);
//    printf("Tablica               : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

//// Zad dodatkowe 2
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
//int findDominant(int T[], int n) {
//    int count = 0, val = 0;
//    for (int i = 0; i < n; i++) {
//        int pom = 0;
//        for (int j = 0; j < n; j++)
//            if (T[i] == T[j]) pom++;
//        if (pom > count) {
//            val = T[i];
//            count = pom;
//        }
//    }
//    return val;
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
//    int n = 10, a = 0, b = 10;
//    int tab[n];
//    fill_random(tab, n, a, b);
//
//    printf("Dominanta : %i\n", findDominant(tab, n));
//    printf("Tablica   : "); show_table(tab, n);
//    printf("\n");
//    return 0;
//}

//// Zad dodatkowe 3
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
//int scalarProduct(int T[], int U[], int n) {
//    int s = 0;
//    for (int i = 0; i < n; i++) {
//        s += T[i]*U[i];
//    }
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
//    int n = 10, a = 0, b = 10;
//    int tab1[n], tab2[n];
//    fill_random(tab1, n, a, b);
//    fill_random(tab2, n, a, b);
//
//    printf("Tablica 1        : "); show_table(tab1, n); printf("\n");
//    printf("Tablica 2        : "); show_table(tab2, n); printf("\n");
//    printf("Iloczyn skalarny : %i\n", scalarProduct(tab1, tab2, n));
//    printf("\n");
//    return 0;
//}

// Zad dodatkowe 4
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

void transpose(int **T, int **U, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            U[j][i] = T[i][j];
        }
    }
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
    int m = 10, n = 7, a = 0, b = 100;
    int x, y;
    
    int** t = new int*[m];
    for (int i = 0; i < m; ++i)
        t[i] = new int[n];

    int** u = new int*[n];
    for (int i = 0; i < n; ++i)
        u[i] = new int[m];

    fillMatrix_random(t, m, n, a, b);

    showMatrix(t, m, n);
    printf("\n");
    transpose(t, u, m, n);
    showMatrix(u, n, m);

    for (int i = 0; i < m; ++i)
        delete [] t[i];
    delete [] t;

    for (int i = 0; i < n; ++i)
        delete [] u[i];
    delete [] u;

    return 0;
}