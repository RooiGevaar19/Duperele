# Zadanie 1

mu <- 31576.29
si <- 2884.52
n  <- 27
alpha <- 1 - 0.85

L = mu - qt(1-alpha/2, df=n-1)*(si/sqrt(n-1))
U = mu + qt(1-alpha/2, df=n-1)*(si/sqrt(n-1))

cat("Zadanie 1", end='\n')
cat(c("Przedział ufności: (",L,'; ',U,')' ),sep='',end='\n')

# Zadanie 2

n     <- 12
si2   <- 0.37
alpha <- 1 - 0.89

L = (n*si2)/qchisq(alpha/2,df=n-1)
U = (n*si2)/qchisq(1-alpha/2,df=n-1)

cat("Zadanie 2", end='\n')
cat(c("Przedział ufności: (",U,'; ',L,')' ),sep='',end='\n')
