//// Zad 41
//#include <ctime>
//#include <cstdlib>
//#include <cstdio>
//
//void fillMatrix_random(int **T, int m, int n, int a, int b) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            T[i][j] = rand()%(b-a+1)+a;
//        }
//    }
//}
//
//void fillMatrix_random2(int **T, int m, int n, int a, int b) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i > j) T[i][j] = 0;
//            else T[i][j] = rand()%(b-a+1)+a;
//        }
//    }
//}
//
//bool isLowerTriangular(int **T, int m, int n) {
//    for (int i = 1; i < m; i++)
//        for (int j = 0; j < i; j++)
//            if (T[i][j] != 0)
//                return false;
//    return true;
//}
//
//void showMatrix(int **T, int m, int n) {
//    for (int j = 0; j < m; j++) {
//        if (n >= 1) {
//            printf("[");
//            for (int i = 0; i < n; i++) printf("%i\t", T[j][i]);
//            printf("\b\b]\n");
//        } else {
//            printf("[]\n");
//        }
//    }
//}
//
//int main() {
//    srand(time(NULL));
//    int m = 10, n = 10, a = 0, b = 100;
//    
//    int** tab = new int*[m];
//    for (int i = 0; i < m; ++i)
//        tab[i] = new int[n];
//
//    fillMatrix_random2(tab, m, n, a, b);
//
//    printf("Macierz%sjest trójkątna dolna.\n", (isLowerTriangular(tab, m, n))?" ":" nie ");
//    printf("\n");
//    showMatrix(tab, m, n);
//
//    for (int i = 0; i < m; ++i)
//        delete [] tab[i];
//    delete [] tab;
//
//    return 0;
//}

//// Zad 42
//#include <ctime>
//#include <cstdlib>
//#include <cstdio>
//#include <bits/stdc++.h> 
//
//int cutToRange(int val, int lower, int upper) {
//    return (val+(upper-lower))%(upper-lower)+lower;
//}
//
//void fillMatrix_random(int **T, int m, int n, int a, int b) {
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            T[i][j] = rand()%(b-a+1)+a;
//        }
//    }
//}
//
//void swapVerses(int **T, int m, int n, int x, int y) {
//    if (x < m && y < m && x >= 0 && y >= 0) {
//        for (int i = 0; i < n; i++) {
//            std::swap(T[x][i], T[y][i]);
//        }
//    }
//}
//
//void showMatrix(int **T, int m, int n) {
//    for (int j = 0; j < m; j++) {
//        if (n >= 1) {
//            printf("[");
//            for (int i = 0; i < n; i++) printf("%i\t", T[j][i]);
//            printf("\b\b]\n");
//        } else {
//            printf("[]\n");
//        }
//    }
//}
//
//int main() {
//    srand(time(NULL));
//    int m = 10, n = 10, a = 0, b = 100;
//    int x, y;
//    
//    int** tab = new int*[m];
//    for (int i = 0; i < m; ++i)
//        tab[i] = new int[n];
//
//    fillMatrix_random(tab, m, n, a, b);
//
//    showMatrix(tab, m, n);
//    printf("\n");
//    printf("Podaj wiersz, który chcesz zamienić [1, %i]       : ", m); scanf("%i", &x); x = cutToRange(x-1, 0, m);
//    printf("Podaj wiersz, z którym chcesz go zamienić [1, %i] : ", m); scanf("%i", &y); y = cutToRange(y-1, 0, m);
//    printf("\n");
//    swapVerses(tab, m, n, x, y);
//    showMatrix(tab, m, n);
//
//    for (int i = 0; i < m; ++i)
//        delete [] tab[i];
//    delete [] tab;
//
//    return 0;
//}

// Zad 43
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h> 

int cutToRange(int val, int lower, int upper) {
    return (val+(upper-lower))%(upper-lower)+lower;
}

void fillMatrix_random(int **T, int m, int n, int a, int b) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = rand()%(b-a+1)+a;
        }
    }
}

void swapDiagonals(int **T, int m, int n) {
    if (m == n) {
        for (int i = 0; i < n; i++) {
            std::swap(T[i][i], T[i][n-i-1]);
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
    int m = 10, n = 10, a = 0, b = 100;
    int x, y;
    
    int** tab = new int*[m];
    for (int i = 0; i < m; ++i)
        tab[i] = new int[n];

    fillMatrix_random(tab, m, n, a, b);

    showMatrix(tab, m, n);
    printf("\n");
    swapDiagonals(tab, m, n);
    showMatrix(tab, m, n);

    for (int i = 0; i < m; ++i)
        delete [] tab[i];
    delete [] tab;

    return 0;
}