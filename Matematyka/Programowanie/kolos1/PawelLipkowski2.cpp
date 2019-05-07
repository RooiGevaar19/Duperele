#include <cstdio>
#include <cmath>

int main() {
    int n;
    printf("Podaj liczbę naturalną (n >= 1): "); scanf("%i", &n); 
    if (n < 1) {
        printf("Podano liczbę mniejszą od 1.\n");
    } else {
        double a[n];
        for (int i = 1; i <= n; i++) {
            a[i] = log(1.0 - 1.0/(i+1.0));
        }
        double S = 0; 
        for (int i = 1; i <= n; i++) {
            S += a[i];
        }

        for (int i = 1; i <= n; i++) {
            printf("a_%i: %lf\n", i, a[i]);    
        }

        printf("Suma od i = 1 do %i: %lf\n", n, S);
    }
    return 0;
}