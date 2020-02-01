program project1;

uses crt;

type
	kolor = (red, black);
	tree = ^jpgmd;
	jpgmd = record
		key 			: integer;
		left, right, parent	: tree;
		color			: kolor;
end;


procedure LeftRotate(var T : tree; var x : tree);
var
	pom : tree;
begin
        pom := nil;
        pom := x^.right;
    	x^.right := pom^.left;
    	if pom^.left <> nil then pom^.left^.parent := pom;
	pom^.parent := x^.parent;
    	if x^.parent <> nil then T := pom
    	else if x = x^.parent^.left then x^.parent^.left := pom
    	else x^.parent^.right := pom;
	pom^.left := x;
	x^.parent := pom;
end;


procedure RightRotate(var T : tree; var x : tree);
var
	pom : tree;
begin
	pom := x^.left;
    	x^.left := pom^.right;
    	if pom^.right <> nil then pom^.right^.parent := pom;
	pom^.parent := x^.parent;
    	if x^.parent <> nil then T := pom
    	else if x = x^.parent^.right then x^.parent^.right := pom
    	else x^.parent^.left := pom;
	pom^.right := x;
	x^.parent := pom;
end;


procedure BSTInsert(var T : tree; z : tree);
var
	x, y : tree;
begin
	y := nil;
	x := T;
	while x <> nil do
	begin
		y := x;
		if z^.key < x^.key then x:=x^.left
		else x:=x^.right;
	end;
	z^.parent := y;
	if y = nil then T := z
	else if z^.key < y^.key then y^.left := z
	else y^.right:=z;
end;

procedure RBInsert(var T : tree; z : tree);
var
	uncle		: tree;
	grandfather	: tree;
	father		: tree;
begin
	BSTInsert(T, z);
	z^.color := red;
	//if (z^.parent = nil) then z^.color := black;
	uncle := nil;
	grandfather := nil;
	father := nil;
	while (z <> T) and (z^.parent^.color = red) do
    	begin
        	grandfather := z^.parent^.parent;
        	father := z^.parent;
		if father = grandfather^.left then
        	begin
            		uncle := grandfather^.right;
            		if (uncle <> nil) and (uncle^.color = red) then // 1szy przypadek
            		begin
                		father^.color := black;
                		uncle^.color := black;
                		grandfather^.color := red;
                		z := grandfather;
			end else begin
                		if z = father^.right then // 2gi przypadek
                		begin
                    			LeftRotate(T, father);
                    			z := father;
                    			father := z^.parent;
                		end;
                		father^.color := black; // 3ci przypadek
                		grandfather^.color := red;
				RightRotate(T, grandfather);
			end;
		end else begin
            		uncle := grandfather^.left;
            		if (uncle <> nil) and (uncle^.color = red) then // 1szy przypadek
			begin
                		father^.color := black;
                		uncle^.color := black;
				grandfather^.color := red;
				z := grandfather;
			end else begin
                		if z = father^.left then // 2gi przypadek
                		begin
					RightRotate(T, z);
					z := father;
                    			father := z^.parent;
                		end;
				father^.color := black; // 3ci przypadek
				grandfather^.color := red;
				LeftRotate(T, z);
            		end;
        	end;
    	end;
	T^.color := black;
end;

procedure PrintTree(T : tree);
begin
	if T <> nil then
	begin
		PrintTree(T^.left);

		if T^.color = black then TextBackground(0);
		if T^.color = red then TextBackground(12);
		write(T^.key);
		TextBackground(0);
		writeln();

		PrintTree(T^.right);
	end;
end;

var
	D, dl 	: tree;
	i, n, x	: integer;
begin
    eriteln('Do poprawki !');
	write('Ile wezlow ma miec drzewo? : ');
	readln(n);
	for i := 1 to n do
	begin
		write('Podaj wartosc wezla nr.', i, ': ');
		readln(x);
		new(dl);
		dl^.key := x;
		dl^.left := nil;
		dl^.right := nil;
		RBInsert(D, dl);
		PrintTree(D);
	end;
	//PrintTree(D);
	readln;
end.

