program cputest;

{$mode objfpc}

{$IFDEF MSWINDOWS}
uses Classes;
{$ELSE}
uses initc, ctypes, cthreads, Classes;

function sysconf(i:cint):clong;cdecl;external name 'sysconf';
{$ENDIF}


// ========== PARAMETERS
const mask       = 15;
const factor     = 20000000;
type  NumberType = Extended;


// ========== Thread Declaration
type
    TMyThread = class(TThread)
    public
        Value : NumberType;
        rangeA : Integer; // left bound of range
        rangeB : Integer; // right bound of range
        procedure Execute(); override;
end;

var
    T : array of NumberType;
    i : Integer;
 
function findSumRange(T : array of NumberType; rangeA, rangeB : Integer) : NumberType;
var
    s : NumberType;
    i : Integer;
begin
    s := 0.0;
    for i := rangeA to rangeB do s := s + T[i];
    findSumRange := s;
end;

procedure TMyThread.Execute;
begin
    //WriteLn('I am thread with ID ',ThreadID);
    //writeln(rangeA, ' ', rangeB);
    Value := findSumRange(T, rangeA, rangeB);
end;


function getCPUs() : Integer;
begin
    {$IFDEF MSWINDOWS}
    getCPUs := GetCPUCount();
    {$ELSE}
    getCPUs := sysconf(83); 
    {$ENDIF}
    //getCPUs := 4;
end;

function findSumAsync(T : array of NumberType) : NumberType;
var
    s, i : NumberType;
begin
    s := 0.0;
    for i in T do s := s + i;
    findSumAsync := s;
end;

function findSumSync(T : array of NumberType) : NumberType;
var
    l, m, n : Integer;
    i       : Integer;
    s       : NumberType;
    threads : array of TMyThread;
    sums    : array of NumberType;
begin
    m := getCPUs();
    n := Length(T);
    l := n div m;
    SetLength(threads, m);
    SetLength(sums, m);
    for i := 0 to m-1 do
    begin
        threads[i] := TMyThread.Create(true); 
        threads[i].FreeOnTerminate := true;
        threads[i].rangeA := l*i;
        if i = m-1 
            then threads[i].rangeB := n-1 
            else threads[i].rangeB := l*(i+1)-1;
    end;
    for i := 0 to m-1 do
    begin
        threads[i].Start;
    end;
    for i := 0 to m-1 do
    begin
        threads[i].WaitFor;
    end;
    for i := 0 to m-1 do
    begin
        //writeln(i,' ',threads[i].Value:2:6);
        sums[i] := threads[i].Value;
    end;
    s := findSumAsync(sums);
    SetLength(threads, 0);
    SetLength(sums, 0);
    findSumSync := s;
end;

begin
    randomize;
    writeln('Count of CPU cores: ', getCPUs);

    SetLength(T, getCPUs * factor);
    for i := 0 to Length(T)-1 do
        T[i] := random;
    writeln('Sum (async): ', findSumAsync(T):2:mask);
    writeln('Sum (sync) : ', findSumSync(T):2:mask);
    SetLength(T, 0);
end.