A1 = [2 1;
     1 1];
A2 = [2 10 -1 -1;
      1  6  0 -1];
B1 = [ 3  2;
      -2 -1];
B2 = [-1 2;
      -1 1];
C1 = [1 2 3;
      2 3 4;
      3 4 1];
C2 = [6 9 8;
      0 1 6];

function str = MatrixStr(m)
    str = "";
    rows = rows(m);
    cols = columns(m);
    str = strcat(str, "[");
    for i = 1:rows
        for j = 1:cols
            str = strcat(str, sprintf(" %6.2f ", m(i,j)));
        endfor
        str = strcat(str, ";");
    endfor
    str = strcat(str, "\b]");
endfunction

function leftSolve(A, b)
    try
        warning('off', 'Octave:singular-matrix');
        res = inv(A) * b;
        if (isinf(res) || isnan(res))
            error("Brak jednoznacznego rozwiązania")
        endif
        warning('on', 'Octave:singular-matrix');
        #round(res .* 100) ./ 100;
        #output_precision(4)
        #printf("%8.4f  ", res);
        #printf("%s  ", mat2str(res));
        printf("%s  ", MatrixStr(res));

    catch
        printf("%s ", lasterror.message);
    end_try_catch
endfunction

function rightSolve(A, b)
    try
        warning('off', 'Octave:singular-matrix');
        res = b * inv(A);
        if (isinf(res) || isnan(res))
            error("Brak jednoznacznego rozwiązania")
        endif
        warning('on', 'Octave:singular-matrix');
        #printf("%8.4f  ", res);
        #printf("%s  ", mat2str(res));
        printf("%s  ", MatrixStr(res));
    catch
        printf("%s ", lasterror.message);
    end_try_catch
endfunction

printf("a) "); leftSolve(A1, A2); printf("\n");
printf("b) "); rightSolve(B1, B2); printf("\n");
printf("c) "); rightSolve(C1, C2); printf("\n");