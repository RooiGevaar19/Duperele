program warunki;

const							// blok na wartości stałe - ich nie można zmienić w programie
     pelnoletnosc = 18;

var  							// blok na zmienne
   imie : String;					// zmienna typu String - typ łańcucha znaków, typ tekstowy
   wiek : Integer;					// zmienna typu Integer - liczba całkowita

begin
     writeln('Jak sie nazywasz?');			// writeln sprawia, że kolejny tekst wygeneruje się od nowej linijki
     readln(imie);
     write('Ile lasz lat?');		   	   	// write sprawia, że kolejny tekst wygeneruje się tuż obok
     read(wiek);     			   	 	// analogicznie read i readln

     writeln();				   		// writeln() bez argumentu tekstowego powoduje po prostu przejście do nowej linii
     writeln('Witaj, nazywasz sie ', wiek, '.');	// poniższy writeln ma 3 argumenty tekstowe: dwa dosłowne łańcuchy znaków wieńczone apostrofami i jedną zmienną, która wypisze się na ekranie

     if (imie = 'Pawel') then 	     	   		// instrukcja "if" - jezeli warunek jest spełniony, to nastepna komenda/blok komend się wykona.
     begin
     	  writeln('Oh, nazywasz sie tak samo jak ja :)');
     end;

     if (wiek >= pelnoletnosc) then 	     	    	 // instrukcja "if-else" - jeżeli warunek nie jest spełniony, to wykona się inny blok komend niż wtedy, kiedy warunek zostanie spełniony
     begin
     	  writeln('Jestes pelnoletni(a) i masz ', wiek, 'lat.');
          writeln('Dziekuje za informacje.');
     end else begin
     	 writeln('Brakuje ci ', pelnoletnosc-wiek, ' lat do pelnoletnosci.');  // wyrażenie pelnoletność-wiek to nic innego jak różnica między dwoma liczbami, ta różnica zostanie wypisana na ekranie.
         writeln('Dziekuje za informacje.');
     end;

     if (wiek < 0) then writeln('BTW. podales/as ujemny wiek. ;)');	       // jeżeli w warunku if znajduje się jedna komenda, to można pominąć blok begin-end

     readln();	   		      		 	// instrukcja readln(); prosi o wciśnięcie klawisza ENTER - w systemie Windows może być potrzebna, aby aplikacja nie wyłączyła się przedwcześnie

end.
