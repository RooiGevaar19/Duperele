#include <iostream>

using namespace std;

int main() {
    // wczytujemy
    int T[100000];
    int n;
    int i = 0;
    do {
        cin >> n;
        T[i] = n;
        i++;
    } while (n > -1);

    // przesukujemy
    int count = 0;
    for (int j = 1; j < i-1; j++) {
        if (T[j] > T[j-1]) {
            count++;
        }
    }

    // wypisujemy
    cout << count << endl;    

    return 0;
}