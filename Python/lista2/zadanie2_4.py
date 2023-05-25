from duze_cyfry import daj_cyfre

def DLC(liczba):
    liczba = str(liczba)
    for i in range(5):
        for cyfra in liczba:
            print( daj_cyfre(int(cyfra))[i], end=" ")
        print()

DLC(340152)