# -*- coding: windows-1250 -*-

alfabet = 'aąbcćdeęfghijklłmnńoóprsśtuwyzźż'
slowa = open('/home/kalina/Python/popularne_slowa.txt').read().split()

#--------------------------------------------------

def slownik_szyfrujacy():
    litery = [x for x in alfabet]
    wykodowane = [alfabet[indeks:] + alfabet[:indeks] for indeks in range(len(alfabet))]
    slownik = {litera: kodowanie for litera, kodowanie in zip(litery, wykodowane)}
    return slownik

def ceasar(slowo, klucz):
    szyfrowanie = slownik_szyfrujacy()
    szyfrogram = ''
    slowo = slowo.lower()
    
    for litera in slowo:
        if litera not in szyfrowanie:
            return -1
        szyfrogram += szyfrowanie[litera][klucz]
    
    return szyfrogram

#--------------------------------------------------

leng = len(alfabet)
rowne_szyfrogramy = {}

for slowo in slowa:
    slowo = slowo.lower()
    
    indeks = -1
    for i in range(len(alfabet)):
        if alfabet[i] == slowo[0]:
            indeks = i
        
    if indeks == -1:
        continue
    
    klucz = (leng - indeks) % leng
    szyfrogram = ceasar(slowo, klucz)
    
    if szyfrogram == -1:
        continue
    
    if szyfrogram not in rowne_szyfrogramy:
        rowne_szyfrogramy[szyfrogram] = []
    rowne_szyfrogramy[szyfrogram].append(slowo)

rez = []
MAXdl = 0
for klucz in rowne_szyfrogramy.keys():
    if len(rowne_szyfrogramy[klucz]) > 1:
        if MAXdl < len(klucz):
            MAXdl = len(klucz)
            rez = []
            for el in rowne_szyfrogramy[klucz]:
                rez.append(el)
        elif MAXdl == len(klucz):
            for el in rowne_szyfrogramy[klucz]:
                rez.append(el)

print(*rez)