clear
wzor1 = input("Podaj wzór funkcji f zmiennych x i y: ","s")
wzor1 = strrep(wzor1, ".^", "^");
wzor1_str = wzor1;
wzor1_str = strrep(wzor1, "*", "·");
wzor1 = strrep(wzor1, "^", ".^");


[x,y]=meshgrid(-2:0.1:2);
z1=eval(wzor1);

h=figure;
set(h,'visible','off');
surf(x,y,z1);
title(sprintf("Wykres funkcji f(x,y) = %s", wzor1_str));
print(h, "-dpng", "output.png")