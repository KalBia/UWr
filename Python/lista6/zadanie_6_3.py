from math import sqrt

def pierwsze_dzielniki(liczba):
    dzielniki = set()
    while liczba % 2 == 0 and liczba > 1:
        dzielniki.add(2)
        liczba //= 2
    for i in range(3, liczba+1):
        while liczba % i == 0 and liczba > 1:
            dzielniki.add(i)
            liczba //= i
    return dzielniki

#------------------------------------------------------

print(pierwsze_dzielniki(121))