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

// ========== quicksort

procedure swap(var x, y : Integer);
begin
    x := x + y;
    y := x - y; 
    x := x - y;
end;

function Partition(var arr : Array of Integer; low : Integer; high : Integer) : Integer
begin
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
end;

procedure QuickSortEngine(var A : Array of Integer; p : Integer; r : Integer);		// klasyczny QuickSort
var q : Integer;
begin
	if (p < r) then
	begin
		q := Partition(A,p,r);
		QuickSortEngine(A,p,q);
		QuickSortEngine(A,q+1,r);
	end;
end;

procedure QuickSort(var T : Array of Integer);
begin
    QuickSortEngine(T, Low(T), High(T));
end;

// ========== main

begin
    randomize;
    SetLength(table, MAX);
    fillRandomIntegers(table, RNG);
    writeln('QUICK SORT!!!');
    writeln('Before: ', tableToString(table));
    QuickSort(table);
    writeln('After : ', tableToString(table));
end.