lalka = open('lalka-tom-pierwszy.txt').read().split()
slowa = set(open('popularne_slowa.txt').read().split())
licznik = {}

for indeks_lalka in range(len(lalka)):
    for dlugosc_slowa in range(5, 10):
        if indeks_lalka + dlugosc_slowa >= len(lalka):
            continue
        
        wyraz = ''
        for indeks_sklejanie in range(dlugosc_slowa):
            wyraz += lalka[indeks_lalka+indeks_sklejanie][0]
        
        if wyraz in slowa:
            print("wyraz to:", wyraz)
            if wyraz not in licznik:
                licznik[wyraz] = 0
            licznik[wyraz] += 1
            
            for indeks_sklejanie in range(dlugosc_slowa):
                print(lalka[indeks_lalka+indeks_sklejanie], end=" ")
            print()
  
#wersja rozszerzona
print()
mistrz = sorted(licznik.keys(), key=licznik.get, reverse=True)[0]
print("mistrzowskie slowo to:", mistrz)

for indeks_lalka in range(len(lalka)):
    for dlugosc_slowa in range(5, 10):
        if indeks_lalka + dlugosc_slowa >= len(lalka):
            continue
        
        wyraz = ''
        for indeks_sklejanie in range(dlugosc_slowa):
            wyraz += lalka[indeks_lalka+indeks_sklejanie][0]
        
        if wyraz == mistrz:         
            for indeks_sklejanie in range(dlugosc_slowa):
                print(lalka[indeks_lalka+indeks_sklejanie], end=" ")
            print()