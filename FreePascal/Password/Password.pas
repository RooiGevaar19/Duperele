program pass;

{$MODE OBJFPC}

uses Keyboard;

procedure StopWorking();
begin
    writeln();
    writeln('Zatrzymano.');
    Halt(1);
end;

function KeyInput() : Char;
var
    Key: TKeyEvent;
begin
    InitKeyBoard;
    try
        Key:= GetKeyEvent;
        Key:= TranslateKeyEvent(Key);
        Result := GetKeyEventChar(Key);
    finally
        DoneKeyBoard;
    end;
end;

function readPassword() : String;
var
   Pwstring : String;
   pwchar   : Char;
begin
    Pwstring:='';
    repeat
        Pwchar := KeyInput();
        if PwChar = ^C then StopWorking()
        else if PwChar <> #13 then
        begin
            pwstring:=pwstring+Pwchar;
            write('*')
        end;
    until pwchar = #13;
    Result := pwstring;
end;

function readlnPassword() : String;
var
   Pwstring : String;
   pwchar   : Char;
begin
    Pwstring:='';
    repeat
        Pwchar := KeyInput();
        if PwChar = ^C then StopWorking()
        else if PwChar <> #13 then
        begin
            pwstring:=pwstring+Pwchar;
            write('*');
        end;
    until pwchar = #13;
    writeln();
    Result := pwstring;
end;

function authenticate(input : String) : Boolean;
begin
    Result := input = 'papiesz';
end;

var 
    input : String;

begin
    while True do
    begin
        write('Podaj hasło: ');
        input := readlnPassword();
        if (authenticate(input)) then Break;
        writeln('Złe hasło.');
    end;
    writeln('Dobre hasło! <3 XD');
end.