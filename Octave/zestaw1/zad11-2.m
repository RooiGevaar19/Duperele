function y = f(x)
    y = x^3 + 5*x - 2;
end

function y = df(x)
    y = 3*x^2 + 5;
end

# https://eduinf.waw.pl/inf/alg/005_root/0013.php
function y = f_iteracji(x)
    y = x - (f(x)/df(x));
end


n=input('podaj ilosc iteracji: ')
x0 = 0;
x1=f_iteracji(x0);
for k=2:n
x0=x1;
x1=f_iteracji(x0);
end;
disp('x= '), disp(x1);

r=roots([1 0 5 -2])