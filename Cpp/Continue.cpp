#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Ile elementow ma miec tablica? "; cin >> n;

    int T[n];
    for (int j = 0; j < n; j++) {
    	cout << "Podaj element nr. " << j+1 << ": "; cin >> T[j];
    }

    int i;
    cout << "Ktory element chcesz przyslonic? [1.." << n << "] "; cin >> i;
    if ((i < 1) && (i > n)) {
       cout << "Blad!" << endl;
    } else {
      i--;

      int iloczyn = 1;
      for (int j = 0; j < n; j++) {
      	  if (j == i) continue;
          else iloczyn *= T[j];
      }
      T[i] = iloczyn;

     for (int j = 0; j < n; j++) {
    	cout << "T[" << j+1 << "] = " << T[j] << endl;
     }
    }
    return 0;
}
