%skrypt rysuje wykres wybranej funkcji na przedziale[-4,4]
clear
wzor1 = input("podaj wzór funkcji f_1 zmiennej x: ","s")
wzor1 = strrep(wzor1, ".^", "^");
wzor1_str = wzor1;
wzor1_str = strrep(wzor1, "*", "·");
wzor1 = strrep(wzor1, "^", ".^");

wzor2 = input("podaj wzór funkcji f_1 zmiennej x: ","s")
wzor2 = strrep(wzor2, ".^", "^");
wzor2_str = wzor2;
wzor2_str = strrep(wzor2, "*", "·");
wzor2 = strrep(wzor2, "^", ".^");

x = [-4:0.1:4];
y1 = eval(wzor1);
y2 = eval(wzor2);

h=figure;
set(h,'visible','off');
#plot(x,y1); %kreslenie wykresu y=f(x)
%subplot (2, 1, 1)
plot (x, y1);
hold on 
%subplot (2, 1, 2)
plot(x, y2);
hold off 
title(sprintf("Wykres funkcji f(x), g(x)", wzor1_str));
line(xlim, zeros(2), "linestyle", "-", "color", "black");
line(zeros(2), ylim, "linestyle", "-", "color", "black");
xlabel("x");
ylabel("y");
print(h, "-dpng", "output.png")
%pause()