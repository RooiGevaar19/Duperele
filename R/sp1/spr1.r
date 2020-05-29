mu = 15.02
sigma = 2.76

zadanie1 <- function(mu, sigma) {
  cat("Zadanie 1:\n")
  a = 1 - pnorm(q = 15.98, mean = mu, sd = sigma)
  b = pnorm(q = 14.33, mean = mu, sd = sigma)
  c = pnorm(q = 17.78, mean = mu, sd = sigma) - pnorm(q = 12.26, mean = mu, sd = sigma)
  cat(c("Przykład A: ", a, "\n"))
  cat(c("Przykład B: ", b, "\n"))
  cat(c("Przykład C: ", c, "\n"))
  
}

zadanie2 <- function(mu, sigma, n) {
  cat("Zadanie 2:\n")
  a = 1 - pnorm(q = 15.98, mean = mu, sd = sigma/n)
  b = pnorm(q = 14.33, mean = mu, sd = sigma/n)
  c = pnorm(q = 17.78, mean = mu, sd = sigma/n) - pnorm(q = 12.26, mean = mu, sd = sigma/n)
  cat(c("Przykład A: ", a, "\n"))
  cat(c("Przykład B: ", b, "\n"))
  cat(c("Przykład C: ", c, "\n"))
}

zadanie1(mu, sigma)
zadanie2(mu, sigma, 23)
  