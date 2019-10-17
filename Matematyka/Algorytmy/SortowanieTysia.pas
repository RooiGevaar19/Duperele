program sortowanko;

const
    n = 6;

var
    A    : Array[1..n] of Integer;
    i, j : Longint;
    pom  : Integer;

begin
    writeln('Podaj 6 liczb: ');
    for i := 1 to n do read(A[i]);

    writeln('Podano:');
    for i := 1 to n do write(A[i]:4); // :4 oznacza, że napis zajmie miejsce o długości 4
    writeln();

    // sortowanko
    for i := 1 to n-1 do
        for j := i+1 to n do 
            if (A[j] < A[i]) then begin
                // zamieniamy wartości A[i] i A[j] miejscami
                pom := A[i];
                A[i] := A[j];
                A[j] := pom;
            end;

    writeln('Po posortowaniu:');
    for i := 1 to n do write(A[i]:4);
    writeln();
    //readln();
end.