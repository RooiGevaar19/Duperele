// Zad 15
/*
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

double surface(double a) {
    return a*a;
}

double surface(double a, double b) {
    return a*b;
}

double surface(double a, double b, double c) {
    return sqrt((a+b+c)*(a+b-c)*(a-b+c)*(b+c-a))/4;
}

int main() {
    int command;
    cout << "Pole jakiej figury chcesz obliczyć?\n";
    cout << "   1 - Kwadrat\n   2 - Prostokąt\n   3 - Trójkąt\n> ";
    cin >> command;
    switch (command) {
        case 1 : {
            double a;
            cout << "Podaj długość boku: "; cin >> a;
            cout << "Pole: " << surface(a) << "\n";
            break;
        }
        case 2 : {
            double a, b;
            cout << "Podaj długość boku pierwszego: "; cin >> a;
            cout << "Podaj długość boku drugiego: "; cin >> b;
            cout << "Pole: " << surface(a, b) << "\n";
            break;
        }
        case 3 : {
            double a, b, c;
            cout << "Podaj długość boku pierwszego: "; cin >> a;
            cout << "Podaj długość boku drugiego: "; cin >> b;
            cout << "Podaj długość boku trzeciego: "; cin >> c;
            cout << "Pole: " << surface(a, b, c) << "\n";
            break;
        }
        default : {
            cout << "Błąd!\n";
            break;
        }
    }
    return 0;
}
*/
// Zad 16
/*
#include <iostream>
#include <cstring>

using namespace std;

bool isValid(char category) {
    if (category == 'A') return true;
    if (category == 'B') return true;
    if (category == 'C') return true;
    if (category == 'D') return true;
    return false;
}

double wage(char category) {
    if (category == 'A') return 15.0;
    if (category == 'B') return 25.0;
    if (category == 'C') return 30.0;
    if (category == 'D') return 35.0;
    return 0.0;
}

double salary(int hours, int category) {
    if (hours <= 40) {
        return hours * wage(category);
    } else {
        return 40*wage(category) + (hours-40)*2*wage(category);
    }
}

double addTax(double money) {
    if (money <= 700) {
        return 1.15*money;
    } else if (money <= 1200) {
        return 1.2*money;
    } else {
        return 1.25*money;
    }
}

int main() {
    int hours;
    char category;
    string s = "ABCD";
    do {
        cout << "Podaj liczbę przepracowanych godzin: "; cin >> hours;
        cout << "Podaj kategorię [A..D]: "; cin >> category;
        cout << "\n";
    } while (hours < 0 || !isValid(category));
    cout << "Tygodniówka netto: " << salary(hours, category) << "\n";
    cout << "Tygodniówka brutto: " << addTax(salary(hours, category)) << "\n";
    return 0;
}
*/
// Zad 17
/*
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

int dice() {
    return rand()%6 + 1;
}

int main() {
    srand(time(NULL));
    int p = dice();
    int q = dice();
    cout << "Rzuty: " << p << ", " << q << "\n";
    int s = 0;
    if (p == 5 && q == 5) {
        s += 5;
    }
    if (p % 2 == 0) {
        if (q == 2 || q == 4 || q == 5) {
            s += p+3*q;
        } else {
            s += 2*q;
        }
    } else {
        if (q == 1 || q == 3 || q == 6) {
            s += (p==q)?(5*p+3):(2*q+p);
        } else {
            s += (p>q)?q:p + 4;
        }
    }
    cout << "Wynik: " << s << "\n";
    return 0;
}*/

// Zad 18
/*
#include <iostream>

using std::cout;

int main() {
    for (int i = 10; i < 100; i++) cout << i << " ";
    cout << "\n";
    for (int i = 100; i < 1000; i++) if (i%13 == 0) cout << i << " ";
    cout << "\n";
    return 0;
}
*/

// Zad 19
/*
#include <iostream>

using std::cout;
using std::cin;

int main() {
    int n;
    cout << " n = "; cin >> n;

    cout << "Pętla FOR\nDzielniki: \n";
    for (int i = 1; i <= n; i++) {
        if (n%i == 0) cout << i << "\t";
    }
    cout << "\n";

    cout << "Pętla WHILE\nDzielniki: \n";
    int j = 1;
    while (j <= n) {
        if (n%j == 0) cout << j << "\t";
        j++;
    }
    cout << "\n";

    cout << "Pętla DO-WHILE\nDzielniki: \n";
    j = 1;
    do {
        if (n%j == 0) cout << j << "\t";
        j++;
    } while (j <= n);
    cout << "\n";

    return 0;
}
*/

// Zad 20
#include <iostream>

using std::cout;
using std::cin;


int main() {
    int n, s = 0;
    cout << "   n = "; cin >> n;
    for (int i = 1; i <= n; i++) s += i*i;
    cout << "s(n) = " << s << "\n";
    return 0;
}
