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

bool isLowerTriangular(int **T, int m, int n) {
    for (int i = 1; i < m; i++)
        for (int j = 0; j < i; j++)
            if (T[i][j] != 0)
                return false;
    return true;
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

void showArray(int T[], int n) {
    if (n >= 1) {
        printf("[");
        for (int i = 0; i < n; i++) printf("%i, ", T[i]);
        printf("\b\b]");
    } else {
        printf("[]");
    }
}


int main() {
    srand(time(NULL));
    int m = 10, n = 10, a = 0, b = 16;
    
    int** A = new int*[m];
    for (int i = 0; i < m; ++i)
        A[i] = new int[n];

    fillMatrix_random(A, m, n, a, b);
    printf("Macierz: \n");
    showMatrix(A, m, n);
    printf("\n");

    int tab[10];
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j <= 9; j++) {
            s += A[i][j];
        }
        tab[i] = s;
    }

    printf("Tablica sum wierszy:\t");
    showArray(tab, 10);
    printf("\n");

    for (int i = 0; i < m; ++i)
        delete [] A[i];
    delete [] A;

    return 0;
}
