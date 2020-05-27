#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void game(int Candies[], int n) {
    int cursorAlice = -1; 
    int cursorBob   = n;
    int scoreAlice  = 0;
    int scoreBob    = 0;
    int howMuch     = 0;
    int moves       = 0;
    bool AliceMoves = 1; 

    while (cursorAlice < cursorBob) {
        if (cursorBob - cursorAlice > 1) moves++;
        if (AliceMoves) {
            int i = 0;
            while (i <= howMuch && cursorAlice < cursorBob) {
                cursorAlice++;
                if (cursorAlice >= cursorBob) break;
                i += Candies[cursorAlice];
            }
            scoreAlice += i;
            howMuch = i;
        } else {
            int i = 0;
            while (i <= howMuch && cursorAlice < cursorBob) {
                cursorBob--;
                if (cursorAlice >= cursorBob) break;
                i += Candies[cursorBob];
            }
            scoreBob += i;
            howMuch = i;
        }
        AliceMoves = !(AliceMoves);
    }
    
    cout << moves << " " << scoreAlice << " " << scoreBob << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int Candies[n];
        for (int j = 0; j < n; j++) {
            cin >> Candies[j];
        }
        game(Candies, n);
    }
    return 0;
}