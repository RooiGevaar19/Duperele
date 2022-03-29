function [wynik] = Wiel(x)
    wynik=2*x^2-x+5*eye(size(x));
end

x = input("Podaj macierz: ", "s")
m = eval(x)
Wiel(m)