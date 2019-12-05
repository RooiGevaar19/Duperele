program inverse;

uses sysutils;

const
    MAX = 6;
    RNG = 20;

var
    table : Array of Integer;

procedure fillRandom(var T : Array of Integer; range : Integer);
var
    i : Integer;
begin
    for i := Low(T) to High(T) do table[i] := random(RNG);
end;

function tableToString(T : Array of Integer) : String;
var
    i : Integer;
    s : String;
begin
    if Length(T) = 0 then
    begin
        tableToString := '[]';
    end else begin
        s := '[';
        for i := Low(T) to High(T) do s := s + IntToStr(T[i]) + ', ';
        s := s + #8 + #8 + ']';
        tableToString := s;
    end;
end;

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
    fillRandom(table, RNG);
    writeln(tableToString(table));
    writeln('Liczba inwersji: ', countInverse(table));
end.