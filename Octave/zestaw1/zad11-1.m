function y = f_iteracji(x)
    y = 0.2*(2-x^3)
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