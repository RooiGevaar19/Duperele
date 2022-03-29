function [wynik] = Wiel(x)
    wynik=2*x^2-x+5*eye(size(x));
end

Wiel([2 -3; -1 4])