source data1.m

W = [2, -1, 5];
V = [1, 1, 0, -3];

# polyval(W, A)
try
    printf(' a) '); polyvalm(W, A)
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' b) '); polyvalm(V, N)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch

try
    printf(' c) '); polyvalm(W, C)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch

try
    printf(' d) '); polyvalm(V, M)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch

try
    printf(' e) '); polyvalm(V, H)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch

try
    printf(' f) '); polyvalm(W, P)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch

try
    printf(' g) '); polyvalm(V, L)
catch 
    printf("Wielomian nie istnieje!\n");
end_try_catch


