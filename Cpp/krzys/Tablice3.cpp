#include <iostream>
#include <cstring>

using namespace std;

string wypiszTablice(int T[], int n) {
	if (n == 0) return "[]";

	string wynik = "[";
	for (int i = 0; i <= n-1; i++) {
		wynik += to_string(T[i]) + ", ";
	}
	wynik += "\b\b]";
	return wynik;
}

int main() {
	int n;
	cout << "Podaj rozmiar tabeli: ";
	cin >> n;
	int T[n];
	cout << "Podaj tabelę: ";
	for (int i = 0; i <= n-1; i++) {
		cin >> T[i];
	}

	cout << "Wypisujemy:\t";
    	cout << wypiszTablice(T, n) << "\n";

	int reverse[n];
	for (int i = 0; i <= n-1; i++) {
		reverse[i] = T[n-i-1];
	}
	cout << "Zamiana 1:\t";
	cout << wypiszTablice(reverse, n) << "\n";

	cout << "Zamiana 2:\t";
	for (int i = 1; i <= n-1; i += 2) {
		int pom = T[i-1];
		T[i-1] = T[i];
		T[i] = pom;
	}
	cout << wypiszTablice(T, n) << "\n";

	return 0;
}
