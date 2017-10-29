program bank;

const
  correctPin = 2137;
  MaxAttempts = 3;

// procedury i funkcje
// procedury to bloki komend, które można wykorzystywać wielokrotnie
// UWAGA: funkcje i procdury nie muszą przyjmować argumentów wejściowych, jak widać poniżej

procedure event_onCorrectPIN();
begin
  writeln('Poprawny PIN');
end;

procedure event_onWrongPIN();
begin
  writeln('Niepoprawny PIN');
end;

procedure event_onSuccess();
begin
  writeln('Zalogowano!');
end;

procedure event_onFail();
begin
  writeln('Za duzo zlych prob wprowadzenia numeru PIN.');
end;

function insertPIN() : Integer;
var
  x : Integer;
begin
  write('Podaj PIN: '); readln(x);
  insertPIN := x;
end;

function attempt_insertPIN() : Boolean;
var
  att        : Integer;
  if_success : Boolean;
begin
  if_success := False;
  for att := 1 to MaxAttempts do
  begin
    if (insertPIN() = correctPin) then
    begin
      event_onCorrectPIN();
      if_success := True;
      break;                                        // break powoduje przerwanie pętli
    end else begin
      event_onWrongPIN();
    end;
  end;
  attempt_insertPIN := if_success;
end;

// ciało główne programu
// główna część ogranicza się jedynie do wywołania odpowiednich funkcji i procedur, które sterują całym programem.
begin
  if (attempt_insertPIN()) then event_onSuccess() else event_onFail();
  // równie dobrze warunek może brzmieć if (attempt_insertPIN() = True), ale w przypadku funkcji boolean można skrócić zapis
end.
