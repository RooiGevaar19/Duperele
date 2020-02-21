#include <iostream>

using namespace std;



int main() {
    int n;
    cin >> n;
    int T[n];
    for (int i=0; i <= n-1; i++) {
        cin >> T[i];
    }

    bool czyBitoniczny = true;
    
    // szukamy momentu przełamania
    int j = 0;
    for (int i = 1; i <= n-1; i++) {
        if (T[i] == T[i-1]) {
            czyBitoniczny = false;
            break;
        }
        j = i;
        if (T[i] < T[i-1]) {
            break;
        }
    }

    // sprawdzamy czy maleje
    for (int i = j+1; ((i <= n-1) && (czyBitoniczny)); i++) {
        if (T[i] >= T[i-1]) {
            czyBitoniczny = false;
            break;
        }
    }

    //cout << czyBitoniczny << endl;
    cout << ((czyBitoniczny) ? "TAK" : "NIE") << endl;

    //if (czyBitoniczny) 
    //    cout << "TAK" << endl;
    //else 
    //    cout << "NIE" << endl;


    return 0;
}
