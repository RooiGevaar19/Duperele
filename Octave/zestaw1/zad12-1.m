function y = f(x)
    y = x^3 + 5*x - 2;
end

n = input("podaj ilosc iteracji: ");

a = 0;
b = 1;

c1=(a+b)*0.5;
for k=2:n
    if f(a)*f(c1)<0
        b=c1;
    else
        a=c1;
    end;
    c0=c1;
    c1=(a+b)*0.5;
end;

disp('x = '), disp(c1);

r=roots([1 0 5 -2])