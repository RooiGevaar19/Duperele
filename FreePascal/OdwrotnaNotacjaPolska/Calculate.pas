unit calculate;

interface

uses crt, sysutils;

type PStos = ^TStos;
TStos = record
    Liczba: real;
    Nastepny: PStos;
end;


const
        pi = 3.1415926535897932384626433832795;


var
        //pocz : pocz_stos;
        color : integer;
        clean : integer;
        globalsets : integer;


function calc_findfile(leer : string):integer;
function pow(x,y:real):real;
procedure calc_stack_add(var pocz:PStos; number:real);
function calc_stack_show(pocz:PStos) : real;
procedure calc_stack_remove(var pocz:PStos);
procedure calc_help();
procedure calc_globalsets_read();
procedure calc_program();

implementation

function calc_findfile(leer : string):integer;
Var Info : TSearchRec;
    flag : integer;
Begin
  flag := 0;
  If FindFirst ('*',faAnyFile and faDirectory,Info)=0 then
    begin
    Repeat
      With Info do
      begin
        If (Attr and faDirectory) <> faDirectory then
        begin
                if Name = leer then
                begin
                        flag := 1;
                        break;
                end;
        end;
      end;
    Until FindNext(info)<>0;
    end;
  FindClose(Info);
  if flag = 1 then calc_findfile := 1
  else calc_findfile := 0;
End;


function pow(x,y:real):real;
var
        s : real;
begin
        s := exp(y*ln(x));
        pow := s;
end;

procedure calc_stack_add(var pocz:PStos; number:real);
var
    Nowy: PStos;
  begin
    New(Nowy);
    Nowy^.Liczba := number;
    Nowy^.Nastepny := Pocz;
    Pocz := Nowy;
  end;


function calc_stack_show(pocz:PStos) : real;
begin
        calc_stack_show := pocz^.Liczba;
end;

procedure calc_stack_remove(var pocz:PStos);
var
    Pom: PStos;
  begin
    //while Pocz <> nil do
    //begin
      Pom := Pocz^.Nastepny;
      Dispose(Pocz);
      Pocz := Pom;
    //end;
  end;



procedure calc_help();
begin
        if clean = 1 then clrscr();
        writeln('**************************************');
        writeln('*       HELP - INSTRUCTIONS          *');
        writeln('*                                    *');
        writeln('* Reversed Polish Notation (RPN):    *');
        writeln('* in this case you put the opera-    *');
        writeln('* tors behind the numbers.           *');
        writeln('*                                    *');
        writeln('* EXAMPLES:                          *');
        writeln('* 2+3            -> 2 3 +            *');
        writeln('* (12-6)/3       -> 12 6 - 3 /       *');
        writeln('* 5*(2-9)        -> 5 2 9 - *        *');
        writeln('* (12-4)/(4^0.5) -> 12 4 - 4 0.5 ^ / *');
        write('*                                    *');
        readln();
        writeln('* To type a pi number, type          *');
        writeln('* ''p''. PI ~= 3.141592653589793       *');
        writeln('*                                    *');
        writeln('* To type an Euler''s number, type    *');
        writeln('* ''e''. e ~= 2.718281828459           *');
        writeln('*                                    *');
        writeln('* Type ''n'' to type another           *');
        writeln('* number and then type that          *');
        writeln('* number.                            *');
        write('*                                    *');
        readln();
        writeln('* Type ''o'' to type a command         *');
        writeln('* and then type a symbol of that.    *');
        writeln('* command.                           *');
        writeln('*      AVAILABLE COMMANDS            *');
        writeln('*      + -> add                      *');
        writeln('*      - -> substract                *');
        writeln('*      * -> multiply                 *');
        writeln('*      / -> divide                   *');
        writeln('*      ^ -> power                    *');
        writeln('*      r -> root                     *');
        writeln('*      l -> logarithm                *');
        writeln('*                                    *');
        writeln('**************************************');
        readln;

end;

procedure calc_globalsets_read();
var
        conf : text;
