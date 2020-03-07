#include <iostream>
#include <cstring>

using namespace std;

int policz(string x) {
    int poziom = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '(') poziom++;
        else if (x[i] == ')') poziom--;
        else return -1;
    }
    return poziom;
}
// 0 - napis jest poprawny
// ~0 - napis nie jest poprawny


int main() {
    int n;
    cin >> n;

    string T[n];
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    for (int i = 0; i < n; i++) {
        if (policz(T[i]) == 0) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }

    return 0;
}
