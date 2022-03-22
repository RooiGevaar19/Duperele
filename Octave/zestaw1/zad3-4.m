A = [1  3;
     3 -1;
     1 -7];
a = [5 4 -1];

B = [1 -2 5;
     2 -1 1];
b = [0 3];

C = [ 1 2 -1 -1;
     -1 3  0  1;
      0 2 -1 -3;
     -2 2  2  5];
c = [1 -3 2 -6];

D = [-3 1 1;
     -2 2 1;
      1 1 1;
     -3 1 2];
d = [-1 1 3 1];

E = [1 1  2 -3;
     3 2 -6  9;
     4 3 -4  6];
e = [-1 4 3];

F = [1  1 2;
     2 -1 2;
     4  1 4];
f = [-1 -4 -2];

function checkCase(A, b) 
    A_ext = [A b'];
    var_N = columns(A);
    if (rank(A) != rank(A_ext))
        printf("Brak rozwiązania.\n");
    else
        if (rank(A_ext) == var_N)
            printf("Rozwiązanie jest jednoznaczne.\n");
        else 
            n = var_N-rank(A_ext);
            if (n == 1)
                printf("Rozwiązanie zależy od 1 parametru.\n");
            else
                printf("Rozwiązanie zależy od %i parametrów.\n", n);
            endif
        endif
    endif
endfunction

printf("a) "); checkCase(A, a);
printf("b) "); checkCase(B, b);
printf("c) "); checkCase(C, c);
printf("d) "); checkCase(D, d);
printf("e) "); checkCase(E, e);
printf("f) "); checkCase(F, f);