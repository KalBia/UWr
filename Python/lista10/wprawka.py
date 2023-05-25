def wieza(klocki):
    szerokosc = 2*klocki - 1
    
    puste = (szerokosc - 1) // 2
    pelne = 1
    for nr_klocka in range(klocki):
        for wiersz in range(3):
            print(puste*' ' + pelne*'#')
        puste -= 1
        pelne += 2

#-------------------------------------------

wieza(5)

#-------------------------------------------

def wieza_w_tablicy(klocki, indeks_szer, indeks_wys, tablica):
    szerokosc = 2*klocki - 1
    
    pelne = szerokosc
    puste = 0
    for nr_klocka in range(klocki):
        for wiersz in range(3):
            for i in range(pelne):
                tablica[indeks_szer+puste+i][indeks_wys] = '#'
            indeks_wys -= 1
        puste += 1
        pelne -= 2

def wieze(lista_wiez):
    liczba_wiez = len(lista_wiez)
    
    szerokosc_calosci = 0
    max_wysokosc = 0
    for nr_wiezy in range(liczba_wiez):
        szerokosc_calosci += 2*lista_wiez[nr_wiezy]
        max_wysokosc = max(max_wysokosc, lista_wiez[nr_wiezy])
    
    max_wysokosc *= 3
    tablica = [[' ' for i in range(max_wysokosc)] for j in range(szerokosc_calosci)]
    
    indeks_szerokosci = 0
    for nr_wiezy in range(liczba_wiez):
        wieza_w_tablicy(lista_wiez[nr_wiezy], indeks_szerokosci, max_wysokosc-1, tablica)
        indeks_szerokosci += 2*lista_wiez[nr_wiezy]

    return tablica

#----------------------------------------------------

for i in range(3): print()

wiezyczki = wieze([2, 1, 3])

for i in range(len(wiezyczki[0])):
    for j in range(len(wiezyczki)):
        print(wiezyczki[j][i], end='')
    print()