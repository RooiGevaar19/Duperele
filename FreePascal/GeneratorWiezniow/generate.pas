 //Author: Paul Lipkowski
// 10/25/2016

program generate;

const 
	count  = 2048; // ile wygeneruje rekordow
	nbase  = 128;   // ile jest imion w bazie
	sbase  = 256;   // ile jest nazwisk w bazie

var
	names     : array[1..nbase] of string;
	surnames  : array[1..sbase] of string;
	fnames    : text;
	fsurnames : text;
	foutput   : text;
	y,m,d     : integer;
	s         : array[1..11] of integer;
	i,j       : integer; // iteratory
	a,b       : integer;
	height    : integer;
	weight    : integer;

begin
	// czytanie imion
	assign(fnames, 'name.txt');	
	reset(fnames);
	for i := 1 to nbase do
	begin
		readln(fnames, names[i]);
	end;	
	close(fnames);
	
	// czytanie nazwisk
	assign(fsurnames, 'agtername.txt');	
	reset(fsurnames);
	for i := 1 to sbase do
	begin
		readln(fsurnames, surnames[i]);
	end;	
	close(fsurnames);

	// zapis do nowej bazy danych
	randomize();	
	assign(foutput, 'newbase.txt');
	rewrite(foutput);
	for i := 1 to count do
	begin
		// losowanie imienia i nazwiska		
		a := random(nbase-1+1)+1;
		b := random(sbase-1+1)+1;
		if names[a, Length(names[a])] = 'a' then // rozwazanie przypadkow kobiet z naziwskami -ska, -cka etc.
		begin
			if (surnames[b, Length(surnames[b])] = 'i') 
			and (surnames[b, Length(surnames[b])-1] = 'k')
			then 
			begin
				surnames[b, Length(surnames[b])] := 'a';
			end;
		end;		
		write(foutput, names[a],''#9'',surnames[b],''#9'');
		// powrot do dawnych ustawien bazy
		if names[a, Length(names[a])] = 'a' then
		begin
			if (surnames[b, Length(surnames[b])] = 'a') 
			and (surnames[b, Length(surnames[b])-1] = 'k')
			then 
			begin
				surnames[b, Length(surnames[b])] := 'i';
			end;
		end;

		// generowanie poprawnego PESELu
		// generowanie daty urodzenia

		y := random(83-45+1)+45; //domyslnie urodzeni w latach 1945-1983
		m := random(12-1+1)+1;
		d := random(28-1+1)+1;   //dla uproszczenia wszystkie miesiace maja 28 dni
		s[1] := y div 10;
		s[2] := y mod 10;
		s[3] := m div 10;
		s[4] := m mod 10;
		s[5] := d div 10;
		s[6] := d mod 10;
			
		write(foutput, y);		

		if m in [1..9] then 
		begin
			write(foutput,'0',m);
		end
		else
		begin
			write(foutput, m);
		end;

		if d in [1..9] then 
		begin
			write(foutput,'0',d);
		end
		else
		begin
			write(foutput, d);
		end;

		// nr serii		
		for j := 7 to 9 do
		begin
			s[j] := random(10);
			write(foutput, s[j]);	
		end;

		// cyfra sugerujaca plec
		if names[a, Length(names[a])] = 'a' then 
		begin
			s[10] := random(5);
			s[10] := 2*s[10];
		end
		else
		begin
			s[10] := random(5);
			s[10] := 2*s[10]+1;
		end;
		write(foutput, s[10]);	

		// cyfra kontrolna		
		s[11] := s[1] + 3*s[2] + 7*s[3] + 9*s[4] + s[5] + 3*s[6] + 7*s[7] + 9*s[8] + s[9] + 3*s[10];
		s[11] := s[11] mod 10;
		s[11] := 10 - s[11];
		if s[11] = 10 then s[11] := 0;
		write(foutput, s[11]);

		write(foutput,''#9''); // tabulator

		// wzrost i waga
		height := random(195-165+1)+165;
		weight := random(120-50+1)+50;
		write(foutput, height,''#9'',weight);

		write(foutput,''#9''); // tabulator

		// data zatrzymania kradzieja
		y := random(2015-2000+1)+2000; //domyslnie zatrzymani w latach 2000-2015
		m := random(12-1+1)+1;
		d := random(28-1+1)+1;   //dla uproszczenia wszystkie miesiace maja 28 dni
			
		write(foutput, y,'-');		

		if m in [1..9] then 
		begin
			write(foutput,'0',m,'-');
		end
		else
		begin
			write(foutput, m,'-');
		end;

		if d in [1..9] then 
		begin
			write(foutput,'0',d);
		end
		else
		begin
			write(foutput, d);
		end;

		write(foutput,''#9''); // tabulator

		// dlugosc wyroku w latach (120 oznacza dozywocie)
		y := random(10);
		case y of
			1 : write(foutput, 120);
			2 : write(foutput, 25);
			3 : write(foutput, 25);
			else begin 
				y := random(15-1+1)+1;
				write(foutput, y);
			end;
		end;

		//koniec rekordu
		writeln(foutput, '');
	end;
	close(foutput);
	
	writeln('Generated.');	
	readln();
end.

