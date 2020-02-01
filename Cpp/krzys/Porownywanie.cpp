#include <iostream>
#include <string>

using namespace std;

string obetnij(string x) {
    if (x.length() == 1) {
        return x;
    } else {
        string res = "";
        bool mozeWypisac = false;
        int n = x.length();

        for (int i = 0; i <= n-1; i++) {
            if (x[i] != '0') {
                mozeWypisac = true;
            }
            if (mozeWypisac) {
                res += x[i];
            }
        }
        if (res == "") return "0";
        return res;
    }
}

int konwertuj(char x) {
    return (int)x - 48;
}

int porownaj(string a, string b) {
    // a > b => 1
    // a < b => -1
    // a = b => 0

    if (a.length() < b.length()) {
        return -1;
    } else if (a.length() > b.length()) {
        return 1;
    } else {
        // liczby są równej długości
        int n = a.length();
        int flaga = 0;
        for (int i = 0; i <= n-1; i++) {
            int x = konwertuj(a[i]);
            int y = konwertuj(b[i]);
            if (x < y) {
                flaga = -1;
                break;
            } else if (x > y) {
                flaga = 1;
                break;
            }
        }
        return flaga;

    }
}

int testuj(string a, string znak, string b) {
    // 1  - prawda
    // 0  - falsz
    // -1 - error
    int wynik = porownaj(a, b);

    if (znak == "<") {
        if (wynik < 0) return 1;
        else return 0;
    } else if (znak == ">") {
        if (wynik > 0) return 1;
        else return 0;
    } else if (znak == "==") {
        if (wynik == 0) return 1;
        else return 0;
    } else if (znak == "!=") {
        if (wynik != 0) return 1;
        else return 0;
    } else if (znak == "<=") {
        if (wynik <= 0) return 1;
        else return 0;
    } else if (znak == ">=") {
        if (wynik >= 0) return 1;
        else return 0;
    } else {
        return -1;
    }
}

int main() {
    string L1, L2, znak;
    cin >> L1 >> znak >> L2;

    L1 = obetnij(L1);
    L2 = obetnij(L2);

    int wynik = testuj(L1, znak, L2);

    //cout << wynik << endl;
    if (wynik == 1) cout << "TAK" << endl;
    else if (wynik == 0) cout << "NIE" << endl;
    else cout << "BŁĄD" << endl;

    return 0;
}