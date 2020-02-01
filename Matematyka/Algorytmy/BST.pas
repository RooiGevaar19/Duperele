program bst;

uses crt;

type
	Tree = ^jpgmd;
	jpgmd = record
		key 	    : integer;
		left, right	: tree;

end;

procedure BSTInsert(var T : Tree; z : Tree);
var
	x, y : Tree;
begin
	y := nil;
	x := T;
	while x <> nil do
	begin
		y := x;
		if z^.key <= x^.key then x:=x^.left
		else x:=x^.right;
	end;
	if y = nil then T := z
	else if z^.key < y^.key then y^.left := z
	else y^.right:=z;
end;

function createNode(x : Integer) : Tree;
var
    dl : Tree;
begin
    new(dl);
    dl^.key := x;
    dl^.left := nil;
    dl^.right := nil;
    createNode := dl;
end;

procedure PrintInOrder(T : Tree);
begin
	if T <> nil then
	begin
		PrintInOrder(T^.left);
		writeln(T^.key);
		PrintInOrder(T^.right);
	end;
end;

var
    tr : Tree;
    i  : Integer;

begin
    writeln('do poprawki!');
    randomize;
    for i in [1..20] do
        BSTInsert(tr, createNode(random(20)));
    PrintInOrder(tr);
end.