disp("ustal a, b: ");
#disp("ustal a, b i c: ");
a = input("a = ");
b = input("b = ");
#c = input("c = ");
r=roots([a b]);
#r=roots([a b c]);
disp("pierwiastki p(x) = a*x + b: ")
#disp("pierwiastki p(x) = a*x^2 + b*x + c: ")
r

p=[a b];
#p=[a b c];
x=[r-1:0.1:r+1];
y=polyval(p,x);

h=figure;
set(h,'visible','off');
plot(x,y), grid on
print(h, "-dpng", "output.png")