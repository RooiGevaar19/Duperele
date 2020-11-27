saveToPNG <- function(filename, thing, 
        thing1=NULL, thing2=NULL, thing3=NULL, thing4=NULL,
        thing5=NULL, thing6=NULL, thing7=NULL, thing8=NULL) {
    png(paste(filename, ".png", sep=""))
    thing
    if (!is.null(thing1)) thing1
    if (!is.null(thing2)) thing2
    if (!is.null(thing3)) thing3
    if (!is.null(thing4)) thing4
    if (!is.null(thing5)) thing5
    if (!is.null(thing6)) thing6
    if (!is.null(thing7)) thing7
    if (!is.null(thing8)) thing8
    dev.off()
}

f <- function(n) {
  (-1)^n * (1/n)
}

saveToPNG("wykresik",
    plot(f(1:50), 
        pch=16,
        ylab="A(n)",
        xlab="n",
        col="red"),
    abline(h=0, col="orange"),
    abline(h=0.1, col="yellow"),
    abline(h=-0.1, col="yellow")
)
