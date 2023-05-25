import random
from collections import defaultdict as dd

pol_ang = dd(lambda:[])
ang_pol = dd(lambda:0)

#konwersja pliku ze słownikiem na nasz słownik Pythonowy
for x in open('pol_ang.txt'):
    x = x.strip() #pozbywamy się spacji w wierszu
    L = x.split('=') #dzielimy według znaku równa się
    if len(L) != 2: #jeśli nie mamy dwóch słów, to wers nie zawierał wpisu do słownika
        continue    
    pol, ang = L
    pol_ang[pol].append(ang)
    ang_pol[ang] = 0
    
#obliczanie popularnosci slow angielskich wedlug browna  
for x in open('brown.txt'):
    L = x.split()
    for znak in L:
        if znak in {'.', ',', '"', "'", "?", "!", "-", '(', ')', '/', ':', ';'}:
                slowo = slowo.replace(znak, '')
    for slowo in L:
        if slowo in ang_pol:
            ang_pol[slowo] += 1

#zostawianie w slowniku jedynie slow najpopularniejszych
for slowo in pol_ang:
    best = []
    nrBest = -1
    for tlumaczenie in pol_ang[slowo]:
        if ang_pol[tlumaczenie] > nrBest:
            nrBest = ang_pol[tlumaczenie]
            best.clear()
            best.append(tlumaczenie)
        elif ang_pol[tlumaczenie] == nrBest:
            best.append(tlumaczenie)
    pol_ang[slowo] = best

#tłumaczenie tekstu
def tlumacz(polskie):
    wynik = []
    for s in polskie:
        if s in pol_ang:
            wynik.append(random.choice(pol_ang[s]))
        else:
            wynik.append('[?]')
    return ' '.join(wynik)
    
zdanie = 'chłopiec z dziewczyna pójść do kino'.split()

for i in range(15):
    print (tlumacz(zdanie))            
            
