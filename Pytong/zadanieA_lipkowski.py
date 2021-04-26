# ==============================
# Paweł Lipkowski
# Zadanie a)
# 2021-04-26
# ==============================


def nwd(a, b):
    if b > 0:
        return nwd(b, a%b)
    return a

# funkcja przyjmująca napis postaci ułamkowej, np. "-52/3" 
# i zwracająca albo napis liczby mieszanej albo napis błędu
def naLiczbeMieszana(ul):
    licznik = int(ul.split('/')[0])
    mianownik = int(ul.split('/')[1])

    if mianownik == 0:
        return "errdiv0"
    else:
        # ustalanie znaku ułamka
        if (1.0*licznik/mianownik < 0):
            znak = "-"
        else:
            znak = ""

        licznik = abs(licznik)
        mianownik = abs(mianownik)
        
        # skracanie ułamka
        skr = nwd(licznik, mianownik)
        licznik //= skr
        mianownik //= skr
        calosc = licznik // mianownik
        licznik %= mianownik

        if (licznik == 0):                # jeżeli wyszło nam, że liczba jest całkowita
            ulamek_wlasciwy = ""
        else:
            ulamek_wlasciwy = str(licznik) + "/" + str(mianownik)
        calosc = "" if (calosc == 0 and licznik != 0) else (str(abs(calosc))+" ")  # jeżeli część cała wynosi zero, to możemy ją pominąć w zapisie

        return znak + calosc + ulamek_wlasciwy

def czyJestUlamkiem(s):
    values = s.split('/')
    if (values[0][0] == '-'):
        values[0] = values[0].replace('-', '')
    if (values[1][0] == '-'):
        values[1] = values[1].replace('-', '')
    return len(values) == 2 and all(i.isdigit() for i in values)


# ======= main
print("Zamiana ułamka niewłaściwego na liczbę mieszaną")
jestUlamkiem = False
while not (jestUlamkiem):
    print("Podaj ułamek postaci a/b, np. 3/5, -40/9: ", end="")
    ul = input()
    jestUlamkiem = czyJestUlamkiem(ul)
    if not (jestUlamkiem):
        print("Podane wyrażenie nie jest ułamkiem.")

wynik = naLiczbeMieszana(ul)
if (wynik == "errdiv0"):
    print("Nie dzielimy przez 0.")
else:
    print("Wynik:", wynik)


