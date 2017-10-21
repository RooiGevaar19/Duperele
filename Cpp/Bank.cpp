#include <iostream>
#include <cstdio>

const int correctPin = 2137;

int podajPin()
{
    int x;
    printf("Podaj PIN: ");
    scanf("%i", &x); // poproś o integer (specyfikator %i, znacznie precyzyjniejsza i szybsza metoda wejścia - zobacz więcej o printf/scanf) - ampersand oznacza, że po wykonaniu scanfa zmieni się również wartość zmiennej x
    return x;
}

void event_onCorrectPin()
{
    printf("Poprawny PIN!\n"); // \n oznacza koniec linii
}

void event_onWrongPin()
{
    printf("Niepoprawny PIN!\n");
}

void event_onSuccess()
{
    printf("Zalogowano się!\n");
}

void event_onFail()
{
    printf("Zablokowano możliwość podania numeru PIN - za dużo złych prób!");
}

int main()
{
    int proby = 10, flag = 0; // flaga sprawdza, czy próba zalogowania się powiodła się
    while (proby >= 0)
    {
        int pin = podajPin();
        if (pin == correctPin)
        {
            event_onCorrectPin();
            flag = 1;
            break;  // przerwanie pętli
        } else {
            event_onWrongPin();
            proby--;
        }
    }
    if (flag == 0) event_onFail();
    else event_onSuccess();
    //getchar();	   // jak pracujesz na Windowsie, to odkomentuj
    return 0;		   // inb4 linux masterrace ;)
}

//------------------------------------------------------------------------------
// Author: RooiGevaar19 (Paul Lipkowski)
// Date:   10/21/2017
// Name:   Bank

