program recurringsort;

uses crt, SysUtils, StrUtils;

const 
    MAX = 25;
    RNG = 200;

var
    table  : array of Integer;
    i      : Integer;

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
        tableToString := 'null';
    end else begin
        s := '';
        for i := Low(T) to High(T) do s := s + IntToStr(T[i]) + ' ';
        s := s + #8;
        tableToString := s;
    end;
end;

function tableToString(T : Array of Integer; pad : Integer) : String;
var
    i : Integer;
    s : String;
begin
    if Length(T) = 0 then
    begin
        tableToString := 'null';
    end else begin
        s := '';
        for i := Low(T) to High(T) do s := s + PadLeft(IntToStr(T[i]), pad) + ' ';
        s := s + #8;
        tableToString := s;
    end;
end;

function tableToCuteString(T : Array of Integer) : String;
var
    i : Integer;
    s : String;
begin
    if Length(T) = 0 then
    begin
        tableToCuteString := '[]';
    end else begin
        s := '[';
        for i := Low(T) to High(T) do s := s + IntToStr(T[i]) + ', ';
        s := s + #8 + #8 + ']';
        tableToCuteString := s;
    end;
end;

procedure Rekurencja(var A : Array of Integer; p : Integer);
var
    i, k : Integer;
begin
    if (0 < p) then
    begin
        Rekurencja(A, p-1);
        k := A[p];
        i := p-1;
        while (A[i] > k) and (i >= 0) do
        begin
            A[i+1] := A[i];
            i := i-1;
        end;
        A[i+1] := k;
    end;
end;

begin
    randomize;
    SetLength(table, MAX);
    fillRandom(table, RNG);
    writeln(tableToString(table, 4));
    Rekurencja(table, High(table));
    writeln(tableToString(table, 4));
end.