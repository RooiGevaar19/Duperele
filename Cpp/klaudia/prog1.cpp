#include <iostream>

using namespace std;

int main() {
    int a, b, suma;
    
    cout << "Podaj dwie liczby" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    //suma = a + b;
    //cout << "a + b = " << suma << endl;
    cout << "a + b = " << a+b << endl;
    cout << "a - b = " << a-b << endl;
    cout << "a * b = " << a*b << endl;
    if (b == 0) 
    {
        cout << "nie dzielimy przez 0!!!" << endl;
    } 
    else {
        cout << "a / b = " << a/b << endl;
    }

    cout << "Autor: Paweł Lipkowski" << endl;
    return 0;
}