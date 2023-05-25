from collections import defaultdict as dd

#-----------------------------------------------

slowa = open('popularne_slowa.txt').read().split()

#------------------------------------------------

def histogram(slowo):
    hist = dd(lambda: 0)
    for litera in slowo:
        hist[litera] += 1
    return hist

def ukladalne(hist, histW, slowoW):
    for litera in slowoW:
        if hist[litera] != histW[litera]:
            return False
    return True

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
    
    for slowo in slowa:
        if ukladalne_1_z_2(slowo, histWejsc):
            nowe_slowa.append(slowo)
    
    for indeks1 in range(len(nowe_slowa)):
        slowo1 = nowe_slowa[indeks1]
        
        if len(slowo1) >= len(slowoWejsc): continue
        
        for indeks2 in range(indeks1+1, len(nowe_slowa)):
            slowo2 = nowe_slowa[indeks2]
            
            if len(slowo1) + len(slowo2) != len(slowoWejsc): continue
            
            hist = histogram(slowo1+slowo2)
            
            if ukladalne(hist, histWejsc, slowoWejsc):
                print(slowo1, slowo2)

#------------------------------------------------

zagadka('Paweł Rychlikowski')