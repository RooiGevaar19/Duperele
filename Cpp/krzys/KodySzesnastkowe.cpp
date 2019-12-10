#include <iostream>

using namespace std;

int main() {
    char hex[2];
    cout << "Podaj liczbe szesnastkową: ";
    cin >> hex;

    char cyfra1 = hex[0];
    char cyfra2 = hex[1];

    int numer1;
    if (cyfra1 == 'A') numer1 = 10;
    else if (cyfra1 == 'B') numer1 = 11;
    else if (cyfra1 == 'C') numer1 = 12;
    else if (cyfra1 == 'D') numer1 = 13;
    else if (cyfra1 == 'E') numer1 = 14;
    else if (cyfra1 == 'F') numer1 = 15;
    else numer1 = (int)cyfra1 - 48;

    int numer2;
    if (cyfra2 == 'A') numer2 = 10;
    else if (cyfra2 == 'B') numer2 = 11;
    else if (cyfra2 == 'C') numer2 = 12;
    else if (cyfra2 == 'D') numer2 = 13;
    else if (cyfra2 == 'E') numer2 = 14;
    else if (cyfra2 == 'F') numer2 = 15;
    else numer2 = (int)cyfra2 - 48;

    int wynik = numer2 + 16*numer1;

    cout << wynik << endl << (char)wynik << endl;

    return 0;
}

