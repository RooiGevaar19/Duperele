# zadanie 1
zadanie1 <- function() {
  alpha = 4.56
  lambda = 1.34
  
  limit = 10
  
  curve(dgamma(x,shape=alpha,scale=lambda), col="red", xlim=c(0,20))
  cat(c("P =", 1-pgamma(limit, shape=alpha, scale = lambda))) 
}

zadanie1()

zadanie2 <- function(n) {
  alpha = 74*sqrt(n)
  lambda = 0.81
  limit = 9
    
  alpha/lambda - limit*n
}
  
zadanie2(10000)