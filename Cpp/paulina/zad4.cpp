#include<iostream>

using namespace std;
 
//funkcja zamieniająca wartości zmiennych
void zamien(int *a, int *b) {
    int pom = *a;
        *a = *b;
        *b = pom;
}
 
void sortuj(int *x, int *y, int *z) {
        if(*x > *y)
            zamien(x,y);
        if(*x > *z)
            zamien(x,z);
        if(*y > *z)
            zamien(y,z);
}
 
int main() {
        int x, y, z;
        
        cout<<"Podaj trzy liczby: ";
        cin>>x>>y>>z;
        
        sortuj(&x,&y,&z);
        
        cout<<"Liczby posortowane: "<<x<<" "<<y<<" "<<z<<endl;
        return 0;
}
