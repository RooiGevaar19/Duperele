program kontynuuj;

uses Classes, SysUtils;

var
  input, i  : String;
  StringSet : TStringList;
  flag      : Boolean;
begin
  StringSet := TStringList.Create;
  flag := False;
  repeat
    write('Podaj lancuch znakow (albo wcisnij ENTER by zakonczyc): '); readln(input);
    if input = '' then
    begin
      flag := True;
      writeln('Zakonczono.');
    end else begin
      StringSet.Add(input);
    end;
  until (flag = True);

  writeln();
  writeln('Tekst:');
  for i in StringSet do
  begin
      writeln(i);
  end;

  writeln('');
  writeln('Liczba linijek: '+IntToStr(StringSet.Count));
  StringSet.Free;
end.
