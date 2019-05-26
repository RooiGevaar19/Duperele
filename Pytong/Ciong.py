import math

def isPrime(x):
    if (x < 2):
        return False
    if (x <= 3):
        return True
    for i in range(2, int(math.sqrt(x))+1):
        if (x % i == 0):
            return False
    return True

def buildSet(n):
    s = []
    for i in range(2, n+1):
        if (isPrime(i)):
            s.append(i)
    return s

numbers = buildSet(10000000)

print numbers

for i in range(0, len(numbers)-1):
    print 'a_' + str(i) + ':\t' + str(numbers[i+1]) + "\t" + str(numbers[i]) + "\t" + str(numbers[i+1]*1.0/numbers[i])