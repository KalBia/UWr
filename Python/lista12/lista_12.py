# BRAK PUNKTÓW WPISANYCH MIMO ZROBIENIA ZADAŃ:
#--------------------------------------------------
#   lista 10, zadanie 4
#   lista 11, zadanie 2
#--------------------------------------------------
#--------------------------------------------------
#--------------------------------------------------
# KOLOKWIUM 2020
#--------------------------------------------------
# a) dla listy dodatnich liczb całkowitych obliczy średnią długość
# elementu na tej liście (mierzonego liczbą cyfr)
#--------------------------------------------------
def średnia_liczba_cyfr(L):
    return round( ( sum([len(str(el)) for el in L]) ) / len(L) ) 
            # suma długości el. w L przez liczbę el. w L

print("średnia_liczba_cyfr:", średnia_liczba_cyfr([123, 4325, 18490, 421677, 1, 23, 444]))

#--------------------------------------------------
# b) na wejściu bierze ciąg cen danej akcji w kolejnych dniach działania giełdy, 
# i zwraca maksymalny zysk, jaki odnotujemy, gdy akcję tę jednokrotnie kupimy i jednokrotnie
# sprzedajemy 
#--------------------------------------------------
def maksymalmy_zysk(L):
    return max([max(L[i:]) - min(L[:i]) for i in range(1, len(L))])
            # max z wartosci max sprzedaży w dniach po kupnie - min kupna do pewnego dnia

print("maksymalny_zysk:", maksymalmy_zysk([2, 15, 1, 3, 15, 4, 6]))

#--------------------------------------------------
# c) która zwraca True wtedy i tylko wtedy, gdy napis s składa się z samych
# słów typu Tytułowego (czyli wielka litera na początku, później same małe)
#--------------------------------------------------
def czy_Tytułowe(slowo):
    return (slowo[0] == slowo[0].upper() and slowo[1:] == slowo[1:].lower())
        # False gdy pierwsza litera nie jest duża lub pozostałe nie są małe
    
def czy_jest_tytulem(s):
    return all(czy_Tytułowe(slowo) for slowo in s.split())
        # zwraca prawdę jeśli wszystkie słowa są Tytułowe

print("czy_jest_tytulem:", czy_jest_tytulem('Ania Zielonego Wzgórza'))

#--------------------------------------------------
# d) jako argument bierze słownik, w którym klucze i wartości są liczbami. 
# Funkcja powinna zwrócić (dowolny) klucz, dla którego różnica między nim a 
# przypisaną mu wartością jest największa (co do wartości bezwględnej).
#--------------------------------------------------
def maksymalny_skok(D):
    return max([(abs(key - D[key]), key) for key in D])[1]
        # zwraca drugi element z pary (czyli klucz), gdzie różnica to max

print("maksymalny_skok:", maksymalny_skok({5:3, 6:1, 7:70, 2:15, 3:4}))

#--------------------------------------------------
# e) dla listy liczb L zwraca listę zawierającą te same liczby, posortowaną leksykograficznie
#--------------------------------------------------
def posortowana_leksykograficznie(L):
    return [ int(EL) for EL in sorted([str(el) for el in L]) ]
        # return sorted(L, key=str)
        # najpierw sortuje string zrobione z el. L a potem znowu z nich robi inty

print("posortowana_leksykograficznie:", posortowana_leksykograficznie([1,4,55,222,9,10]))

#--------------------------------------------------
# f) która sortuje rosnąco ciąg bitów (czyli liczb 0 i 1)
#--------------------------------------------------
def sortuj_bity(L):
    return (len(L)-sum(L))*[0] + sum(L)*[1]
        # zer jest długość_tablicy_L - suma_elementów_L, a jedynek jest suma_elementów_L

print("sortuj_bity:", sortuj_bity([0, 0, 1, 1, 0, 1, 0]))

#--------------------------------------------------