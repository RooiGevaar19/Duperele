unit Real128Unit;

interface

{$IFDEF CPU64}
type RealType = Extended;
type IntType = Int64;
{$ENDIF}

{$IFDEF CPU32}
type RealType = Extended;
type IntType = LongInt;
{$ENDIF}

const Base = 10;

type Decimal128 = record
    sign     : ShortInt;
    fraction : RealType;
    factor   : IntType;
end;

operator := (x : LongInt) res : Decimal128;
operator := (x : Extended) res : Decimal128;

operator := (x : Decimal128) res : LongInt;
operator := (x : Decimal128) res : Extended;

operator + (x : Decimal128; y : Decimal128) res : Decimal128;
operator - (x : Decimal128; y : Decimal128) res : Decimal128;
operator * (x : Decimal128; y : Decimal128) res : Decimal128;
operator / (x : Decimal128; y : Decimal128) res : Decimal128;

operator inc (x : Decimal128) res : Decimal128;
operator dec (x : Decimal128) res : Decimal128;
//operator trunc (x : Decimal128) res : Decimal128;
//operator round (x : Decimal128) res : Decimal128;
//operator ln (x : Decimal128) res : Decimal128;
//operator exp (x : Decimal128) res : Decimal128;

procedure print(x : Decimal128);
procedure printBased(x : Decimal128);

implementation

//uses Math;
uses SysUtils;

// ====== USEFUL THINGS

function power(f : IntType) : RealType;
var
    Result : RealType;
    i      : IntType;
begin
    Result := 1;
    if (f <> 0) then begin 
        Result := 1;
        for i := 1 to abs(f) do Result := Result * Base;
        if (f < 0) then Result := 1.0 / Result;
    end;
    power := Result;
end;

procedure normalize(var x : Decimal128);
begin
    writeln(x.fraction : 2 : 5);
    writeln(x.sign);
    if (x.fraction < 0) then
    begin
        x.sign := x.sign * -1;
        x.fraction := abs(x.fraction);
    end;
    while (x.fraction < 1) do
    begin
        x.fraction := x.fraction * Base;
        Dec(x.factor);
    end;
    while (x.fraction >= Base) do
    begin
        x.fraction := x.fraction / Base;
        Inc(x.factor);
    end;
end;

procedure transformToFactor(var x : Decimal128; newbase : IntType);
begin
    while (x.factor > newbase) do
    begin
        x.fraction := x.fraction * Base;
        Dec(x.factor);
    end;
    while (x.factor < newbase) do
    begin
        x.fraction := x.fraction / Base;
        Inc(x.factor);
    end;
end;

// ====== IMPLEMENTATION

operator := (x : LongInt) res : Decimal128;
begin
    res.sign := x div abs(x); 
    res.factor := trunc(ln(abs(x))/ln(Base));
    res.fraction := abs(x / power(res.factor));
end;

operator := (x : Extended) res : Decimal128;
begin
    res.sign := trunc(x/abs(x));
    res.factor := trunc(ln(abs(x))/ln(Base));
    res.fraction := abs(x / power(res.factor));
end;

operator := (x : Decimal128) res : LongInt;
begin
    res := x.sign * trunc(x.fraction) * trunc(power(x.factor));
end;

operator := (x : Decimal128) res : Extended;
begin
    res := x.sign * x.fraction * power(x.factor);
end;

operator + (x : Decimal128; y : Decimal128) res : Decimal128;
begin
    transformToFactor(x, y.factor);
    res.factor := x.factor;
    res.fraction := x.fraction * x.sign + y.fraction * y.sign;
    res.sign := 1;
    normalize(res);
end;

operator - (x : Decimal128; y : Decimal128) res : Decimal128;
begin
    transformToFactor(x, y.factor);
    res.factor := x.factor;
    res.fraction := x.fraction * x.sign - y.fraction * y.sign;
    res.sign := 1;
    normalize(res);
end;

operator * (x : Decimal128; y : Decimal128) res : Decimal128;
begin
    res.sign     := x.sign     * y.sign;
    res.fraction := x.fraction * y.fraction;
    res.factor   := x.factor   + y.factor;  
    normalize(res);
end;

operator / (x : Decimal128; y : Decimal128) res : Decimal128;
begin
    res.sign     := x.sign     * y.sign;
    res.fraction := x.fraction / y.fraction;
    res.factor   := x.factor   - y.factor;
    normalize(res); 
end;

operator inc (x : Decimal128) res : Decimal128;
begin
    res := x + 1.0;
end;
operator dec (x : Decimal128) res : Decimal128;
begin
    res := x + 1.0;
end;

//operator trunc (x : Decimal128) res : Decimal128;
//begin
//    transformToFactor(x, 0);
//    res.sign := x.sign;
//    res.factor := x.factor;
//    res.fraction := trunc(x.fraction);
//    normalize(res);
//end;
//
//operator round (x : Decimal128) res : Decimal128;
//begin
//    transformToFactor(x, 0);
//    res.sign := x.sign;
//    res.factor := x.factor;
//    res.fraction := round(x.fraction);
//    normalize(res);
//end;

//operator ln (x : Decimal128) res : Decimal128;
//begin
//    res.sign     := x.sign     * y.sign;
//    res.fraction := x.fraction * y.fraction;
//    res.factor   := x.factor   + y.factor;  
//    normalize(res);
//end;
//
//operator exp (x : Decimal128) res : Decimal128;
//begin
//    if (x < 1) then res.sign := -1 else res.sign := 1; 
//    res.fraction := x.fraction * y.fraction;
//    res.factor   := x.factor   + y.factor;  
//    normalize(res);
//end;

procedure printBased(x : Decimal128);
begin
    if (abs(x.factor) < 10) then
    begin
        writeln(FormatFloat('0.###############', x.sign * x.fraction * power(x.factor)));
    end else begin
        if (x.fraction = 1) 
            then writeln(x.sign*Base, '^', x.factor)
                else writeln(FormatFloat('0.###############', x.sign*x.fraction), '*', Base, '^', x.factor);
    end
end;

procedure print(x : Decimal128);
begin
    writeln(x.fraction, 'E+');
end;

end.