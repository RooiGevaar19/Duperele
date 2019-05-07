#include <cstdio>

int main() {
    int x, y;
    printf("Podaj współrzędną x [-10, 10]: "); scanf("%i", &x);
    printf("Podaj współrzędną y [-10, 10]: "); scanf("%i", &y);

    bool guess = true;
    if (x*x > 100 || y*y > 100) { // czy x,y należą do [-10, 10]
        guess = false;
    } else {
        int r = 7;
        if (y >= x + 10) {
            guess = true;
        } else {
            if (x >= 0 && y <= 0) {
                if (y < x - 10 || x*x + y*y <= r*r) guess = false;
            } else {
                guess = false;
            }
        }
    }
    printf("Ten punkt%snależy do figury.\n", ((guess)?" ":" nie "));
    return 0;
}
