#include <iostream>

using namespace std;

int main()
{
    bool pierwsza = true;
    int n,x,y;           // szukamy, czy istnieją 2 liczby pierwsze X,Y takie, że dowolna liczba naturalna N idzie być zapisana jako N = X + Y
    cin>>n;              // wpisujemy liczbę N
    x=n;                 // zakładamy, że X = N
    while(1==1)          // powtarzajmy, póki znajdziemy liczbę pierwszą X taką, że N = X + Y
    {
        pierwsza = true;        // zakładamy, że pierwszy domniemany X, który znajdziemy, jest pierwszy
        x--;                    // w każdym kroku zmniejszamy X o 1
        for(int i=2;i*i<x;i++)  // dla każdej liczby x sprawdzamy
            if(x%i==0)          // czy istnieje I < sqrt(X), która dzieli X
            {                   // jeżeli dzieli, to
            pierwsza = false;   // obecny X jest liczbą złożoną
            break;              // i przerywamy pętlę
            }                   // w przeciwnym razie, jak takiej liczby nie znaleźliśmy, to X jest pierwszy
        if(pierwsza)    // 
        {               // jeżeli X jest pierwszy, to
            y=n-x;      // uznajemy, że Y = N-X
            break;      // i przerywamy pętlę
        }
    }       // pętla zawsze się przerwie dla dowolnego N >= 3, ponieważ znajdzie mniejszą liczbę pierwszą i uzna ją za X

    cout<<"n = "<<x<<" + "<< y; // wypisujemy N = X + Y
    getchar();
    getchar();
    return 0;
}