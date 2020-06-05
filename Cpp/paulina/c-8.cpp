Paulina Magdalena Pajączkowska  nr indeksu: 266458

1)

#include<iostream>
using namespace std;
int main()
{
    int n = 6;
    int* w=&n;
    cout << n << &n << w << *w << endl;

    return 0;
}

2)
#include<iostream>
using namespace std;
void potrojimy_liczbe(int* n)
{
    *n*= 3;
}
int main()
{
    int n;
    cout << "Podaj liczbe : " << endl;
    cin >> n;
    int* w = &n;
    potrojimy_liczbe(w); 

    cout << n  << endl;
    return 0;
}
3)
#include <iostream>

using namespace std;

void cube(int *a){
    cout << *a*(*a)*(*a);
};

int main()
{
    cout << "Podaj x " << endl;
    int x;
    cin >> x;
    cube(&x);
    return 0;
}

4)
#include<iostream>
#include<cstdlib>
using namespace std;
 
//funkcja zamieniająca wartości zmiennych
void zamien(int *a, int *b)
{
    int pom = *a;
        *a = *b;
        *b = pom;
}
 
void sortuj(int *x, int *y, int *z)
{
        if(*x>*y)
                zamien(x,y);
        if(*x>*z)
                zamien(x,z);
        if(*z>*y)
                zamien(y,z);
}
 
int main()
{
        int x, y, z;
        
        cout<<"Podaj trzy liczby: ";
        cin>>x>>y>>z;
        
        sortuj(&x,&y,&z);
        
        cout<<"Liczby posortowane: "<<x<<" "<<y<<" "<<z<<endl;
        
        system("pause");
        return 0;
}

5)
#include <iostream>

using namespace std;

void dziel(int *a, int n)
    {
    do
    {
        *a=*a-n;
    }
    while(*a>0);
    if(*a==-1)
    {
        *a=*a+2;
        cout << *a << " x Nieparzyste";
    }
    else
    cout << *a << " x Parzyste";
}

int main()
{
    cout << "Podaj x " << endl;
    int x;
    cin >> x;
    dziel(&x,2);
    return 0;
}
6)
#include <iostream>

using namespace std;

int addmult(int* a, int* b) {
    *a = *a + *b;
    cout << "Wartosc a: " << *a << endl;
    return *a * (*b);
}

int main()
{
    int x, y;
    cout << "Podaj x i y " << endl;
    cin >> x;
    cin >> y;
    cout << " wartosc a*b : " << addmult(&x, &y) << endl;
    return 0;
}