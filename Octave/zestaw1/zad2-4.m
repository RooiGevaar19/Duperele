A = [1  4;
     2 -1];
B = [1 4 10;
     7 8 18;
     3 7 17];
C = [2 3;
     4 6];
D = [ 2 3 4 1;
      5 1 0 0;
     -1 5 8 2];
E = [2  -1 -2 4;
     4  -2  1 7;
     2 -10  8 2];
F = [2 1 1 1;
     1 3 1 1;
     1 1 4 1;
     1 1 1 5;
     1 2 3 4;
     1 1 1 1];
G = [ 1 0 -1  2  0;
      1 1  0 -1 -1;
     -3 0  2  0  1];

printf("rank(A) = %i\n", rank(A));
printf("rank(B) = %i\n", rank(B));
printf("rank(C) = %i\n", rank(C));
printf("rank(D) = %i\n", rank(D));
printf("rank(E) = %i\n", rank(E));
printf("rank(F) = %i\n", rank(F));
printf("rank(G) = %i\n", rank(G));