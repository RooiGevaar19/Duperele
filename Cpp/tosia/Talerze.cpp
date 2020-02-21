#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define DUZO 1000

using namespace std;

vector<string> podzielNaWyrazy(string napis) {
    vector<string> pom;
    stringstream strumien(napis); // Turn the string into a stream.
    string wyraz;
 
    while(getline(strumien, wyraz, ' ')) {
        pom.push_back(wyraz);
    }
    
    return pom;
}

// ========== STOSY

string stosPlytkich[DUZO];
int znacznikPlytkich = -1;
string stosGlebokich[DUZO];
int znacznikGlebokich = -1;

void kladzNaPlytkie(string wartosc) {
    znacznikPlytkich++;
    stosPlytkich[znacznikPlytkich] = wartosc;
}

string zdejmijZPlytkich() {
    if (znacznikPlytkich == -1) {
        return "Stos plytkich jest pusty!";
    }
    string wartosc = stosPlytkich[znacznikPlytkich];
    znacznikPlytkich--;
    return wartosc;
}

void kladzNaGlebokie(string wartosc) {
    znacznikGlebokich++;
    stosGlebokich[znacznikGlebokich] = wartosc;
}

string zdejmijZGlebokich() {
    if (znacznikGlebokich == -1) {
        return "Stos glebokich jest pusty!";
    }
    string wartosc = stosGlebokich[znacznikGlebokich];
    znacznikGlebokich--;
    return wartosc;
}

// =========== POLECENIA

void wczytajPolecenie() {
    string napis;
    getline(cin, napis,'\n');
   
    vector<string> wyrazy = podzielNaWyrazy(napis);

    if (wyrazy.size() > 0) {
        if (wyrazy[0] == "dziekuje") {
            if (wyrazy[1] == "plytki") {
                kladzNaPlytkie(wyrazy[2]);
            } else if (wyrazy[1] == "gleboki") {
                kladzNaGlebokie(wyrazy[2]);
            }

        } else if (wyrazy[0] == "prosze") {
            if (wyrazy[1] == "plytki") {
                cout << zdejmijZPlytkich() << endl;
            } else if (wyrazy[1] == "gleboki") {
                cout << zdejmijZGlebokich() << endl;
            }

        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        wczytajPolecenie();
    }
    return 0;
}