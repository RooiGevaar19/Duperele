f <- function(n) { return(n*n) }
g <- function(n) { return(sin(n)) }

DirichletConvolve <- function(f, g, k) {
    sum = 0
    for (i in (1:k)[!k%%1:k]) { 
        sum = sum + f(i)*g(k/i)
    }
    sum
}

print(DirichletConvolve(f, g, 4))
