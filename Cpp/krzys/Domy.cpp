#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, B;
    cin >> B >> N;
    int T[N];
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }
    sort(T, T+N);

    int cash = B;
    //int count = 0;
    int i = 0;
    while (cash > 0 && i < N) {
        if (cash >= T[i]) {
            //count++;
            cash -= T[i];
        } else break;
        i++;
    }

    //cout << count << endl;
    cout << i << endl;

    return 0;
}