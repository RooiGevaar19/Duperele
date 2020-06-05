# Zadanie 1

n = 11
Mu = 42436.97 
Si = 2189.87
lim = 45000
#alt = "less"
alpha = 0.03

val1 <- ((Mu-lim)*sqrt(n-1))/Si
val2 <- qt(alpha, n-1) # dla hipotezy alternatywnej <=
val1
val2
val1 <= -val2

# t.test(x = wm, y = ws, alternative = c("two.sided", "less", "greater"), var.equal = TRUE)
#t.test(x = wm, y = ws, alternative = c("less"), var.equal = TRUE, conf.level = 1-alfa_3)

# Zadanie 2

n = 20
Si = 0.84
#alt = "greater"
alpha = 0.07
lim = 0.45

val1 <- (n*Si)/lim
val2 <- qchisq(alpha, n-1)
val1
val2
val1 >= val2