program dupa;

uses sysutils, Unix;



procedure Beep(freq, length : Integer);
var 
    S : Longint;
begin
    //Writeln('Output of ls -l');
    //S := fpSystem('( speaker-test -t sine -f 1000 )& pid=$! ; sleep 0.1s ; kill -9 $pid');
    //S := fpSystem('speaker-test -t sine -f 440 -l 1 & sleep .3 && kill -9 $!');
    S := fpSystem('(speaker-test -t sine -f '+IntToStr(freq)+' & sleep '+FloatToStr(freq/1000)+' && kill -9 $!) > /dev/null');
    //Writeln('Command exited wwith status : ',S);
end;

//libc.so   linux
 
//procedure beep(freq:integer;duration:integer);cdecl external 'msvcrt.dll' name '_beep';
//procedure beep(freq:integer;duration:integer);cdecl external 'libc.so' name 'Beep';
//begin
//    beep(1000,200);
//    writeln('Press enter to end . . .');
//    readln;
//    beep(200,500);
//end.

begin
    Beep(440, 300);
    Beep(400, 300);
    Beep(300, 200);
    Beep(300, 200);
    Beep(400, 300);
    Beep(440, 300);
    Beep(480, 500);
end.
