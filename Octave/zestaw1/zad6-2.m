function [wynik] = Wiel(x)
    wynik=2*x^2-x+5*eye(size(x));
end

x = str2num(input("Podaj liczbę: ", "s"))
Wiel(x)