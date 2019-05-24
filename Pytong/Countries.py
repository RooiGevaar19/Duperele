import random

database = [
    "Denmark", "China", "Israel", "India", 
    "Poland", "Portugal", "Puerto Rico", "Panama",
    "Sweden", "Switzerland", "Germany", "Great Britain", 
    "Ghana", "Ukraine", "USA", "France"]

random.shuffle(database)

def howmany(letter):
    count = 0
    for i in database:
        if (i[0] == letter):
            count += 1
    return count

l = raw_input("Enter a letter [A-Z]: ").upper()[:1]
count = howmany(l)
if (count == 0):
    print "No countries in my database. :("
else:
    for i, content in enumerate(filter(lambda x : x[0] == l, database)):
        print "Country no.", i+1, ":", content