function y = f(x)
    y = x^3 + 5*x - 2;
end

function y = df(x)
    y = 3*x^2 + 5;
end


# https://eduinf.waw.pl/inf/alg/005_root/0012.php
function y = f_siecz(x1, x2)
    if (f(x1) - f(x2) != 0)
        y = x1 - f(x1)*((x1 - x2)/(f(x1) - f(x2)))
    else 
        # dla bardzo małych różnic lepiej użyć pochodnej zamiast ilorazu różnicowego
        y = x1 - (f(x1)/df(x1));
    endif
end

n=input("podaj ilosc iteracji: ");

x0=0;
x1=1;
x2=f_siecz(x0,x1);

for k=3:n
    x0=x1;
    x1=x2;
    x2=f_siecz(x0,x1);
end;
disp("x= "), disp(x2);

r=roots([1 0 5 -2])