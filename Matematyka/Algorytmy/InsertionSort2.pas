program insertionsort;

uses crt;

const 
    MAX   = 25;
    RANGE = 200;

var
    table  : array of Integer;
    i      : Integer;


procedure InsertionSort2(var T : array of Integer);
var
    i, j, pom, n : Integer;
begin
    n := Length(T);
    for i := 1 to n-1 do
        for j := i downto 1 do
            if (T[j-1] > T[j]) then
            begin
                pom := T[j-1];
                T[j-1] := T[j];
                T[j] := pom;
            end else begin
                break;
            end;
end;

begin
    randomize;

    SetLength(table, MAX);
    for i := 0 to MAX-1 do table[i] := random(RANGE);
    
    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();

    InsertionSort2(table);

    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();
end.