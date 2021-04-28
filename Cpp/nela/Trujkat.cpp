#include <iostream>

using namespace std;

int main() {
    float pole = 0.0;
    do {
        cout << "Podaj wartość pola trójkąta: ";
        cin >> pole;
        if (pole < 0) {
            cout << "Podano niepoprawną wartość. Musi ona być liczbą nieujemną." << endl;
        }
    } while (pole < 0);

    float podstawa = 0.0;
    do {
        cout << "Podaj wartość długości podstawy trójkąta: ";
        cin >> podstawa;
        if (podstawa <= 0) {
            cout << "Podano niepoprawną wartość. Musi ona być liczbą dodatnią." << endl;
        }
    } while (podstawa <= 0);

    // P = (a * h) / 2
    // 2 * P = a * h
    // h = (2 * P)/a
    float wysokosc = (2 * pole)/podstawa;

	cout << "Wysokość trójkąta wynosi " << wysokosc << "." << endl;
	return 0;
}
