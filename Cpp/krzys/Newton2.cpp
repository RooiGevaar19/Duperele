#include <iostream>

using namespace std;

int silnia(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    int newton = silnia(n) / (silnia(k)*(silnia(n-k)));
    cout << newton << endl;
    return 0;
}