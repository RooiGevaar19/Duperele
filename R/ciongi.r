f <- function(n) {
  (-1)^n * (1/n)
}

plot(f(1:50), 
     pch=16,
     ylab="A(n)",
     xlab="n",
     col="red")
abline(h=0, col="orange")
abline(h=0.1, col="yellow")
abline(h=-0.1, col="yellow")