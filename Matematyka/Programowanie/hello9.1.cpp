// Wskaźniki - Zad 2
#include <cstdio>
#include <cstdlib>
#include <ctime>

void fill_random(int T[], int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        T[i] = rand()%(b-a+1)+a;
    }
}

void zad2_3() {
    int n = 3;
    int *w = &n;
    printf("=== Zadanie 2\n");
    printf("Adres   : %p\n", w);
    printf("Wartość : %i\n", *w);

    int *s = &n;
    printf("=== Zadanie 3\n");
    printf("Adres   : %p\n", s);
    printf("Wartość : %i\n", *s);
}

void zad8_9() {
    int tab[10];
    fill_random(tab, 10, 0, 10);
    int *w = tab[0];
    printf("=== Zadanie 8\n");
    printf("Adres   : %p\n", w);
    printf("Wartość : %i\n", *w);

}

int main() {
    srand(time(NULL));
    zad2_3();
    zad8_9();
    return 0;
}