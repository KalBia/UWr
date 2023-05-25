import math

def czy_pierwsza(n):
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

def czy_szczesliwa(n):
    liczba = str(n)
    test = "777"
    if test in liczba:
        return True
    return False

ile = 0
N = 10**5
print("Szczesliwe liczby pierwsze :D")
for i in range(777, N):
    if czy_pierwsza(i) and czy_szczesliwa(i):
        ile += 1
        print(i)
print("Liczba szczesliwych liczb pierwszych:", ile)
