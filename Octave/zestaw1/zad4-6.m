%skrypt rysuje wykres wybranej funkcji na przedziale[-4,4]
clear
wzor1 = input("podaj wzór funkcji f zmiennej x: ","s")
wzor1 = strrep(wzor1, ".^", "^");
wzor1_str = wzor1;
wzor1_str = strrep(wzor1, "*", "·");
wzor1 = strrep(wzor1, "^", ".^");

wzor2 = input("podaj wzór funkcji g zmiennej x: ","s")
wzor2 = strrep(wzor2, ".^", "^");
wzor2_str = wzor2;
wzor2_str = strrep(wzor2, "*", "·");
wzor2 = strrep(wzor2, "^", ".^");

wzor3 = input("podaj wzór funkcji h zmiennej x: ","s")
wzor3 = strrep(wzor3, ".^", "^");
wzor3_str = wzor3;
wzor3_str = strrep(wzor3, "*", "·");
wzor3 = strrep(wzor3, "^", ".^");

x = [-4:0.1:4];
y1 = eval(wzor1);
y2 = eval(wzor2);
y3 = eval(wzor3);

h=figure;
set(h,'visible','off');

plot (x, y1);
hold on 
plot(x, y2);
plot(x, y3);
hold off 

title("Wykres funkcji f(x), g(x), h(x)");
line(xlim, zeros(2), "linestyle", "-", "color", "black");
line(zeros(2), ylim, "linestyle", "-", "color", "black");
xlabel("x");
ylabel("y");
legend("f(x)", "g(x)", "h(x)", "location", "northeastoutside");

print(h, "-dpng", "output.png")
%pause()