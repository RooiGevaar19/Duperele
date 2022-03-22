source data3.m


function attemptSolve(A, b)
    try
        warning('off', 'Octave:singular-matrix');
        res = inv(A) * b';
        if (isinf(res) || isnan(res))
            error("Brak jednoznacznego rozwiązania")
        endif
        warning('on', 'Octave:singular-matrix');
        printf("%8.4f  ", res);

    catch
        printf("%s ", lasterror.message);
    end_try_catch
endfunction

printf("a) "); attemptSolve(A, a); printf("\n");
printf("b) "); attemptSolve(B, b); printf("\n");
printf("c) "); attemptSolve(C, c); printf("\n");
printf("d) "); attemptSolve(D, d); printf("\n");