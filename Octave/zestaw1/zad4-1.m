%skrypt rysuje wykres wybranej funkcji na przedziale[-4,4]
clear
wzor=input("podaj wzór funkcji f zmiennej x: ","s")
wzor = strrep(wzor, ".^", "^");
wzor1 = wzor;
wzor1 = strrep(wzor, "*", "·");
wzor = strrep(wzor, "^", ".^");

x=[-4:0.1:4];
y=eval(wzor);

h=figure;
set(h,'visible','off');
plot(x,y); %kreslenie wykresu y=f(x)
title(sprintf("Wykres funkcji f(x)=%s", wzor1));
print(h, "-dpng", "output.png")
%pause()