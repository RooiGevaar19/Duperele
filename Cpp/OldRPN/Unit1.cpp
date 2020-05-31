#include <iostream>
#include <conio.h>

using namespace std;

struct element
{
        int wartosc;
        element *poprzedni;
};

element *dodaj (int liczba, element *wierzcholek)
{
        element *wsk;
        wsk = new element;
        if (!wsk) return 0;
        wsk -> wartosc = liczba;
        wsk -> poprzedni = wierzcholek;
        return wsk;
}

element *usun (int *liczba, element *wierzcholek)
{
        if (!wierzcholek) return 0;
        element *wsk;
        *liczba = wierzcholek -> wartosc;
        wsk = wierzcholek -> poprzedni;
        delete wierzcholek;
        return wsk;
}

void help()
{
        cout << "***********************************" << endl;
        cout << "*  POMOC - WPISYWANIE INSTRUKCJI  *" << endl;
        cout << "*                                 *" << endl;
        cout << "* Wpisz 'n' aby moc wpisac liczbe,*" << endl;
        cout << "* a nastepnie wpisz wybrana war-  *" << endl;
        cout << "* tosc.                           *"; getchar(); getchar();
        cout << "*                                 *" << endl;
        cout << "* Wpisz znak operatora, aby uzyc  *" << endl;
        cout << "* go w wyrazeniu.                 *" << endl;
        cout << "*     DOSTEPNE TYPY OPERATOROW    *" << endl;
        cout << "*          +   -   *   /          *" << endl;
        cout << "*                                 *" << endl;
        cout << "***********************************" << endl;
        getchar();

}

int main()
{
        char com[64]; int n[64], ilosc;
        int x, y, z;
        clrscr();
        cout << "OBLICZANIE WYRAZENIA ONP !!! \n";
        cout << "Podaj ilosc instrukcji wyrazenia: "; cin >> ilosc;

        help();

        cout << "*****************************************************" << endl;
        for (int i = 0; i < ilosc; i++)
        {
                cout << "Wpisz instrukcje: "; cin >> com[i];
                if (com[i] == 'n')
                {
                        cout << "Wpisz wybrana liczbe: "; cin >> n[i];
                }
        }
        cout << "*****************************************************" << endl;

        cout << "WPISANE WYRAZENIE W ONP" << endl;
        for (int i = 0; i < ilosc; i++)
        {
                if (com[i] == 'n') cout << n[i] << " "; else cout << com[i] << " ";
        }
        cout << "\n";
        getchar();

        cout << "*****************************************************" << endl;

        element *wierzcholek;
        wierzcholek = new element;
        wierzcholek = NULL;
        for (int i = 0; i < ilosc; i++)
        {
                if (com[i] == 'n')
                {
                        wierzcholek = dodaj(n[i], wierzcholek);
                }
                else
                {
                        switch (com[i])
                        {
                                case '+' : {
                                        y = wierzcholek->wartosc;
                                        wierzcholek = usun(&y, wierzcholek);
                                        x = wierzcholek->wartosc;
                                        wierzcholek = usun(&x, wierzcholek);
                                        z = x+y;
                                        wierzcholek = dodaj(z, wierzcholek);
                                        continue;
                                }
                                case '-' : {
                                        y = wierzcholek->wartosc;
                                        wierzcholek = usun(&y, wierzcholek);
                                        x = wierzcholek->wartosc;
                                        wierzcholek = usun(&x, wierzcholek);
                                        z = x-y;
                                        wierzcholek = dodaj(z, wierzcholek);
                                        continue;
                                }
                                case '*' : {
                                        y = wierzcholek->wartosc;
                                        wierzcholek = usun(&y, wierzcholek);
                                        x = wierzcholek->wartosc;
                                        wierzcholek = usun(&x, wierzcholek);
                                        z = x*y;
                                        wierzcholek = dodaj(z, wierzcholek);
                                        continue;
                                }
                                case '/' : {
                                        y = wierzcholek->wartosc;
                                        wierzcholek = usun(&y, wierzcholek);
                                        x = wierzcholek->wartosc;
                                        wierzcholek = usun(&x, wierzcholek);
                                        z = x/y;
                                        wierzcholek = dodaj(z, wierzcholek);
                                        continue;
                                }
                                default : {
                                cout << "FATAL ERROR\n";
                                getchar();
                                return 0;
                                }
                        }
                }
        }
        cout << "Wynik: " << wierzcholek->wartosc << endl;

        system("pause");
        return 0;
}

  // RedThreat Company
 // 2009-2014 AD
// Auteur: Pawel Lipkowski (CSB)
