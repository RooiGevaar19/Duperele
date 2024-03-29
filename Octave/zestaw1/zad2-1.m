A = [5 -3;
     7  3];
B = [ 9 6;
     12 8];
C = [2 1 3;
     5 3 2;
     1 4 3];
D = [3 2 -4;
     4 1 -2;
     5 2 -3];
E = [1 1 1;
     1 2 3;
     1 3 6];
F = ones(4, 4) - 2*eye(4);
G = ones(4, 4) - eye(4);
H = [1 3 1  0;
     1 4 2 -1;
     1 0 1  2;
     0 3 3  1];
L = [1 0 3  4 5;
     2 3 7 10 3;
     3 0 0  0 2;
     2 0 7  7 2;
     1 0 5  3 1];

printf('det(A) = %g\n', det(A));
printf('det(B) = %g\n', det(B));
printf('det(C) = %g\n', det(C));
printf('det(D) = %g\n', det(D));
printf('det(E) = %g\n', det(E));
printf('det(F) = %g\n', det(F));
printf('det(G) = %g\n', det(G));
printf('det(H) = %g\n', det(H));
printf('det(L) = %g\n', det(L));
