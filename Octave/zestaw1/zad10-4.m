disp("ustal a, b i c: ");
a = input("a = ");
b = input("b = ");
c = input("c = ");
r=roots([a b c]);
disp("pierwiastki p(x) = a*x^2 + b*x + c: ")
r

p=[a b c];

if (b^2 - 4*a*c < 0)
    px = b^2 / 2*a;
    x=[px-1:0.1:px+1];
else
    x=[min(r)-1:0.1:max(r)+1];
endif

y=polyval(p,x);

h=figure;
set(h,'visible','off');
plot(x,y), grid on
print(h, "-dpng", "output.png")