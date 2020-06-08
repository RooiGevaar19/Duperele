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

writeln("e)");
m0 = 7
# jeszcze inny sposób, t-wartość statystyki 
t <- ((mean(gwozdzie_lambda)-7)/sd(gwozdzie_lambda)*sqrt(lambda.len))
t
#zbiór krytyczny rózna; kwantyle
qt(alpha/2,lambda.len-1)
qt(1-alpha/2,lambda.len-1)
#przedzialy to -inf do qt(alfa/2,n-1) suma qt(1-alfa/2,n-1) do inf
# t nie należy do przedziału, więc nie odrzucamy H_0
#zbiór krytyczny m > m_0  kwantyl
qt(1-alpha, lambda.len-1)
#przedział to od kwantyl do inf
#t należy do przedziału, więc przyjmujemy H_1

# Zadanie 2

writeln("Zadanie 2"); 
writeln("a)");
t.test(x = gwozdzie_lambda, y = gwozdzie_mu, alternative = c("two.sided"), var.equal = TRUE, conf.level = 1-alpha)

writeln("b)");
var.test(x = gwozdzie_lambda, y = gwozdzie_mu, alternative = c("two.sided"), var.equal = TRUE, conf.level = 1-alpha)

writeln("Zadanie 3"); 

dane_raw <- c(1092, 412, 825, 305, 997, 381, 952, 354, 1088, 435, 1104, 408, 1146, 467, 825, 334)
dane <- matrix(dane_raw,nrow=2)

dane

writeln("a)");

zadanie3a_poparcie <- function(dane, i) {
    dane[2,i]/dane[1,i]
}

zadanie3a_przedzial_ufnosci_lewy <- function(dane, i, alfa) {
    n <- dane[1,i]
    p.poparcia <- zadanie3a_poparcie(dane, i)
    kwantyl <- qt(1-alfa/2, n)
    a <- p.poparcia - kwantyl * sqrt((p.poparcia*(1-p.poparcia))/n)

    a
}

zadanie3a_przedzial_ufnosci_prawy <- function(dane, i, alfa) {
    n <- dane[1,i]
    p.poparcia <- zadanie3a_poparcie(dane, i)
    kwantyl <- qt(1-alfa/2, n)
    b <- p.poparcia + kwantyl * sqrt((p.poparcia*(1-p.poparcia))/n)

    b
}

for (i in 1:ncol(dane)) {
    writeln(c("TYDZIEN ", toString(i)));
    write("Poparcie: ");
    writeln(zadanie3a_poparcie(dane, i)*100);
    write("Przedział ufności: (");
    write(zadanie3a_przedzial_ufnosci_lewy(dane, i, alpha)*100);
    write(", "); 
    write(zadanie3a_przedzial_ufnosci_prawy(dane, i, alpha)*100);
    writeln(")");
}

writeln("");
writeln("b)");

zadanie2b <- function(dane, i, threshold) {
    m1 <- dane[2,i]
    n <- dane[1,i]
    p0 <- threshold
    #wartość statytsyki 
    (m1/n - p0)/(sqrt((p0*(1-p0))/n))
}

prog <- 0.38
for (i in 1:ncol(dane)) {
    writeln(c("TYDZIEN ", toString(i)));
    writeln(c("Wartość statystyki: ", zadanie2b(dane, i, prog)));
    writeln(c("P-wartość: ", min(c(2*pnorm(zadanie2b(dane, i, prog)), 2*(1-pnorm(zadanie2b(dane, i, prog)))))));

}

writeln("");
writeln("c)");

