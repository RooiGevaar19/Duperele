A = [-3  1  5;
      6 -2 15];
A2 = A';
B = [1 2  3; 
     2 5  7; 
     3 7 10];
C = [1 1 0;
     1 0 1
     2 1 1];
D = [1 1 0 0;
     1 0 1 0;
     0 1 1 0;
     0 0 0 1];

function str = check(A)
    [Rows, Cols] = size(A');
    if (Rows == Cols) 
        #A'
        #det(A')
        if (det(A') == 0)
            str = "Wektory są liniowo zależne";
        else
            str = "Wektory są liniowo niezależne";
        endif
    else
        if (Rows < Cols)
            str = "Wektory są liniowo zależne";
        else
            #res = inv(A') * (zeros(Rows))';
            res = (A') \ (zeros(Rows,1));
            if (isinf(res) || isnan(res))
                str = "Wektory są liniowo zależne";
                return
            endif
            if (res == zeros(1,Rows))
                str = "Wektory są liniowo niezależne";
            else
                str = "Wektory są liniowo zależne";
            endif
        endif
    endif
endfunction

printf("a) %s\n", check(A));
printf("b) %s\n", check(B));
printf("c) %s\n", check(C));
printf("d) %s\n", check(D));