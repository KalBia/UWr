# -*- coding: windows-1250 -*-

alfabet = 'aąbcćdeęfghijklłmnńoóprsśtuwyzźż'

#--------------------------------------------------

# tworzymy slownik ze wszystkimi wystepujacymi w napisie literami
# GIT
def permu_na_slownik(litery, permu):
    slownik = {litera: kodowanie for litera, kodowanie in zip(litery, permu)}
    return slownik

# dzielimy napisy na trzy slowa w dzialaniu
# GIT
def napis_na_slowa(napis):
    slowa = ['', '', '']
    
    indeks = 0
    for znak in napis:
        if znak != ' ':
            if znak == '+' or znak == '=':
                indeks += 1
            else:
                slowa[indeks] += znak
    
    return slowa

# podkladamy pod slowo liczbe wedlug slownika
# GIT
def slowo_na_liczbe(slowo, slownik):
    liczba = 0
    for znak in slowo:
        liczba = liczba*10 + slownik[znak]
    return liczba

# sprawdzamy poprawnosc podstawienia slownikowego
def good(permu, slowa, litery):    
    slownik = permu_na_slownik(litery, permu)
    
    # sprawdzamy czy pierwsza litera to nie zero
    for i in range(3):
        if slownik[slowa[i][0]] == 0:
            return False
    
    # na koniec sprawdzamy czy suma siÄ™ zgadza
    czynnik1 = slowo_na_liczbe(slowa[0], slownik)
    czynnik2 = slowo_na_liczbe(slowa[1], slownik)
    wynik = slowo_na_liczbe(slowa[2], slownik)
    
    if czynnik1 + czynnik2 == wynik:
        return True
    return False

# robimy tablicÄ™ liter z napisu
def stworz_zbior_liter(napis):
    litery = set()
    for znak in napis:
        if znak != ' ' and znak != '+' and znak != '=':
            litery.add(znak)
    
    return list(litery)

# generowanie wszystkich permutacji
def perm(liczby):
    if len(liczby) == 0:
        return [ [] ]
    ps = perm(liczby[1:])
    e = liczby[0]
    return [ p[:i] + [e] + p[i:]  for p in ps for i in range(len(p)+1) ]
            
# czesc glowna
def zagadka(napis):
    napis = napis.lower()
    slowa = napis_na_slowa(napis)
    litery = stworz_zbior_liter(napis)
    
    if len(litery) > 10: # bo wĂłwczas mamy wiÄ™cej liter niĹĽ cyfr do rozdania :c
        return {}
    
    permutacje = perm([i for i in range(10)]) # jest ich 3 628 800
    
    permu = permutacje[0][:len(litery)]
    nr_permutacji = 0
    
    while not good(permu, slowa, litery):

        nr_permutacji += 1
        if nr_permutacji >= len(permutacje):
            return {} 
        
        permu = permutacje[nr_permutacji][:len(litery)]
        
    return permu_na_slownik(litery, permu)

#-------------------------------------------------------------------------------

print(zagadka("SEND + MORE = MONEY"))

# SEND + MORE = 9567 + 1085 = 10652 = MONEY
# czyli:
#   S = 9
#   E = 5
#   N = 6
#   D = 7
#   M = 1
#   O = 0
#   R = 8
#   Y = 2