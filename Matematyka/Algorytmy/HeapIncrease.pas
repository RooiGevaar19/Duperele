program HeapSort;

uses sysutils;

const
    MAX = 10;
    RNG = 20;

type Heap = Array of Integer;

var
    table : Heap;

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

function parent(x : Integer) : Integer;
begin
    parent := x div 2;
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
    for i := High(T) downto Low(T)+1 do
    begin
        swap(T[Low(T)], T[i]);
        heapify(T, i, Low(T));
    end;
end;

procedure HeapIncreaseKey(var T : Array of Integer; i : Integer; K : Integer);
begin
    if (k < T[i]) then Exit;
    T[i] := k;
    while (i >= 1) and (T[parent(i)] < T[i]) do
    begin
        swap(T[i], T[parent(i)]);
        i := parent(i);
    end;
end;

function HeapExtractMax(var T : Heap) : Integer;
var 
    i, val : Integer;
begin
    if (Length(T) = 0) then Exit;
    val := T[Low(T)];
    for i := Low(T)+1 to High(T) do T[i-1] := T[i];
    SetLength(T, Length(T)-1);
    buildHeap(T);
    HeapExtractMax := val;
end;

procedure HeapInsert(var T : Heap; key : Integer);
begin
    SetLength(T, Length(T)+1);
    T[High(T)] := key-1;
    HeapIncreaseKey(T, High(T), key);
end;

begin
    randomize;
    SetLength(table, MAX);
    fillRandomIntegers(table, RNG);
    writeln('HEAPINCREASEKEY!!!');
    writeln('Before           : ', tableToString(table));
    buildHeap(table);
    writeln('Heap             : ', tableToString(table));
    HeapIncreaseKey(table, High(table) div 2, 0);
    writeln('After increase   : ', tableToString(table));
    writeln('Extracted        : ', HeapExtractMax(table));
    writeln('After extraction : ', tableToString(table));
    HeapInsert(table, 2137);
    HeapInsert(table, 1488);
    writeln('After insertion  : ', tableToString(table));
end.