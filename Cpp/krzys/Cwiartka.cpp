#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin>>x>>y;

    if (x > 0 && y > 0) {
        cout << "Pierwsza cwiartka" << endl;
    } else if (x < 0 && y > 0) {
        cout << "Druga cwiartka" << endl;
    } else if (x < 0 && y < 0) {
        cout << "Trzecia cwiartka" << endl;
    } else if (x > 0 && y < 0) {
        cout << "Czwarta cwiartka" << endl;
    } else if (x == 0 && y == 0) {
        cout << "Punkt przecięcia się osi" << endl;
    } else if (x == 0) {
        cout << "Oś Y" << endl;
    } else if (y == 0) {
        cout << "Oś X" << endl;
    } else {
        cout << "coś jest nie tak XD";
    }

    return 0;
}