import random as rn

def randperm(n):
    hist = [0 for i in range(n)]
    result = hist[:]
    
    for i in range(n):
        hist[i] = 0
    
    i = 0
    while i < n:
        candidate = rn.randint(0, n-1)
        if hist[candidate] == 0:
            result[i] = candidate
            hist[candidate] += 1
            i += 1
    return result

#//**********************************

for i in range(5):
    print(randperm(10))