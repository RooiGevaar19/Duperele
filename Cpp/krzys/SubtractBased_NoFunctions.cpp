#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

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
	
	string c = ""; //1
	bool pozyczka = false; //2
	
	// wyrównaj zerami odjemnik
	while (b.size() < a.size()) b = '0' + b; //3
	
	// odejmij
	for (int i = a.size()-1; i >= 0; i--) { //4
		if (pozyczka) { //5
			a[i] = a[i] - 1; //6
		}
		pozyczka = false; //7
		int roznica = a[i] - b[i]; //8
		if (roznica < 0) { //9
			pozyczka = true; //10
			roznica += podstawa; //11
		}
		c = to_string(roznica) + c; //12
	}
	
	// usuñ zera z wyniku
	while (c[0] == '0') { //13
		c.erase(c.begin());
	}
	
	cout << "Wynik: " << c << endl;
	
	getchar();
	getchar();
	return 0;
}
