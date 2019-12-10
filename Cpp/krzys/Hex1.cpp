#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char a, b;
    int wynik;
    cin >> a >> b;
    wynik = (a-48)*16;
    if (b >= '0' && b <= '9') wynik += (b-48);
    else wynik += (b-55);
    cout << wynik << endl << (char)wynik << endl;
    return 0;
}
