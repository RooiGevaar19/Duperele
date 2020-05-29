# Zadanie 1
eps <- 0.5
n1 <- 7

1-(pt(eps*sqrt(n1-1),df=n1-1) - pt(-eps*sqrt(n1-1),df=n1-1))

# Zadanie 2
n2 <- 11
mu1 <- 53
mu2 <- 57
si2 <- 8

1-(pt((mu2-mu1)*sqrt(n2-1)/si2,df=n2-1))