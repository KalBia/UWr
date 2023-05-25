from random import *

#---------------------------------------------------------------------
# drużyna = (0-nazwa, 1-potencjał obronny, 2-potencjał ofensywny, 3-siła bramkarza, 4-bramkostrzelność)
arabia = ('Arabia_Saudyjska', 2, 3, 0.3, 0.3)
argentyna = ('Argentyna', 4, 6, 0.5, 0.8)
meksyk = ('Meksyk', 3, 4, 0.6, 0.5) 
polska = ('Polska', 2, 3, 0.9, 0.8)

grupa = [arabia, argentyna, meksyk, polska]
#---------------------------------------------------------------------
def FA(druzyna):
    return druzyna[2] + randint(1, 6)

def FD(druzyna):
    return druzyna[1] + randint(1, 6)

def okazje_strzeleckie(FA, FD):
    if FA > FD:
        return FA-FD
    return 0

def strzal_do_bramki(sila_bramkarza, bramkostrzelnosc):
    b = random()*sila_bramkarza
    g = random()*bramkostrzelnosc
    if g > b:
        return 1
    return 0

def mecz(A, B):
    Awynik = 0
    Bwynik = 0
    aFA = FA(A)
    bFA = FA(B)
    aFD = FD(A)
    bFD = FD(B)
    Aokazje = okazje_strzeleckie(aFA, bFD)
    Bokazje = okazje_strzeleckie(bFA, aFD)
    
    for i in range(Aokazje):
        Awynik += strzal_do_bramki(B[3], A[4])
    for i in range(Bokazje):
        Bwynik += strzal_do_bramki(A[3], B[4])
    
    return (Awynik, Bwynik)

def rozgrywki_grupowe(grupa, czy_wypisywac_wyniki):
    wyniki = {}
    ranking = {}
    bilans = {}
    for a in range(len(grupa)):
        for b in range(a+1, len(grupa)):
            #wyniki meczow
            punkty = mecz(grupa[a], grupa[b])
            wyniki[(grupa[a][0], grupa[b][0])] = punkty
            
            #punktacja            
            if grupa[a][0] not in ranking:
                ranking[grupa[a][0]] = 0
            if grupa[b][0] not in ranking:
                ranking[grupa[b][0]] = 0
            
            if punkty[0] > punkty[1]:
                ranking[grupa[a][0]] += 3
            elif punkty[1] > punkty[0]:
                ranking[grupa[b][0]] += 3
            else:
                ranking[grupa[a][0]] += 1
                ranking[grupa[b][0]] += 1
                
            #bilans            
            if grupa[a][0] not in bilans:
                bilans[grupa[a][0]] = 0
            if grupa[b][0] not in bilans:
                bilans[grupa[b][0]] = 0
            
            bilans[grupa[a][0]] += punkty[0] - punkty[1]
            bilans[grupa[b][0]] += punkty[1] - punkty[0]            
    
    if czy_wypisywac_wyniki:
        for A,B in wyniki.items():
            print(A[0], "vs", A[1], ":", B)
            
    #tworzenie kolejnosci
    kolejnosc = [0 for i in range(len(grupa))]
    for a in range(len(grupa)):
        for b in range(a+1, len(grupa)):
            if ranking[grupa[a][0]] > ranking[grupa[b][0]]:
                kolejnosc[a] += 1
            elif ranking[grupa[b][0]] > ranking[grupa[a][0]]:
                kolejnosc[b] += 1
            else:
                if bilans[grupa[a][0]] > bilans[grupa[b][0]]:
                    kolejnosc[a] += 1
                elif bilans[grupa[b][0]] > bilans[grupa[a][0]]:
                    kolejnosc[b] += 1
                else:
                    los = randint(0, 1)
                    if los: kolejnosc[a] += 1
                    else: kolejnosc[b] += 1
    
    lista_druzyn_w_kolejnosci = []
    i = len(grupa)-1
    while i >= 0:
        for j in range(len(grupa)):
            if kolejnosc[j] == i:
                lista_druzyn_w_kolejnosci.append(grupa[j][0])
        i -= 1
    
    return lista_druzyn_w_kolejnosci
#----------------------------------------------------------------------
#SYMULACJA POLSKA-ARGENTYNA
wygrane = 0
for i in range(100_000):
    proba = mecz(polska, argentyna)
    if proba[0] > proba[1]:
        wygrane += 1
prawdopodobienstwo = wygrane/100_000
print("Prawdopodobieństwo wygranej Polski nad Argentyną:", prawdopodobienstwo)
#----------------------------------------------------------------------
#TESTY
test = rozgrywki_grupowe(grupa, True)
#----------------------------------------------------------------------
#SYMULACJA ROZGRYWEK
top2Polska = 0
for i in range(100_000):
    proba = rozgrywki_grupowe(grupa, False)
    if proba[0] == 'Polska' or proba[1] == 'Polska':
        top2Polska += 1
prawdopodobienstwo2 = top2Polska/100_000
print("Prawdopodobieństwo zajęcia top 2 miejsc przez Polskę w grupie:", prawdopodobienstwo2)