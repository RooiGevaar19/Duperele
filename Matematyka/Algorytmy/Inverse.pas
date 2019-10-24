program inverse;

const
    MAX = 6;
    RANGE = 20;

var
    table : Array of Integer;
    i     : Integer;

function countInverse(T : Array of Integer) : Integer;
var
    count, i, j : Integer;
begin
    count := 0;
    for i := 0 to Length(T)-2 do
        for j := i+1 to Length(T)-1 do
            if T[i] > T[j] then 
                Inc(count);
    countInverse := count;
end;

begin
    randomize;
    SetLength(table, MAX);
    for i := 0 to MAX-1 do table[i] := random(RANGE);

    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();
    writeln('Liczba inwersji: ', countInverse(table));
end.