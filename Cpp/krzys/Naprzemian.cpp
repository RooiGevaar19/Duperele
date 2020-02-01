#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int T[n];
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < n; i += 2) {
        cout << T[i] << " ";
    }
    for (int i = 1; i < n; i += 2) {
        cout << T[i] << " ";
    }
    return 0;
}