def F(T,p,k,e):
    if (k == p):
        if (T[p-1] > e):
            return p
        else:
            return p+1
    else:
        s = int((p+k)/2)
        if (T[s-1] > e):
            return F(T,p,s,e)
        else:
            return F(T,s+1,k,e)

def search(T,a,b):
    i = 0
    count = 0
    while(T[i] < a and i < len(T)):
        i += 1
    while(T[i] <= b and i < len(T)):
        count += 1
        i += 1
    return count

database = [
    [3,4,6,8,9],
    [15,16,18,22,24],
    [2,10,16,24,26],
    [1,3,10,10,18]
]

p = 1
k = 5
e = 10

print("Przeszukiwanie 1")
for I in database:
    print F(I,p,k,e)

print("Przeszukiwanie")
print search(database[0],4,8)