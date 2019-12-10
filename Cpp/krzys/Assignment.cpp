#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int numer_tel;
    cout << "Podaj numer: ";
    cin >> numer_tel;
    int cyfra = numer_tel % 10;
    cyfra = cyfra * 2;
    cyfra += 5;
    cyfra *= 50;
    cyfra += 1764+5;
    cyfra -= 1996;

    int liczba = cyfra / 100;
    int wynik = cyfra % 100;

    cout << "Liczba: " << liczba << endl;
    cout << "Wynik: "  << wynik << endl;

    fflush(stdin);
    getchar();
    return 0;
}
