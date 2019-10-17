program stosik;
{$mode OBJFPC}

uses crt;

const LEN = 10;

type Queue = array of Integer;

var 
    stos    : Queue;
    i       : Integer;

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

function getHead(st : Queue) : Integer;
begin
    getHead := st[0];
end;

function getTail(st : Queue) : Integer;
begin
    getTail := st[Length(st)-1];
end;

procedure sort(var tab : Queue);
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

    writeln('Kolejeczka !!!!!');
    writeln('Kładziemy:');
    for i := 1 to LEN do 
    begin
        enqueue(stos, random(20));
        writeln(' - ', getTail(stos));
    end;

    writeln('Zdejmujemy:');
    for i := 1 to LEN do writeln(' - ', dequeue(stos));

    writeln('Voila!');
end.