#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int T[n];
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int first = -1;
    for (int i = 0; i <= n-1; i++) {
        if (x == T[i]) {
            first = i+1;
            break;
        }
    }

    int last = -1;
    for (int i = n-1; i >= 0;i--) {
        if (x == T[i]) {
            last = i+1;
            break;
        }
    }

    cout << first << " " << last << endl;

    return 0;
}

// Jak wymieniamy elementy tablicy
// człowiek : 1 2 3 4 5 6 ... k   k+1 k+2 ... n-1 n
// C++      : 0 1 2 3 4 5 ... k-1 k   k+1 ... n-2 n-1

