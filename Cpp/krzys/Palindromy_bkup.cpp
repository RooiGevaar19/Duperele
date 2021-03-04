#include <iostream>

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
    int a, l=0;
    for (int baza = 2; baza <= 16; baza++) {
        while(cin>>a)
        {
            if (palindrom(zamiana(a, baza)))
            {
                l++;
            }
        }
        cout<<l<<endl;
    }
    getchar();
    getchar();
    return 0;
}