source data3.m

function res = cramerSolve (A, b) 
    [Rows, Cols] = size(A);
    Cols2 = size(b);
    if (Cols != Cols2)
        error("Wektor po prawej nie ma tego samego rozmiaru co macierz po lewej.");
    endif
    Det = det(A);
    if (Det == 0)
        error("Układ nie jest układem Cramera");
    endif
    res = [];
    for i = (1:Cols)
        pom = A;
        pom(:,i) = b;
        x = det(pom);
        res = [res; x/Det];
    endfor
endfunction

function attemptCramer(A, b)
    try
        res = cramerSolve(A, b);
        printf("%8.4f  ", res);
    catch
        printf("%s ", lasterror.message);
    end_try_catch
endfunction

printf("a) "); attemptCramer(A, a); printf("\n");
printf("b) "); attemptCramer(B, b); printf("\n");
printf("c) "); attemptCramer(C, c); printf("\n");
printf("d) "); attemptCramer(D, d); printf("\n");