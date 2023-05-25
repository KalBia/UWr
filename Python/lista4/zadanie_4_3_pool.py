import random as rn

def randperm(n):
    pool = [i for i in range(n)]
    result = [0 for i in range(n)]
    
    for i in range(n):
        candidate = rn.choice(pool)
        result[i] = candidate
        pool.remove(candidate)
    return result

#//**********************************

for i in range(5):
    print(randperm(10))
    
x = randperm(10**6)
print("DONE!")