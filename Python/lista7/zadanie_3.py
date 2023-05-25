tekst_lalki = open('lalka-tom-pierwszy.txt').read().split()
polskie_slowa = set(open('popularne_slowa.txt').read().split())

#------------------------------------------------------------------------------------

def przerobka_znaki_interpunkcyjne(tekst):
    for slowo in tekst:
        for znak in slowo:
            if znak in {'.', ',', '"', "'", "?", "!", "-", '(', ')', '/', ':', ';'}:
                slowo = slowo.replace(znak, '')
    return tekst

def bez_polskich_znakow(slowo):
    for znak in slowo:
        if znak in 'ąśćłóźżęń':
            return False
    return True

def wypis_fragmentu(indeks, dlugosc):
    for i in range(indeks, indeks+dlugosc):
        print(tekst_lalki[i], end=" ")
    print()

def szukanie_fragmentu():
    przerobiony_tekst = przerobka_znaki_interpunkcyjne(tekst_lalki)
    maks_dlugosc_fragmentu = 0
    maks_liczba_slow = 0
    indeks_do_wypisu = 0
    dlugosc_tekstu = len(przerobiony_tekst)
    
    for indeks_pierwszego in range(dlugosc_tekstu):
        dlugosc_fragmentu = 0
        liczba_slow = 0
        for indeks_aktualny in range(indeks_pierwszego, dlugosc_tekstu):
            if bez_polskich_znakow(przerobiony_tekst[indeks_aktualny]) and (przerobiony_tekst[indeks_aktualny].lower() in polskie_slowa or przerobiony_tekst[indeks_aktualny] in polskie_slowa):
                dlugosc_fragmentu += len(przerobiony_tekst[indeks_aktualny])
                liczba_slow += 1
            else:
                if dlugosc_fragmentu > maks_dlugosc_fragmentu:
                    maks_dlugosc_fragmentu = dlugosc_fragmentu
                    maks_liczba_slow = liczba_slow
                    indeks_do_wypisu = indeks_pierwszego
                    print("POSZUKIWANIA!")
                    wypis_fragmentu(indeks_do_wypisu, maks_liczba_slow)
                break
    
    print("\n\nOSTATECZNY FRAGMENT!")
    wypis_fragmentu(indeks_do_wypisu, maks_liczba_slow)

#----------------------------------------------------------------------------------------

szukanie_fragmentu()