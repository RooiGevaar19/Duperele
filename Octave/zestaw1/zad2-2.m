source data2.m

try 
    printf("inv(A) = "); 
    Ai = inv(A); 
    if(isinf(Ai))
        error()
    endif
    Ai
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(B) = "); 
    Bi = inv(B); 
    if(isinf(Bi))
        error()
    endif
    Bi
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(C) = "); 
    Ci = inv(C); 
    if(isinf(Ci))
        error()
    endif
    Ci
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(D) = "); 
    Di = inv(D); 
    if(isinf(Di))
        error()
    endif
    Di
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(E) = "); 
    Ei = inv(E); 
    if(isinf(Ei))
        error()
    endif
    Ei
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(F) = "); 
    Fi = inv(F); 
    if(isinf(Fi))
        error()
    endif
    Fi
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(H) = "); 
    Hi = inv(H); 
    if(isinf(Hi))
        error()
    endif
    Hi
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch

try 
    printf("inv(M) = "); 
    Mi = inv(M); 
    if(isinf(Mi))
        error()
    endif
    Mi
catch 
    printf("Brak macierzy odwrotnej!\n");
end_try_catch
