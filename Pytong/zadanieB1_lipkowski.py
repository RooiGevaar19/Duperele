# ==============================
# Paweł Lipkowski
# Zadanie b)
# 2021-04-28
# ==============================

def iloczyn(T):
    wynik = 1
    for item in T:
        wynik *= item
    return wynik

def nwd_2(a, b):
    while (b > 0):
        pom = a
        a = b
        b = pom % b
    return a

def nwd_N(T):
    if (len(T) == 1):
        return T[0]
    elif (len(T) == 2):
        return nwd_2(T[0], T[1])
    else:
        return nwd_2(T[0], nwd_N(T[1:]))


def nww_N(T):
    if (len(T) == 1):
        return T[0]
    else:
        return iloczyn(T) // nwd_N(T)

def jestDodatniaCalkowita(x):
    try: 
        y = int(x)
        return (y >= 1)
    except ValueError:
        return False


# ====== main
print("Obliczanie NWD i NWW.")
moznaIscDalej = False
while not (moznaIscDalej):
    print("Podaj, ile ma być liczb: ", end="")
    n = input()
    moznaIscDalej = jestDodatniaCalkowita(n)
    if not (moznaIscDalej):
        print("Liczb nie jest dodatnia całkowita.")
    else:
        n = int(n)

T = []

for i in range(0, n):
    moznaIscDalej = False
    while not (moznaIscDalej):
        print("Podaj liczbę nr. "+str(i+1)+": ", end="")
        value = input()
        moznaIscDalej = jestDodatniaCalkowita(value)
        if not (moznaIscDalej):
            print("Liczba nie jest dodatnia całkowita.")
        else:
            T.append(int(value))

print("Liczby: ",T)
print("NWD:    ", nwd_N(T))
print("NWW:    ", nww_N(T))
