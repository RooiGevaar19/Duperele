%skrypt rysuje wykres wybranej funkcji na przedziale[-4,4]
clear
x=[-4:0.1:4];
wzor=input("podaj wzór funkcji f zmiennej x: ","s")
y=eval(wzor);
plot(x,y); %kreslenie wykresu y=f(x)
print -djpg image.jpg
%pause()