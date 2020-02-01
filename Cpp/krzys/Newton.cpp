#include <iostream>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    int a = 1, b = 1, c = 1;

    for (int i = 2; i <= n; i++) {
        a = a * i;
    }

    for (int i = 2; i <= k; i++) {
        b = b * i;
    }

    for (int i = 2; i <= n-k; i++) {
        c = c * i;
    }

    int newton = a/(b*c);
    cout << newton << endl;
    return 0;
}