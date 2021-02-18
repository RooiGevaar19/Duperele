#include <iostream>

using namespace std;

string PrzeciwnaU2(string s)
{
    int i;
    for(i=0; i<8; i++) // zamiania zer na jedynki i jedynki na zera
        if(s[i] == '0') s[i] = '1';
        else s[i] = '0';
    s = '0'+s;
    i = 8;
    while(s[i]=='1') // dopełnienie U2 - dodanie 1
    {
        s[i]='0';
        i--;
    }
    s[i] = '1';
    return s.substr(1,8);
}

string DodajU2(string a, string b) 
{
    int suma, przn = 0;
    string c = "";
    for (int i = a.size()-1; i >= 0; i--) 
    {
        suma=przn+a[i]-'0'+b[i]-'0'; // dodanie 2 cyfer i przeniesienie z poprzedniego dodawania
        if (suma % 2 == 1) c = '1'+c; // dodanie wyniku do napisu końcowego
        else c = '0'+c;
        przn = suma/2; // jeżeli suma przy dodawaniu cyfr >= 2, to należy przenieść jedynkę do przodu 
    }
    //if (przn==1) c='1'+c;
    return c;
}

int main()
{
    string a,b,c;
    cin>>a;
    cin>>b;
    while(a.size()<8)a='0'+a; // dopełnienie zerami a i b
    while(b.size()<8)b='0'+b;
    b=PrzeciwnaU2(b);
    c=DodajU2(a,b);
    cout << c << endl;
    return 0;
}