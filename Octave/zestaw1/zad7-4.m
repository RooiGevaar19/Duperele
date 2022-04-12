%skrypt tworzy macierz - "tabliczke mnozenia"
n=input("podaj wymiar n: ");
A=1:n;
for i=2:n
    A=[A; i:i:i*n];
end
# A

%B - co drugi wiersz macierzy A
B = A(:,1); 
k=3;
while k<=n
    B=[B A(:,k)]; k=k+2;
end
B