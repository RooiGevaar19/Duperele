A = [ 1 3 2;
      2 4 4;
     -1 1 2];

B = [1 1 1];

if (det(A) != 0)
    printf("Wektory tworzą bazę w przestrzeni R^3.\n");
    res = A' \ B';
    printf("Współrzędne wektora %s w tej bazie: %s\n", mat2str(B), mat2str(res'));
else
    printf("Wektory nie tworzą bazy w przestrzeni R^3.\n");
endif