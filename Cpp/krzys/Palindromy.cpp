#include <iostream>
#include <vector>

using namespace std;

string zamiana(int d, int baza)
{
    string b= "";
    int cyfra;
    while(d>0)
    {
      cyfra = d % baza;
      if(cyfra<10) b = char('0'+cyfra)+b;
        else b=char('A'-10+cyfra)+b;
      d = d / baza;
    }
    return b;
}
bool palindrom(string liczba)
{
     bool c = true;
     for (int i=0;i<liczba.size()/2;i++)
     {
        if (liczba[i]!=liczba[liczba.size()-1-i])
        {
            c=false;
            break;
        }
     }
     return c;
}
int main()
{
    string a;
    vector<int> dane = {}; // zadeklaruj pustą tablicę z danymi liczbowymi
    while (cin >> a) {     // póki się wczytują dane wejściowe linijka po linijce
        dane.push_back(atoi(a.c_str())); // wrzuć do tablicy z danymi wczytaną wartość
    }
    for (int baza = 2; baza <= 16; baza++) { // dla każdego systemu od 2 do 16
        int l = 0; // resetuj licznik
        for (int i = 0; i < dane.size(); i++) // dla każdej liczby z tabeli
        {            
            if (palindrom(zamiana(dane[i], baza))) // jeżeli obecna liczba jest palindromem w danym systemie
            {
                l++; // zwiększ licznik
            }
        }
        cout<<l<<endl; // wypisz liczbę palindromów w danym systemie
    }
    //getchar();
    //getchar();
    return 0;
}