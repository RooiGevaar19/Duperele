#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Ile Zdziś ma ocen?: ";
    cin >> n;

    int oceny[n];
    for (int i = 0; i < n; i++) cin >> oceny[i]; 
    
    int wynik[7] = {0}; 
    for (int i = 0; i < n; i++) wynik[oceny[i]]++; 

    for (int i = 1; i <= 6; i++) cout << wynik[i] << " ";
    cout << endl;
    return 0;
}