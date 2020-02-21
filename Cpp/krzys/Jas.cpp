#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> tab[i][j];
        }
    }
    int x, y;
    cin >> x >> y;

    int gdzieonjest = -1;
    for (int i = 0; i < n; i++) {
        int x1 = tab[i][0], x2 = tab[i][2];
        int y1 = tab[i][1], y2 = tab[i][3];

        if ((x1 <= x) && (x <= x2) && (y1 <= y) && (y <= y2)) {
            gdzieonjest = i+1;
            break;
        }

    }

    cout << gdzieonjest << endl;
    
    return 0;
}