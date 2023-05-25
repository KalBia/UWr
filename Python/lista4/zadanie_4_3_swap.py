#zerknij jak działa shuffle w c++ - to niżej nie
#ma całkowicie równych prawdopodobieństw wylosowania
#wszystkich permutacji!

import random as rn

def randperm(n):
    result = [i for i in range(n)]
    
    for i in range(2*n):
        a = rn.randint(0, n-1)
        b = rn.randint(0, n-1)
        result[a], result[b] = result[b], result[a]
    return result

#//**********************************

for i in range(5):
    print(randperm(10))
    
x = randperm(10**6)
print("DONE!")