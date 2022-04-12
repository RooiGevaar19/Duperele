%skrypt tworzy macierz - "tabliczke mnozenia"
n=input("podaj wymiar n: ")
A=1:n;
for i=2:n
    A=[A; i:i:i*n];
end
A