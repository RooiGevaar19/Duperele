# ==============================
# Paweł Lipkowski
# Zadanie b)
# 2021-04-26
# ==============================

def nwd(a, b):
    while (b > 0):
        pom = a
        a = b
        b = pom % b
    return a

def nww(a, b):
    return (a*b) // nwd(a, b)

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
    print("Podaj pierwszą liczbę dodatnią całkowitą: ", end="")
    x = input()
    print("Podaj drugą liczbę dodatnią całkowitą: ", end="")
    y = input()
    moznaIscDalej = (jestDodatniaCalkowita(x) and jestDodatniaCalkowita(y))
    if not (moznaIscDalej):
        print("Co najmniej jedna z podanych liczb nie jest dodatnia całkowita.")

x = int(x)
y = int(y)
print("NWD:", nwd(x,y))
print("NWW:", nww(x,y))
