# -*- coding: windows-1250 -*-

alfabet = 'aąbcćdeęfghijklłmnńoóprsśtuwyzźż'

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
        szyfrogram += szyfrowanie[litera][klucz]
    
    return szyfrogram

#--------------------------------------------------

slowo = 'Labladolek'
klucz = 9

print(ceasar(slowo, klucz))