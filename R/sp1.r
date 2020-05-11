# technicznie

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
# DANE

salary = c(2.88, 4.02, 3.05, 2.94, 3.07, 8.37, 3.15, 11.5, 7.39, 2.77, 2.81, 2.56, 6.39, 5.24, 3.79, 7.45, 2.62, 8.69, 2.52, 2.75,
          2.76, 3.25, 3, 2.93, 7.26, 3.26, 5.85, 7.61, 2.81, 6.55, 2.78, 5.62, 3.22, 3.46, 2.87, 2.69, 3.99, 9.15, 2.97, 2.74,
          3.5, 4.03, 4.9, 2.74, 2.51, 3.25, 3, 4.84, 3.3, 2.76, 3.28, 5.42, 3.03, 4.52, 2.92, 8.76, 2.97, 3.5, 6.02, 3.53,
          2.75, 2.56, 3.25, 3.04, 11.98)

degree = c("Sr", "Sr", "P", "Z", "Sr", "Sr", "P", "P", "Sr", "W", "P", "Z", "Sr", "W", "Sr", "Sr", "Sr", "Sr", "Z", "Z",
"Z", "Z", "W", "P", "W", "W", "W", "Sr", "Z", "W", "P", "P", "P", "P", "W", "Z", "P", "W", "Z", "P",
"Z", "P", "W", "W", "Sr", "W", "Z", "W", "P", "W", "Z", "P", "Z", "Sr", "W", "Z", "P", "P", "W", "Z",
"W", "Sr", "Sr", "Z", "P")

data1 <- data.frame(matrix(c(salary, degree), nrow=65, ncol=2))
colnames(data1) <- c("Salaries", "Degrees")


# ==============================
# Zadanie 1

salary.length <- length(salary)
n <- salary.length

# 1a - Średnia
salary.avg <- sum(salary) / length(salary)

# 1a - Odchylenie standardowe
salary.variance <- sum((salary - salary.avg)^2) / (salary.length-1)
salary.stddev <- sqrt(salary.variance)

# 1a - Asymetria
salary.asym <- sum((salary-salary.avg)^3) / (sum((salary-salary.avg)^2))^1.5

# 1a - Kurtoza
salary.kurt <- (1/n*sum((salary-salary.avg)^4))/(salary.stddev^4)-3

# 1b - Mediana i kwartyle
kwantyl <- function(x, q) {
	x.sort = sort(x)
	n <- length(x.sort)
	L <- (n+1) * q
	M <- floor(L)
	(1 - (L - M)) * x.sort[M] + (L - M) * x.sort[M+1]
}

salary.median    <- kwantyl(salary, 1/2)
salary.quantiles <- kwantyl(salary, c(1/4, 1/2, 3/4))

# 1c - Pozycyjne miary

getmode <- function(v) {
	uniqv <- unique(v)
	uniqv[which.max(tabulate(match(v, uniqv)))]
}

salary.Q3 <- kwantyl(salary, 3/4)
salary.Q1 <- kwantyl(salary, 1/4)
salary.asymPos <- (salary.Q1 + salary.Q3 - 2*salary.median)/(salary.Q3-salary.Q1)
salary.range <- (max(salary) - min(salary)) / floor(sqrt(length(salary)))
salary.mode <- getmode(salary)

# 1d - Szereg rozdzielczy

rangeCount <- trunc(sqrt(65))
rangeLeft <- min(salary)
rangeRight <- max(salary)
rangeStep <- (rangeRight - rangeLeft)/(rangeCount)

rangeTable <- min(salary)+0:rangeCount*rangeStep

rangeMids <- list()
for (i in 1:(rangeCount)) {
	rangeMids <- c(rangeMids, mean(c(rangeTable[i], rangeTable[i+1])))
}

counts <- table(cut(salary, rangeTable, include.lowest=TRUE))

sumCounts <- counts
for (i in 2:length(counts)) {
    sumCounts[i] <- sumCounts[i-1]+counts[i]
}

# 1f - gęstość
salary.density <- function(x) {
    dnorm(x, mean=salary.avg, sd=salary.stddev)
}
norm1x <- seq(2, 12, 0.1)
norm1y <- salary.density(norm1x)

# 1h - empiryczna
salary.empiric <- ecdf(salary)

