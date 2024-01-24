import random

# limit = 10     # mnożymy co najwyżej razy 10
# exercises = 10 # 10 ćwiczeń jako default

# ustalenie warunków testu
print("Podaj liczbę ćwiczeń:     ", end='')
exercises = int(input())
print("Podaj maksymalny czynnik: ", end='')
limit = int(input())

# mechanizm testowy
result = 0                                   # zmienna do sumowania punktów
for i in range (0, exercises):
    a = random.randint(0, limit)             # losuj czynnik 1
    b = random.randint(0, limit)             # losuj czynnik 2
    print(f"{i+1}: \t{a} * {b} = ", end='')
    guess = int(input())                     # weź odpowiedź od użytkownika
    if (guess == a*b):                       # sprawdź, czy odpowiedź zgadza się z faktycznym iloczynem
        print('Dobrze!')
        result += 1
    else:
        print(f'Poprawny wynik to {a*b}')

# napisz wynik
print(f"Wynik: {result}/{exercises} = {result/exercises*100}%")