import random
import time

#---------------------------------------------------------------

plansza_startowa = """
CCCCCCCC
CCCCCCCC
........
........
........
........
BBBBBBBB
BBBBBBBB
"""

plansza = [list(wiersz) for wiersz in plansza_startowa.split()]
BOK = 10
M = 8
ruchy_C = [(-1, 1), (0, 1), (1, 1)]
ruchy_B = [(1, -1), (0, -1), (-1, -1)]
pozycje_bialych = [[x, y] for x in range(M) for y in range(M) if plansza[x][y] == 'B']
pozycje_czarnych = [[x, y] for x in range(M) for y in range(M) if plansza[x][y] == 'C']

#----------------------------------------------------------------

def rysuj_plansze():
    for wiersz in plansza:
        print(*wiersz)
        
def dotarl_na_koniec():
    for i in range(M):
        if plansza[M-1][i] == 'C':
            return 'C'
    
    for i in range(M):
        if plansza[0][i] == 'B':
            return 'B'
    
    return -1

def zly_ruch(x, y, ruch, czyj_ruch):
    if x + ruch[0] < 0 or x + ruch[0] >= M:
        return True
    if y + ruch[1] < 0 or y + ruch[1] >= M:
        return True    
    if plansza[x + ruch[0]][y + ruch[1]] == czyj_ruch:
        return True
    if ruch[0] == 0 and plansza[x + ruch[0]][y + ruch[1]] != czyj_ruch:
        return True
    return False

def ruch_do_przodu(x, y, czyj_ruch, ruch):
    xs = x + ruch[0]
    ys = y + ruch[1]
    
    if czyj_ruch == 'B':
        plansza[xs][ys] = czyj_ruch
        pozycje_bialych.add([xs, ys])
        
        plansza[x][y] = '.'
        pozycje_bialych.remove([x, y])
        
    if czyj_ruch == 'C':
        plansza[xs][ys] = czyj_ruch
        pozycje_czarnych.add([xs, ys])
    
        plansza[x][y] = '.'
        pozycje_czarnych.remove([x, y])
    
def ruch_w_bok(x, y, czyj_ruch, ruch):
    xs = x + ruch[0]
    ys = y + ruch[1]
    
    if czyj_ruch == 'B':
        if plansza[xs][ys] != '.':
            pozycje_czarnych.remove([xs, ys])
        
        plansza[xs][ys] = czyj_ruch
        pozycje_bialych.add([xs, ys])
            
        plansza[x][y] = '.'
        pozycje_bialych.remove([x, y])
        
    if czyj_ruch == 'C':
        if plansza[xs][ys] != '.':
            pozycje_bialych.remove([xs, ys])
        
        plansza[xs][ys] = czyj_ruch
        pozycje_czarnych.add([xs, ys])
            
        plansza[x][y] = '.'
        pozycje_czarnych.remove([x, y])
    
def wykonaj_ruch(czyj_ruch, biale, czarne):
    if czyj_ruch == 'B':
        i = random.choice(pozycje_bialych)
        x = i[0]
        y = i[1]
        
        ruch = random.choice(ruchy_B)
        while zly_ruch(x, y, ruch, czyj_ruch):
            ruch = random.choice(ruchy_B)
            
        if ruch[0] == 0:
            ruch_do_przodu(x, y, czyj_ruch, ruch)
        else:
            ruch_w_bok(x, y, czyj_ruch, ruch)     
    else:
        i = random.choice(pozycje_czarnych)
        x = i[0]
        y = i[1]
        
        ruch = random.choice(ruchy_C)
        while zly_ruch(x, y, ruch, czyj_ruch):
            ruch = random.choice(ruchy_C)
            
        if ruch[0] == 0:
            ruch_do_przodu(x, y, czyj_ruch, ruch)
        else:
            ruch_w_bok(x, y, czyj_ruch, ruch)
            
def czy_sa_biale():
    for x in range(M):
        for y in range(M):
            if plansza[x][y] == 'B':
                return True
    return False

def czy_sa_czarne():
    for x in range(M):
        for y in range(M):
            if plansza[x][y] == 'C':
                return True
    return False

#----------------------------------------------------------------

biale = 16
czarne = 16
czyj_ruch = 'B'

while True:
    rysuj_plansze()
    
    # sprawdzamy czy obaj gracze maja wciaz pionki
    if not czy_sa_biale():
        print('B nie ma pionkow, wygrywa C!')
        break
    if not czy_sa_czarne():
        print('C nie ma pionkow, wygrywa B!')
        break
    
    print('Wciąż są pionki!')
    
    # sprawdzamy czy ktorys pionek dotarl na koniec planszy
    koniec = dotarl_na_koniec()
    if koniec != -1:
        print(koniec + ' dotarl na koniec planszy i wygrywa!')
        break
    
    print('Wciąż nikt nie dotarł na koniec!')
    
    biale, czarne = wykonaj_ruch(czyj_ruch, biale, czarne)
    if czyj_ruch == 'B':
        czyj_ruch = 'C'
    else:
        czyj_ruch = 'B'
        
    time.sleep(0.5)
        
print('Koniec!')
input()