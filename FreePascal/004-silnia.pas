program silnia;

uses
  SysUtils;     // moduł pozwalający na konwersję z Integer to String (funkcja IntToStr())

// funkcje - działania pozwalające na wielokrotne obliczanie pewnych wartości na podstawie zadanych argumentóœ wejściowych 

function silnia_iteracyjna_while (x : Integer) : LongInt; // funkcja przyjmuje 1 argument Integer i zwraca wartosc typu LongInt
var
  s : LongInt;
begin
  s := 1;
  while (x > 1) do                    // początek pętli while - jeżeli na wstępie warunek się nie spełni (tj. x będzie równe 0 albo 1), to pętla zostanie pominięta
  begin
    s := s * x;
    dec(x);                           // dekrementacja - wartość x zostnaie zmniejszona o 1 - analogicznie inc(x) inkrementuje, czyli zwiększa wartość x o 1
  end;
  silnia_iteracyjna_while := s;       // instrukcja przypisująca wynik do wyjścia funkcji
end;

function silnia_iteracyjna_for_up (x : Integer) : LongInt;
var
  s : LongInt;
  i : Integer;
begin
      s := 1;
      for i := 1 to x do s := s * i;  // pętla for iteruje od liczby 1 do x rosnąco
      silnia_iteracyjna_for_up := s;  // jeżeli pętla ma iterować do mniejszej liczby niż liczba startowa, to pętla się nie wykona
end;

function silnia_iteracyjna_for_down (x : Integer) : LongInt;
var
  s : LongInt;
  i : Integer;
begin
      s := 1;
      for i := x downto 1 do s := s * i;  // pętla for iteruje od liczby x do 1 malejąco
      silnia_iteracyjna_for_down := s;    // jeżeli pętla ma iterować do większej liczby niż liczba startowa, to pętla się nie wykona
end;

function silnia_iteracyjna_foreach (x : Integer) : LongInt;
var
  s : LongInt;
  i : Integer;
begin
    s := 1;
    for i in [1..x] do s := s * i;      // pętla foreach porusza się po zbiorze - może też poruszać się po kolekcjach i listach
    silnia_iteracyjna_foreach := s;     // zbiór w pętli jest niepoprawny, jeżeli x = 0, wtedy pętla się nie wykona
end;

function silnia_rekurencyjna (x : Integer) : LongInt;   // rekurencja to odwołanie funkcji do samej siebie
begin                                                   // jest prostsza w zapisie niż iteracja, ale bardziej zużywa pamięć
  if (x = 0) then silnia_rekurencyjna := 1              // przy konstrukcji if-else pojedyńcza instrukcja przed else nie jest zakończona średnikiem
  else silnia_rekurencyjna := x * silnia_rekurencyjna(x-1);   // z rekurencyjnejdefinicji silni -> n! = n * (n-1)!
end;

// ciało główne programu
begin
  writeln(IntToStr(1*2*3*4*5*6));
  writeln(silnia_iteracyjna_while(6));
  writeln(silnia_iteracyjna_for_up(6));
  writeln(silnia_iteracyjna_for_down(6));
  writeln(silnia_iteracyjna_foreach(6));
  writeln(silnia_rekurencyjna(6));
  writeln();
  writeln(IntToStr(1));
  writeln(silnia_iteracyjna_while(0));
  writeln(silnia_iteracyjna_for_up(0));
  writeln(silnia_iteracyjna_for_down(0));
  writeln(silnia_iteracyjna_foreach(0));
  writeln(silnia_rekurencyjna(0));
  writeln();
end.
