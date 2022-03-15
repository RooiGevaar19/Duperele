source data1.m


try
    printf(' a) '); X = C' + 2*M
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' b) '); X = (C - 2*M)/2
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' c) '); X = (R-N)/(-3)
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' d) '); X = G' - 2*D
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' e) '); X = L' - M; X = X / 2
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' f) '); X = C - H; X = X / 3
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' g) '); X = B - A - P - H
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' h) '); X = E' - 2*(H-F); error() #X = X / 0
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' i) '); X = 5*P - P + L
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' j) '); X = H^3 + D + E; X = X/2
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' k) '); X = K + M - L + K
catch 
    printf("Brak rozwiązania!\n");
end_try_catch

try
    printf(' l) '); X = 8*H - G
catch 
    printf("Brak rozwiązania!\n");
end_try_catch