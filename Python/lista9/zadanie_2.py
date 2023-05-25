from collections import defaultdict as dd

#-----------------------------------------------

slowa = open('/home/kalina/Python/popularne_slowa.txt').read().split()

#------------------------------------------------

def histogram(slowo):
    hist = dd(lambda: 0)
    for litera in slowo:
        hist[litera] += 1
    return hist

def dobor_trzeciego(hist, histW, slowoW):
    trzecie = ''
    for litera in set(sorted(slowoW)):
        for i in range(histW[litera]-hist[litera]):
            trzecie += litera
    return str(sorted(trzecie))

def ukladalne_1_z_2(slowo1, hist2):
    hist1 = histogram(slowo1)
    for litera in slowo1:
        if hist2[litera] < hist1[litera]:
            return False
    return True

def zagadka(slowoWejsc):
    slowoWejsc = slowoWejsc.lower()
    slowoWejsc = slowoWejsc.replace(" ", "")
    histWejsc = histogram(slowoWejsc)
    nowe_slowa = []
    posortowane = {}
    rez = set()
    
    for slowo in slowa:
        if ukladalne_1_z_2(slowo, histWejsc):
            nowe_slowa.append(slowo)
            
            posort_slowo = str(sorted(slowo))
            if posort_slowo not in posortowane:
                posortowane[posort_slowo] = []
            posortowane[posort_slowo].append(slowo)
    
    for indeks1 in range(len(nowe_slowa)):
        slowo1 = nowe_slowa[indeks1]
        
        if len(slowo1) >= len(slowoWejsc): continue
        
        for indeks2 in range(indeks1+1, len(nowe_slowa)):
            slowo2 = nowe_slowa[indeks2]            
            hist = histogram(slowo1+slowo2)
            
            if len(slowo1+slowo2) >= len(slowoWejsc): continue
            
            if ukladalne_1_z_2(slowo1+slowo2, histWejsc):
                trzecie = dobor_trzeciego(hist, histWejsc, slowoWejsc)
                if trzecie in posortowane:           
                    for slowo3 in posortowane[trzecie]:
                        if slowo3 == slowo1 or slowo3 == slowo2: continue
                        rez.add(tuple(sorted([slowo1, slowo2, slowo3])))
                        if indeks1 % 10 == 0:
                            print('indeks1:', indeks1)
    
    for trojka in rez:
        print(*trojka)

#------------------------------------------------

zagadka('Paweł Rychlikowski')