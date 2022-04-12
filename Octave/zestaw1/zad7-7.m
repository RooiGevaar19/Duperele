%skrypt tworzy macierz - "tabliczke mnozenia"
n=input("podaj wymiar n: ");
A=1:n;
for i=2:n
    A=[A; i:i:i*n];
end
# A

%w macierzy A zmiana wiersza nr1 i nr2
disp("podaj numery kolumn w A do zamiany")
nr1=input("nr1: "); 
nr2=input("nr2: ");
pom = A(:, nr1); 
A(:, nr1) = A(:, nr2); 
A(:, nr2) = pom;
A