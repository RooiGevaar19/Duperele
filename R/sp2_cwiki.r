# Paweł Lipkowski, 238181
# Sprawdzian 2

# ==============================
# Technicznie

arrayToStr <- function(array) {
	toString(cat("[", sep="")+cat(array, "\b\b]", sep=", ")) 
}

write <- function(content, separator="") {
	cat(content, sep=separator); 
}

writeln <- function(content, separator="") {
	cat(content, "\n", sep=separator); 
}

saveToPNG <- function(filename, thing, thing2=NULL) {
    png(paste(filename, ".png", sep=""))
    thing
    if (!is.null(thing2)) thing2
    dev.off()
}

# ==============================
# Dane

gwozdzie_lambda = c(6.7, 8, 7.66, 8.36, 6.51, 7.49, 7.96, 7.26, 7.56, 7.7, 7.49, 7.5, 7.9, 7.18, 7.74, 7.06, 6.99, 6.82, 7.88, 7.07, 7.8, 7.43, 7.26, 6.96, 6.86, 7.27)

gwozdzie_mu = c(6.12, 7.28, 5.85, 7.78, 5.53, 6.2, 7.07, 7.22, 6.89, 7.06, 5.6, 6.85, 7.78, 5.48, 6.94, 6.82, 7.52, 7.63, 6.44, 7.32, 7.17)

alpha = 1 - 0.95

# ==============================
# ZADANIE 1

writeln("Zadanie 1"); 
writeln("a)");

lambda.avg = mean(gwozdzie_lambda);
lambda.sd = sd(gwozdzie_lambda);
lambda.var = var(gwozdzie_lambda);
lambda.len = length(gwozdzie_lambda);

writeln(c("   - Średnia:                  " , lambda.avg))
writeln(c("   - Odchylenie standardowe:   " , lambda.sd))


writeln("b)");

L = lambda.avg - qt(1-alpha/2, df=lambda.len-1)*(lambda.sd/sqrt(lambda.len-1))
U = lambda.avg + qt(1-alpha/2, df=lambda.len-1)*(lambda.sd/sqrt(lambda.len-1))
writeln(c("   - Przedział ufności war. oczekiwanej: (" , L, ', ', U, ')'))

L = (lambda.len*lambda.sd^2)/qchisq(alpha/2,df=lambda.len-1)
U = (lambda.len*lambda.sd^2)/qchisq(1-alpha/2,df=lambda.len-1)
writeln(c("   - Przedział ufności wariancji: (" , U, ', ', L, ')'))

writeln("c)");

zadanie1c <- function(alfa) {
    abs(diff(lambda.avg + c(-1, 1) * lambda.sd / sqrt(lambda.len-1) * qnorm(1-alfa/2)))
}

writeln(c(0.00000003762, " ", zadanie1c(0.00000003762)));
writeln(c(0.00000003763, " ", zadanie1c(0.00000003763)));
writeln(c(0.00000003764, " ", zadanie1c(0.00000003764)));

# 1d
zadanie1d_war <- function(n) {
  abs(diff((n-1) * 1/qchisq(c(1-alpha/2, alpha/2),df=n-1) * lambda.var))
}

zadanie1d_avg <- function(n) {
  abs(diff(round(lambda.avg+c(-1,1)*lambda.sd/sqrt(n-1)*qnorm(.975),2)))
}

zadanie1d_war(6);
zadanie1d_war(7);

zadanie1d_avg(1);
zadanie1d_avg(2);
zadanie1d_avg(3);
zadanie1d_avg(4);
zadanie1d_avg(5);
zadanie1d_avg(6);

# 1e

# Zadanie 2

writeln("Zadanie 2"); 
writeln("a)");
t.test(x = gwozdzie_lambda, y = gwozdzie_mu, alternative = c("two.sided"), var.equal = TRUE, conf.level = 1-alpha)

writeln("b)");
var.test(x = gwozdzie_lambda, y = gwozdzie_mu, alternative = c("two.sided"), var.equal = TRUE, conf.level = 1-alpha)

