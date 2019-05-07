// Zad 12
/*
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int max3(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

bool isPitagorean(int a, int b, int c) {
    if (max3(a,b,c) == a) {
        return a*a == b*b+c*c;
    } else if (max3(a,b,c) == b) {
        return b*b == a*a+c*c;
    } else {
        return c*c == b*b+a*a;
    }
}

int main() {
    int a, b, c;
    cout << "Podaj 3 liczby: \n";
    cin >> a >> b >> c;
    a = abs(a);
    b = abs(b);
    c = abs(c);
    cout << "To " << (isPitagorean(a,b,c)?"jest":"nie jest") << " trójka pitagorejska.\n"; 
    return 0;
}
*/

// Zad 13
/*
#include <iostream>

int main() {
    int ocena;
    printf("Podaj ocenę w liczbie: "); scanf("%i", &ocena);
    switch (ocena) {
        case 2 : {
            printf("To jest ocena niedostateczna\n"); 
            break;
        }
        case 3 : {
            printf("To jest ocena dostateczna\n"); 
            break;
        }
        case 4 : {
            printf("To jest ocena dobra\n"); 
            break;
        }
        case 5 : {
            printf("To jest ocena bardzo dobra\n"); 
            break;
        }
        case 6 : {
            printf("To jest ocena celująca\n"); 
            break;
        }
        default : {
            printf("To jest żadna ocena\n");
            break;
        }
    }
    return 0;
}
*/

// Zad 14
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    
    char operand;
    cout << "2 + 2 !!!!\n";
    cout << "Podaj liczbę a\n"; cin >> a;
    cin >> s;

    return 0;
}
