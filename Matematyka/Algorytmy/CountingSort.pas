program CountingSort;

uses sysutils;

const
    MAX = 40;
    RNG = 200;

var
    table : Array of Integer;

// ========== zapełnianie i wypisywanie tablicy

procedure fillRandomNaturals(var T : Array of Integer; range : Integer);
var
    i : Integer;
begin
    for i := Low(T) to High(T) do table[i] := random(RNG);
end;

procedure fillRandomIntegers(var T : Array of Integer; range : Integer);
var
    i : Integer;
begin
    for i := Low(T) to High(T) do table[i] := random(2*RNG)-RNG;
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

// Sortowanie przez zliczanie

function tableMax(T : Array of Integer) : Integer;
var i, s : Integer;
begin
    s := T[Low(T)];
    for i := Low(T)+1 to High(T) do
        if (T[i] > s) then
            s := T[i];
    tableMax := s;
end;

procedure CountingSort(var A : Array of Integer);
var
    n, k : Integer;
    B, C : Array of Integer;
    i    : Integer;
begin
    k := tableMax(A);
    n := Length(A);
    SetLength(C, k+1);
    SetLength(B, n);
    for i := 0 to k do C[i] := 0;
    for i := 0 to n-1 do C[A[i]] := C[A[i]]+1;
    for i := 1 to k do C[i] := C[i] + C[i-1];
    for i := n-1 downto 0 do
    begin
        B[C[A[i]] - 1] := A[i];
        C[A[i]] := C[A[i]] - 1;
    end;
    for i := 0 to n-1 do A[i] := B[i];
end;

begin
    randomize;
    SetLength(table, MAX);
    fillRandomNaturals(table, RNG);
    writeln('COUNTING SORT!!!');
    writeln('Before: ', tableToString(table));
    CountingSort(table);
    writeln('After : ', tableToString(table));
end.