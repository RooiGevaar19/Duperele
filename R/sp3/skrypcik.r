# Zadanie 1
mu <- 3.18
var1 <- 10.35

pchisq(q = 30.49/var1, df=3)

# Zadanie 2
n <- 6
var2 <- 0.37
test <- 0.45

1 - pchisq(q = (n*test)/var2, df=n-1)