begin
        assign(conf,'global.cfg');
        reset(conf);
        readln(conf, clean);
        readln(conf);
        readln(conf, color);
        readln(conf);
        close(conf);
end;


procedure calc_program();
var
        com, op : array[0..255] of char;
        n : array[0..255] of real;
        ilosc : integer;
        x, y, z : real;
        i, error : integer;
        command, quest : char;
        pocz : PStos;
begin
        color := 1;
        clean := 1;
        if calc_findfile('global.cfg') = 1 then calc_globalsets_read();
        repeat
                if clean = 1 then clrscr();
                if color = 1 then TextColor(15);
                writeln('*******************************');
                writeln('*    |----\  -----\  \   |    *');
                writeln('*    |    |  |    |  |\  |    *');
                writeln('*    |----/  |----/  | \ |    *');
                writeln('*    | \     |       |  \|    *');
                writeln('*    |  \    |       |   \    *');
                writeln('*                             *');
                writeln('*******************************');
                writeln('*  Welcome to RPN Calculator! *');
                writeln('*                             *');
                writeln('* Type A to calculate !       *');
                writeln('* Type H for help             *');
                writeln('* Type O for options          *');
                writeln('* Type Q to quit program      *');
                writeln('*******************************');
                //readln(command);
                command := readkey;
                if (command = 'h') or (command = 'H') then
                begin
                        calc_help();
                end;
                if (command = 'q') or (command = 'Q') then
                begin
                        repeat
                        if clean = 1 then clrscr();
                        writeln('*******************************');
                        writeln('*Are you sure you wanna quit ?*');
                        writeln('*    Y -> Yes                 *');
                        writeln('*    N -> No, I want to       *');
                        writeln('*         calculate more!     *');
                        writeln('*******************************');
                        quest := readkey;
                        until (quest = 'y')or(quest = 'n')or(quest = 'Y')or(quest = 'N');
                end;
                if (command = 'o') or (command = 'Q') then
                begin
                        repeat
                        if clean = 1 then clrscr();
                        writeln('*******************************');
                        writeln('*  Colors:                    *');
                        writeln('*  0 -> No Color              *');
                        writeln('*  1 -> Color (default)       *');
                        writeln('*                             *');
                        writeln('*******************************');
                        readln(color);
                        until (color = 0)or(color = 1);
                        if color = 0 then TextColor(7);
                        if color = 1 then TextColor(15);
		        repeat
                        if clean = 1 then clrscr();
                        writeln('*******************************');
                        writeln('*  Cleaning screen:           *');
                        writeln('*  0 -> Off                   *');
                        writeln('*  1 -> On (default)          *');
                        writeln('*                             *');
                        writeln('*******************************');
                        readln(clean);
                        until (clean = 0)or(clean = 1);
                end;
                if command = 'a' then
        begin
        error := 0;
        if clean = 1 then clrscr();
        writeln('*****************************************************');
        writeln('* CALCULATING RPN !!!');
        write('* How many instructions? : ');
        if color = 1 then TextColor(7);
        readln(ilosc);
        if clean = 1 then clrscr();
        if color = 1 then TextColor(15);
        writeln('*****************************************************');
        for i := 0 to ilosc-1 do
        begin
                if color = 1 then TextColor(15);
                write('* Type the ',i+1,'. command: ');
                if color = 1 then TextColor(7);
                readln(com[i]);
                if (com[i] = 'n') then
                begin
                        if color = 1 then TextColor(15);
                        write('* Type that number: ');
                        if color = 1 then TextColor(7);
                        readln(n[i]);
                end;
                if (com[i] = 'e') then
                begin
                        n[i] := exp(1);
                end;
                if (com[i] = 'o') then
                begin
                        if color = 1 then TextColor(15);
                        write('* Type the symbol: ');
                        if color = 1 then TextColor(7);
                        readln(op[i]);
                end;
                if (com[i] = 'p') then
                begin
                	n[i] := pi;
                end;
                if color = 1 then TextColor(15);
                writeln('*--------------------------------------------');
        end;
        if clean = 1 then clrscr();
        writeln('*****************************************************');

        write('* THE TYPED RPN -> ');
        if color = 1 then TextColor(14);
        for i := 0 to ilosc-1 do
        begin

                if (com[i] = 'n') then
                begin
                        write(n[i]:2:2,' ');
                        continue;
                end
                else
                begin
            		if (com[i] = 'e') then
            		begin
            			write('e ');
                                continue;
            		end
            		else
            		begin
            			if (com[i] = 'p') then
            			begin
            				write('PI ');
                        	        continue;
            			end
                		else
                		begin
                        	if (com[i] = 'o') then
                        	begin

                            	if (op[i] = 'l') then
                            	begin
                                	write('log ');
                                	continue;
                            	end;
                            	if (op[i] = 'r') then
                            	begin
                                	write('root ');
                                	continue;
                            	end;
                                write(op[i],' ');
                            	continue;
                        	end
                        	else
                        	begin
                            	        error := 1; // input error
                                        continue;
                        	end;

           			end;
           		end;
        	end;
        end;
        if (error > 0) then break;
        writeln();
        if color = 1 then TextColor(15);
        write('*----------------------------------------------------');
        readln();

        pocz := nil;
        for i := 0 to ilosc-1 do
        begin
                if ((com[i] = 'n')or(com[i] = 'e')or(com[i] = 'p')) then
                begin
                        calc_stack_add(pocz, n[i]);
                end
                else
                begin
                        if (com[i] = 'o') then
                        begin
                                case op[i] of
                                        '+' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                z := x+y;
                                                calc_stack_add(pocz, z);
                                                continue;
                                        end;
                                        '-' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                z := x-y;
                                                calc_stack_add(pocz, z);
                                                continue;
                                        end;
                                        '*' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                z := x*y;
                                                calc_stack_add(pocz, z);
                                                continue;
                                        end;
                                        '/' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                if y = 0 then begin
                                                        error := 2; // divide by zero
                                                        break;
                                                end
                                                else
                                                begin
                                                        z := x/y;
                                                        calc_stack_add(pocz, z);
                                                end;
                                                continue;
                                        end;
                                        '^' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                z := pow(x,y);
                                                calc_stack_add(pocz, z);
                                                continue;
                                        end;
                                        'r' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                if y = 0 then begin
                                                        error := 3; // 0th root
                                                        break;
                                                end
                                                else
                                                begin
                                                        z := pow(x,1/y);
                                                        calc_stack_add(pocz, z);
                                                end;
                                                continue;
                                        end;
                                        'l' : begin
                                                y := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                x := pocz^.Liczba;
                                                calc_stack_remove(pocz);
                                                if ln(y) = 0 then begin
                                                        error := 2; // divide by zero
                                                        break;
                                                end
                                                else
                                                begin
                                                        z := ln(2)/ln(3);
                                                        calc_stack_add(pocz, z);
                                                end;
                                                calc_stack_add(pocz, z);
                                                continue;
                                        end
                                        else begin
                                                error := 1; // input error
                                                continue;
                                        end;
                                end;
                        end
                        else
                        begin
                                error := 1; // input error
                                continue;
                        end;
                end;
        end;
        if (error > 0) then break;
        if (pocz^.Liczba <= 4294967296) then
        begin
                z := pocz^.Liczba;
                if color = 1 then TextColor(15);
                write('* Result: ');
                if color = 1 then TextColor(12);
                writeln(z:2:16);
        end
        else
        begin
                if color = 1 then TextColor(15);
                write('* Result: ');
                if color = 1 then TextColor(12);
                writeln(pocz^.Liczba);
        end;
        if color = 1 then TextColor(15);
        writeln('*****************************************************');
        readln();
        while pocz <> nil do calc_stack_remove(pocz);
        end;

        until (quest = 'y') or (quest = 'Y');
        if color = 1 then TextColor(7);
end;

end.
