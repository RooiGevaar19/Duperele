#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    bool mozeWypisac = false;

    if (n < 10) {
        cout << n << endl;
    } else {
        while (n >= 1) {
            if (n%10 != 0) 
                mozeWypisac = true;
            if (mozeWypisac)
                cout << n%10;
            n /= 10;
        }
        cout << endl;
    }

    return 0;
}