program kolejeczka;

const MAX = 6;
const PREF = 4;

type Queue = array[1..20] of Integer;

var
  kolejka    : Queue;
  input      : Integer;
  tail, head : Integer;
  i          : Integer;

procedure enqueue(var q : Queue; var tail : Integer; x : Integer);
begin
  if (tail >= MAX) then
  begin
       writeln('za wiele XD');
  end else begin
      Q[tail] := x;
      tail := tail + 1;
  end;
end;

function dequeue(var q : Queue; var head : Integer; var tail : Integer) : Integer;
var
   x : Integer;
begin
     if (head >= tail) then
     begin
          writeln('pusto XD');
          dequeue := -1;
     end else begin
          x := q[head];
          head := head + 1;
          dequeue := x;
     end;
end;

begin
     tail := 1; head := 1;
     for i := 1 to PREF do
     begin
          writeln('Podaj element: ');
          readln(input);
          enqueue(kolejka, tail, input);
     end;
     for i := 1 to PREF do
     begin
          writeln('Zdejmuje: ', dequeue(kolejka, head, tail));
     end;
     readln;
end.