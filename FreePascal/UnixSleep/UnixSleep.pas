program example72;

{ Program to demonstrate the NanoSleep function. }

uses BaseUnix;

const MIL = 1000000;



procedure Sleep(len : LongInt);
var
    Req,Rem : TimeSpec;
    Res     : Longint;
begin
    With Req do
    begin
        tv_sec := len div 1000;
        tv_nsec:= (len mod 1000) * MIL;
    end;
    //Flush(Output);
    Res:=(fpNanoSleep(@Req,@rem));
    //Writeln(res);
    //If (res<>0) then
    //    With rem do
    //    begin
    //        Writeln('Remaining seconds     : ',tv_sec);
    //        Writeln('Remaining nanoseconds : ',tv_nsec);
    //    end;
end;

begin
    writeln('zzz');
    Sleep(5700);
    writeln('Done');
end.