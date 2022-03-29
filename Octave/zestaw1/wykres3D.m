clear
[x,y]=meshgrid(-2:0.2:2);
wzorg=input("podaj wzor funkcji g zmiennych x i y: ", "s");
g=eval(wzorg);
surf(x,y,g);