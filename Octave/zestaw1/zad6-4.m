function y = f(x)
    y = x.^3 - 2*x.^2;
end

clear

x=[-4:0.1:4];
y=f(x);

h=figure;
set(h,'visible','off');
plot(x,y); %kreslenie wykresu y=f(x)
title(sprintf("Wykres funkcji f(x)"));
line(xlim, zeros(2), "linestyle", "-", "color", "black");
line(zeros(2), ylim, "linestyle", "-", "color", "black");
xlabel("x");
ylabel("f(x)");
print(h, "-dpng", "output.png")
%pause()