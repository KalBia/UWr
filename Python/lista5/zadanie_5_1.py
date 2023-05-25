#specyfikacja:
#   wejście: a - całkowite dodatnie

#definicje: 
#   energia liczby a - pozycja, na której w tym ciągu po raz pierwszy pojawia się jedynka, licząc od zera
#//**********************************

def F(a):
    if a % 2 == 0:
        return a/2
    else:
        return 3*a + 1

def energia(a):
    licznik = 0
    while a != 1:
        a = F(a)
        licznik += 1
    return licznik

def analiza_collatza(a, b):
    #wszystkie energie liczb od a do b
    MIN = 2**b
    MAX = 0
    amount = b-a+1
    A = [0 for i in range(amount)]
    sum = 0
    for i in range(amount):
        x = energia(a+i)
        A[i] = x
        sum += x
        MAX = max(x, MAX)
        MIN = min(x, MIN)
        
    
    print("Analiza Collatza dla liczb od " + str(a) + " do " + str(b))
    #srednia energia
    print("Średnia energia wynosi:", sum/amount)
    
    #mediana energii
    print("Mediana energii wynosi: ", end="")
    A = sorted(A)
    if amount % 2 == 1:
        print(A[amount//2])
    else:
        print( (A[amount//2-1] + A[amount//2])/2 )
    
    #maks i min energia
    print("Maksymalna energia wynosi:", MAX)
    print("Minimalna energia wynosi:", MIN)
    
    print()
    
#//**********************************
analiza_collatza(3, 6)