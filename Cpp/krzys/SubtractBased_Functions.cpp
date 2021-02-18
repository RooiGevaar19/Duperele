#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void pause() {
	printf("Press any key to continue...");
	while( getchar() != '\n' ) { } 
	getchar();
}

int CharToInt(char a) {
	return a - '0';
}

char IntToChar(int a) {
	return (char)(a + '0');
}

string removeLeadingZeros(string s) {
	while (s[0] == '0') {
		s.erase(s.begin());
	}
	return s;
}

string odejmij(string a, string b, int podstawa) {
	while (b.size() < a.size()) b = '0' + b;
	
	string c = "";
	bool pozyczka = false;
	for (int i = a.size()-1; i >= 0; i--) {
		if (pozyczka) {
			a[i] = IntToChar(CharToInt(a[i]) - 1);
		}
		pozyczka = false;
		int roznica = CharToInt(a[i]) - CharToInt(b[i]);
		if (roznica < 0) {
			pozyczka = true;
			roznica += podstawa;
		}
		c = to_string(roznica) + c;
	}
	return removeLeadingZeros(c);
}

int main() {
	int podstawa;
	string a, b;
	cout << "Odejmowanie w systemach liczbowych\n";
	cout << "Podaj podstawe: ";
	cin >> podstawa;
	cout << "Podaj pierwsza liczbe: ";
	cin >> a;
	cout << "Podaj druga liczbe:    ";
	cin >> b;
	
	string wynik = odejmij(a, b, podstawa);
	
	cout << "Wynik: " << wynik << endl;
	
	pause();
	return 0;
}
