do
    n = input("podaj wymiar n (min. 4): ", "s");
until (isstrprop(n, "digit") && (str2num(n) >= 4));
n = str2num(n);

A=1:n;
for i=2:n
    A=[A; i:i:i*n];
end

do
    printf("Wybierz opcję: \n");
    printf("  1 - Pokaż tabliczkę mnożenia   \n");
    printf("  2 - Pokaż nieparzyste kolumny  \n");
    printf("  3 - Pokaż parzyste kolumny     \n");
    printf("  4 - Pokaż przekątną tabliczki  \n");
    printf("  5 - Zamień wiersze w tabliczce \n");
    printf("  6 - Zamień kolumny w tabliczce \n");
    printf("  0 - Wyjdź \n");
    command = input("Twój wybór: ","s");
until (isstrprop(command, "digit") && (any(0:6 == str2num(command))));
command = str2num(command);

if (command == 1)
    A
elseif (command == 2)
    B = A(:,2); 
    k=4;
    while k<=n
        B=[B A(:,k)]; k=k+2;
    end
    B
elseif (command == 3)
    B = A(:,1); 
    k=3;
    while k<=n
        B=[B A(:,k)]; k=k+2;
    end
    B
elseif (command == 4)
    d = diag(A);
    d
elseif (command == 5)
    disp("podaj numery wierszy w A do zamiany")
    nr1=input("nr1: "); 
    nr2=input("nr2: ");
    pom = A(nr1, :); 
    A(nr1, :) = A(nr2, :); 
    A(nr2, :) = pom;
    A
elseif (command == 6)
    disp("podaj numery kolumn w A do zamiany")
    nr1=input("nr1: "); 
    nr2=input("nr2: ");
    pom = A(:, nr1); 
    A(:, nr1) = A(:, nr2); 
    A(:, nr2) = pom;
    A
else
    printf("Wyjście.\n");
end;