# 1i 
zadanie1i <- function() {
    alfa <- 0.05
    n <- length(salary)
    t <- qt(1 - alfa/2, df = n - 1)
    s <- sd(salary)
    mean(salary) + c(-1, 1) * s / sqrt(n) * t
}



# Wydruk

writeln("Zadanie 1"); 
writeln("a) Miary klasyczne");
writeln(c("   - Średnia:                  " , salary.avg))
writeln(c("   - Odchylenie standardowe:   " , salary.stddev))
writeln(c("   - Asymetria:                " , salary.asym))
writeln(c("   - Kurtoza:                  " , salary.kurt))
writeln(c("b) Mediana:                    " , salary.median))
writeln(c("   Kwartyle:                   [", toString(salary.quantiles), "]"), " ")
writeln("c) Miary pozycyjne");
writeln(c("   - Asymetria:                " , salary.asymPos),sep="")
writeln(c("   - Modalna:                  " , salary.mode),sep="")
writeln(c("   - Odchylenie ćwiartkowe:    " , (salary.Q3-salary.Q1)/2))
writeln("d) Szereg rozdzielczy");
writeln(c("   - Krańce przedziałów:       [", toString(rangeTable), "]"), " ")
writeln(c("   - Środki przedziałów:       [", toString(rangeMids), "]"), " ")
writeln("   - Liczebność:                ")
for (i in 1:length(counts)) {
    writeln(c("\t", labels(counts[i]), ":\t", counts[i]))
}
writeln("   - Częstość względna:           ")
for (i in 1:length(counts)) {
    writeln(c("\t", labels(counts[i]), ":\t", counts[i]/salary.length))
}
writeln("   - Częstość skumulowana:        ")
for (i in 1:length(counts)) {
    writeln(c("\t", labels(counts[i]), ":\t", sumCounts[i]/salary.length))
}
writeln("   - Gęstość:                     ")
for (i in 1:length(counts)) {
    writeln(c("\t", labels(counts[i]), ":\t", (counts[i]/salary.length)/rangeStep))
}
writeln("e) Histogram liczebności");
saveToPNG(
    "Wykres_1E",
    hist(salary, freq = T, breaks = rangeTable, xlim=c(floor(rangeLeft), ceiling(rangeRight)), col="forestgreen", xlab="Wartości", ylab="Liczebność", main="Histogram liczebności"))

writeln("f) Histogram gęstości + funkcja gęstości rozkładu normalnego");

saveToPNG(
    "Wykres_1F",
    hist(salary, freq = F, breaks = rangeTable, xlim=c(floor(rangeLeft), ceiling(rangeRight)), col="orange", xlab="Wartości", ylab="Gęstość"),
    lines(norm1x, norm1y, col = "red"))

writeln("g) Wykres pudełkowy");
saveToPNG("Wykres_1G", boxplot(salary, main="Wykres pudełkowy", ylim=c(floor(rangeLeft), ceiling(rangeRight)), col="green"))

writeln("h) Dystrybuanta empiryczna + funkcja gęstości rozkładu normalnego");
saveToPNG(
    "Wykres_1H",
    plot(salary.empiric, xlim=c(floor(rangeLeft), ceiling(rangeRight)), col="orange", xlab="Wartości", ylab="Gęstość"),
    lines(norm1x, norm1y, col = "red"))

writeln(c("i) Przedział ufności: [", toString(zadanie1i()), "]"), " ")
writeln(c("j) P(4<X<5):          ", pnorm(5, mean=salary.avg, sd=salary.stddev) - (pnorm(4, mean=salary.avg, sd=salary.stddev))));
writeln(c("k) P = ", pnorm(30*5,mean=30*salary.avg,sd=salary.stddev)-pnorm(30*4,mean=30*salary.avg,sd=salary.stddev)));

writeln("");

# ========================
# Zadanie 2


degrees <- lapply(data1$Degrees, function(x) {
         if (x == "P") 0
    else if (x == "Z") 1
    else if (x == "Sr") 2
    else if (x == "W") 3
    else -1
})
degrees <- unlist(degrees)
degrees

# a

# robota

writeln("Zadanie 2");
writeln("a) Miary klasyczne");
writeln(c("   - Średnia:                  " , salary.avg))
writeln(c("   - Odchylenie standardowe:   " , salary.stddev))
writeln(c("   - Asymetria:                " , salary.asym))
writeln(c("   - Kurtoza:                  " , salary.kurt))



