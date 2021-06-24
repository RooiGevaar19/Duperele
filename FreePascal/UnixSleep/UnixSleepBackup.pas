program example72;

{ Program to demonstrate the NanoSleep function. }

uses BaseUnix;

const MIL = 1000000;

var
    Req,Rem : TimeSpec;
    Res     : Longint;

begin
    With Req do
    begin
        tv_sec := 0;
        tv_nsec:= 500 * MIL;
    end;
    Write('NanoSleep returned : ');
    Flush(Output);
    Res:=(fpNanoSleep(@Req,@rem));
    Writeln(res);
    If (res<>0) then
        With rem do
        begin
            Writeln('Remaining seconds     : ',tv_sec);
            Writeln('Remaining nanoseconds : ',tv_nsec);
        end;
end.