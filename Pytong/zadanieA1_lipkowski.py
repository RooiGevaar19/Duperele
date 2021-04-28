# ==============================
# Paweł Lipkowski
# Zadanie a)
# 2021-04-26
# ==============================


def nwd(a, b):
    if b > 0:
        return nwd(b, a%b)
    return a

# funkcja przyjmująca licznik i mianownik ułamka niewłaściwego
# i zwracająca albo napis liczby mieszanej albo napis błędu
def naLiczbeMieszana(licznik, mianownik):
    if mianownik == 0:
        return "dziel0"
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

        if (calosc == 0 and licznik != 0):
            calosc = "" 
        else:
            calosc = (str(abs(calosc))+" ")  # jeżeli część cała wynosi zero, to możemy ją pominąć w zapisie

        return znak + calosc + ulamek_wlasciwy


# ======= main
print("Zamiana ułamka niewłaściwego na liczbę mieszaną")
print("Podaj licznik ułamka: ", end="")
licznik = int(input())
print("Podaj mianownik ułamka: ", end="")
mianownik = int(input())



wynik = naLiczbeMieszana(licznik, mianownik)
if (wynik == "dziel0"):
    print("Nie dzielimy przez 0.")
else:
    print("Wynik:", wynik)


