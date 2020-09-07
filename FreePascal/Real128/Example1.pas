program Example;

uses Real128Unit;

var
    x, y : Decimal128;

begin
    x := -42;
    y := -126.5;
    x := x + y;
    printBased(x);
    x := 2147483647;
    printBased(x);
    printBased(214748364745.0);
    //print(x);
end.