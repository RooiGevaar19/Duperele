program kalkulator;
var
   s, a, b : Integer;           // można po przecinku deklarować wiele zmiennych tego samego typu
   t, x, y : Real;   		// typ Real - liczba rzeczywista
   command : String;
begin
     writeln('KALKULATOR');
     writeln('Co chcesz zrobic?');
     writeln(' +   : Dodawanie');
     writeln(' -   : Odejmowanie');
     writeln(' *   : Mnozenie');
     writeln(' div : Dzielenie calkowite');
     writeln(' mod : Reszta z dzielenia');
     writeln(' /   : Dzielenie rzeczywiste');
     write('Wpisz komende: '); readln(command);
     case command of	         // blok case pozwala rozpatrywać wiele przypadków wartości danej zmiennej
     	  '+' : begin
              write('Podaj pierwsza liczbe: '); readln(a);
              write('Podaj druga liczbe: '); readln(b);
              s := a + b;  	 // instrukcja przypisania := powoduje, że zmienna s dostaje wartość sumy wartości zmiennych a i b
              writeln('Suma: ', s);
          end;
          '-' : begin
              write('Podaj pierwsza liczbe: '); readln(a);
              write('Podaj druga liczbe: '); readln(b);
              s := a - b;
              writeln('Roznica: ', s);
          end;
          '*' : begin
              write('Podaj pierwsza liczbe: '); readln(a);
              write('Podaj druga liczbe: '); readln(b);
              s := a * b;
              writeln('Iloczyn: ', s);
          end;
          'div' : begin
              write('Podaj pierwsza liczbe: '); readln(a);
              write('Podaj druga liczbe: '); readln(b);
              if (b = 0) then begin
              	 writeln('Nie dzielimy przez zero!');
	      end else begin
              	   s := a div b;
              	   writeln('Iloraz calkowity: ', s);
              end;
          end;
          'mod' : begin
              write('Podaj pierwsza liczbe: '); readln(a);
              write('Podaj druga liczbe: '); readln(b);
              if (b = 0) then begin
              	 writeln('Nie dzielimy przez zero!');
	      end else begin
              	   s := a mod b;
              	   writeln('Modulo: ', s);
              end;
          end;
          '/' : begin
              write('Podaj pierwsza liczbe: '); readln(x);
              write('Podaj druga liczbe: '); readln(y);
              if (y = 0.0) then begin
              	 writeln('Nie dzielimy przez zero!');
              end else begin
              	  t := x / y;
              	  writeln('Iloraz: ', t:2:4);   // liczba rzeczywista podanie podana w minimum 2 znakakach z dokładnością do 4 miejsc po przecinku - pominięcie (czyli napisanie samego "t") spowoduje wyświetlenie zmiennej w notacji naukowej (np. 21.37 = 2.137E+1)
              end;
          end;
          else writeln('Zla komenda!'); 	// else w bloku case zadziała kiedy żaden z powższych przypadków nie zostaje spełniony
     end;
end.
