program insertionsort;

uses crt;

const 
    MAX   = 25;
    RANGE = 200;

var
    table  : array of Integer;
    i      : Integer;


procedure InsertionSort(var T : array of Integer);
var
    i, j, k, n : Integer;
begin
    n := Length(T);
    for i := 1 to n-1 do
    begin
        k := T[i]; 
        j := i-1;
        while (j >= 0) and (k < T[j]) do
        begin
            T[j+1] := T[j];
            j := j-1;
        end;
        T[j+1] := k;
    end;
end;

begin
    randomize;

    SetLength(table, MAX);
    for i := 0 to MAX-1 do table[i] := random(RANGE);
    
    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();

    InsertionSort(table);

    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();
end.