program mergesort;

uses crt;

const 
    MAX   = 25;
    RANGE = 200;

type TInteger = array of Integer;
type Queue = array of Integer;

var
    table  : array of Integer;
    i      : Integer;

// ====== KOLEJKA

function init() : Queue;
var x : Queue;
begin
    SetLength(x, 0);
    init := x;
end;

procedure enqueue(var st : Queue; num : Integer);
var size : Integer;
begin
    size := Length(st);
    SetLength(st, size+1);
    st[size] := num;
end;

function dequeue(var st : Queue) : Integer;
var size, i, val : Integer;
begin
    size := Length(st);
    val := st[0];
    for i := 1 to size-1 do st[i-1] := st[i];
    SetLength(st, size-1);
    dequeue := val;
end;

// ====== MERGESORT

procedure MSMerge(var a : TInteger; left, mid, right : Integer);
var
    q1, q2 : Queue;
    i      : Integer;
begin
    q1 := init();
    q2 := init();

    for i := left to mid do enqueue(q1, a[i]);
    for i := mid+1 to right do enqueue(q2, a[i]);

    for i := left to right do
    begin
        if ((Length(q1) = 0) and (Length(q2) = 0)) then
        begin 
            continue;
        end else if (Length(q1) = 0) then
        begin
            a[i] := dequeue(q2);
        end else if (Length(q2) = 0) then
        begin
            a[i] := dequeue(q1);
        end else begin
            if (q1[0] > q2[0]) then
            begin
                a[i] := dequeue(q2);
            end else begin
                a[i] := dequeue(q1);
            end;
        end;
    end;
end;

procedure MSEngine(var a : TInteger; l , r : Integer);
var 
  m : Integer;
begin
  if l=r then Exit;
  m:= (l+r) div 2;
  MSEngine(a, l, m);
  MSEngine(a, m+1, r);
  MSMerge(a, l, m, r);
end;

procedure MergeSort(var tab : TInteger);
begin
    if (Length(tab) <= 1) then Exit;
    MSEngine(tab, low(tab), high(tab));
end;

// ====== MAIN

begin
    randomize;

    SetLength(table, MAX);
    for i := 0 to MAX-1 do table[i] := random(2*RANGE)-RANGE;
    
    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();

    MergeSort(table);

    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();
    
end.