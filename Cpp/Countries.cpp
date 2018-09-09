#include <iostream>
#include <cstring>
#include <algorithm>

#define WCHUJ 16

using namespace std;

string db[WCHUJ] = {
    "Denmark", "China", 
    "Israel", "India", 
    "Poland", "Portugal", "Puerto Rico", "Panama",
    "Sweden", "Switzerland",
    "Germany", "Great Britain", "Ghana",
    "Ukraine", "USA", "France"
};

string str_toupper(string s) {
    transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c) { 
            return toupper(c); 
        });
    return s;
}

int howManyCountries(char letter) {
    int count = 0;
    for (int i = 0; i < WCHUJ; i++) {
        if (db[i].at(0) == letter) count++;
    }
    return count;
}

int main() {
    string fletter;
    int howmany;

    srand(time(NULL));
    random_shuffle(&db[0], &db[WCHUJ]);
    cout << "Type a letter [A-Z]: ";
    cin >> fletter;
    fletter = str_toupper(fletter);
    if (howmany = howManyCountries(fletter[0]) == 0) {
        cout << "There is no country in my list.\n";
    } else {
        cout << "Countries: \n";
        int j = 0;
        for (int i = 0; i < WCHUJ; i++) {
            if ((db[i].at(0) == fletter[0]) && (j < 2)) {
                cout << " - " << db[i] << "\n";
                j++;
            }
        }
    }
    return 0;
}