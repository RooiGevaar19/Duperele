program bsearch;

uses crt;

const
    MAX = 40;
    RANGE = 200;

var
    table  : array of Integer;
    guess  : Integer;
    i      : Integer;
    result : Integer;

procedure sort(var tab : array of Integer);
var
  i, j : Longint;
  pom  : Integer;
begin
    for j := Length(tab) downto 1 do
        for i := 0 to j-1 do 
            if (tab[i] > tab[i+1]) then begin
                pom := tab[i];
                tab[i] := tab[i+1];
                tab[i+1] := pom;
            end;
end;

procedure sort2(var tab : array of Integer);
var
  i, j : Longint;
  pom  : Integer;
begin
    for i := 0 to Length(tab)-2 do
        for j := i+1 to Length(tab)-1 do 
            if (tab[j] < tab[i]) then begin
                pom := tab[i];
                tab[i] := tab[j];
                tab[j] := pom;
            end;
end;


function bSearch(tab : array of Integer; match, left, right : Integer) : Integer;
var
    middle : Integer;
begin
    middle := (left+right) div 2;
    writeln('left=', left+1 : 3, ' right=', right+1 : 3, ' mid=', middle+1 : 3);
    if (left >= right) then
    begin
        if (tab[left] = match) then bSearch := left else bSearch := -1;
    end else begin
        if match = tab[middle] then bSearch := middle;
        if match < tab[middle] then bSearch := bSearch(tab, match, left, middle-1);
        if match > tab[middle] then bSearch := bSearch(tab, match, middle+1, right);
    end;
end;

function binarySearch(tab : array of Integer; match : Integer) : Integer;
begin
    binarySearch := bSearch(tab, match, 0, Length(tab)-1);
end;

begin
    randomize;

    SetLength(table, MAX);
    for i := 0 to MAX-1 do table[i] := random(RANGE);
    sort2(table);

    for i := 0 to MAX-1 do write(table[i]:4, ' ');
    writeln();

    write('Podaj liczbę od 0 do ', RANGE,': ');
    readln(guess);

    writeln();
    writeln('Szukamy:');
    result := binarySearch(table, guess);
    if (result = -1) then
    begin
        writeln('Nie znaleziono elementu!');
    end else begin
        writeln('Element nr. ', result+1, ': ', table[result]);
    end;
end.