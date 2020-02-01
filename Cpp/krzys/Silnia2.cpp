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
    int n;
    cin >> n;
    cout << silnia(n) << endl;
    return 0;
}