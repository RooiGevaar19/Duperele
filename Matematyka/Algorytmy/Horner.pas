program Horner;

var
    n, i, x : Integer;
    A       : Array of Integer;

function horner(A : Array of Integer; grade, x : Integer) : Integer;
var
    res, i : Integer;
begin
    res := A[0];
	for i:= 1 to grade do res := res*x + A[i];
	horner := res;
end;

begin
    write('Podaj stopień wielomianu: ');
    readln(n);
    SetLength(A, n+1);
    for i := High(A) downto Low(A) do
    begin
        write('Podaj współczynnik przy potędze ', i, ': ');
        readln(A[i]);
    end;
    write('Podaj argument x: '); 
    readln(x);

    writeln();
    writeln('W(', x, ') = ', horner(A, n, x));
end.