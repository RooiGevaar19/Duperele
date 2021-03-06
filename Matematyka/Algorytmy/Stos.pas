program stosik;
{$mode OBJFPC}

uses crt;

const LEN = 10;

type Stack = array of Integer;

var 
    stos    : Stack;
    i       : Integer;

function init() : Stack;
var x : Stack;
begin
    SetLength(x, 0);
    init := x;
end;

procedure push(var st : Stack; num : Integer);
var size : Integer;
begin
    size := Length(st);
    SetLength(st, size+1);
    st[size] := num;
end;

function pop(var st : Stack) : Integer;
var size, val : Integer;
begin
    size := Length(st);
    val := st[size-1];
    SetLength(st, size-1);
    pop := val;
end;

function get(st : Stack) : Integer;
begin
    get := st[Length(st)-1];
end;

procedure sort(var tab : Stack);
var
  i, j : Longint;
  pom  : Integer;
begin
    for j := Length(tab)-1 downto 1 do
        for i := 0 to j-1 do 
            if (tab[i] > tab[i+1]) then begin
                pom := tab[i];
                tab[i] := tab[i+1];
                tab[i+1] := pom;
            end;
end;

begin
    randomize;
    stos := init();

    writeln('Stosik !!!!!');
    writeln('Kładziemy:');
    for i := 1 to LEN do 
    begin
        push(stos, random(20));
        writeln(' - ', get(stos));
    end;

    writeln('Sortujemy!');
    sort(stos);

    writeln('Zdejmujemy:');
    for i := 1 to LEN do writeln(' - ', pop(stos));

    writeln('Voila!');
end.