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
        moves++;
        cout << "Move " << moves << endl;
        if (AliceMoves) {
            cout << "Alice moves." << endl;
            int i = 0;
            while (i <= howMuch && cursorAlice < cursorBob) {
                cursorAlice++;
                cout << "Positions of Alice is " << cursorAlice << " and Bob is " << cursorBob << endl;
                if (cursorAlice >= cursorBob) break;
                cout << "Alice is in " << cursorAlice+1 << " right now and sees " << Candies[cursorAlice] << ". Her turn score is " << i << endl;
                i += Candies[cursorAlice];
                cout << "Alice collected " << Candies[cursorAlice] << " and now her turn score is " << i << endl;
                cout << "Alice has to collect " << howMuch+1 << " or more turn score." << endl;
                cout << (i <= howMuch) << endl;
                if (i <= howMuch) {
                    cout << "She can collect more." << endl;
                    cout << "The limit is " << howMuch << endl;
                } else {
                    cout << "OK. Stop." << endl;
                }
            }
            scoreAlice += i;
            cout << "Alice's overall score is " << scoreAlice << ". Next move." << endl << endl;
            howMuch = i;
        } else {
            cout << "Bob moves." << endl;
            int i = 0;
            while (i <= howMuch && cursorAlice < cursorBob) {
                cursorBob--;
                cout << "Positions of Alice is " << cursorAlice << " and Bob is " << cursorBob << endl;
                if (cursorAlice >= cursorBob) break;
                cout << "Bob is in " << cursorBob+1 << " right now and sees " << Candies[cursorBob] << ". His score is " << i << endl;
                i += Candies[cursorBob];
                cout << "Bob collected " << Candies[cursorBob] << " and now his score is " << i << endl;
                cout << "Bob has to collect " << howMuch+1 << " or more score." << endl;
                cout << (i <= howMuch) << endl;
                if (i <= howMuch) {
                    cout << "He can collect more." << endl;
                    cout << "The limit is " << howMuch << endl;
                } else {
                    cout << "OK. Stop." << endl;
                }
            }
            scoreBob += i;
            cout << "Bob's overall score is " << scoreBob << ". Next move." << endl << endl;
            howMuch = i;
        }
        AliceMoves = !(AliceMoves);
    }
    cout << "Game over." << endl;
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