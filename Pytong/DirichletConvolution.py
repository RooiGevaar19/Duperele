import math

def f(n):
    return n*n

def g(n):
    return math.sin(n)

def DirichletConvolve(f,g,n):
    return sum(f(d)*g(n//d) for d in range(1,n+1) if 1>n%d)

print(DirichletConvolve(f,g,4))