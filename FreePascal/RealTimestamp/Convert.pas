program NAME;

{$mode objfpc}{$H+}

uses DateUtils, SysUtils;

function DateTimeToTimestamp(input : TDateTime) : Real;
var
    ts : LongInt;
    ms : Word;
    rs : Currency;
begin
    ts := DateTimeToUnix(RecodeMillisecond(input, 0));
    ms := MillisecondOf(input);
    rs := ts + ms/1000;
    Result := rs;
end;

var
    S : TDateTime;

begin
    s := Now;
    //s := EncodeDateTime(1945, 5, 9, 21, 37, 44, 235);
    writeln(MillisecondOf(s));
	writeln(DateTimeToTimestamp(s):2:6);
    writeln(DateTimeToStr(s));
end.
