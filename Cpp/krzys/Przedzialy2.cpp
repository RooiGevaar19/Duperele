#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    int T_pocz[5000], T_koniec[5000];
    
    for (int i = 0; i < n; i++) {
        cin >> T_pocz[i] >> T_koniec[i];
    }
        

    sort(T_pocz, T_pocz+n);
    sort(T_koniec, T_koniec+n);

    int a = T_pocz[0];
    int b = T_koniec[0];
    int wynik = 1;
    for (int i = 1; i < n; i++) {
        if (T_pocz[i] > b+1) {
            wynik++;
            a = T_pocz[i];
            b = T_koniec[i];
        } 
        else if (T_koniec[i] >= b) {
            b = T_koniec[i];
        }
    }
    cout << wynik << endl;

    return 0;
}