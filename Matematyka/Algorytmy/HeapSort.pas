program HeapSort;

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

// ========== funkcje do kopców

function left(x : Integer) : Integer;
begin
    left := x * 2 + 1;
end;

function right(x : Integer) : Integer;
begin
    right := x * 2 + 2;
end;

procedure swap(var x, y : Integer);
begin
    x := x + y;
    y := x - y; 
    x := x - y;
end;

procedure heapify(var T : Array of Integer; n : Integer; i : Integer);
var
    l, r    : Integer;
    largest : Integer;
begin
    largest := i;
    l := left(i);
    r := right(i);
    if (l < n) and (T[l] > T[largest]) then largest := l;
    if (r < n) and (T[r] > T[largest]) then largest := r;

    if largest <> i then
    begin
        swap(T[i], T[largest]);
        heapify(T, n, largest);
    end;
end;

procedure buildHeap(var T : Array of Integer);
var i : Integer;
begin
    for i := High(T) div 2 downto Low(T) do
        heapify(T, Length(T), i); 
end;

procedure HeapSort(var T : Array of Integer);
var i : Integer;
begin
    buildHeap(T);
    writeln('Heap  : ', tableToString(table));
    for i := High(T) downto Low(T)+1 do
    begin
        swap(T[Low(T)], T[i]);
        heapify(T, i, Low(T));
        writeln('Step  : ', tableToString(table));
    end;
end;

begin
    randomize;
    SetLength(table, MAX);
    fillRandomIntegers(table, RNG);
    writeln('HEAPSORT!!!');
    writeln('Before: ', tableToString(table));
    HeapSort(table);
    writeln('After : ', tableToString(table));
end.