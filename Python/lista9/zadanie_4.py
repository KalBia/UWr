from turtle import *
import random
import sys
import time
from copy import deepcopy

#--------------------------------------------

tracer(0,0)
BOK = 15
SX = -100
SY = 0

#--------------------------------------------

plansza_startowa = """
...KKKKKKKKKKKK.......
......................
......................
......................
..NNNN................
..NNNN................
..N...................
......................
.........KKKKKKKKKKK..
......................
......................
......................
......................
.........PPPPP........
......................
"""

plansza_mocy = """
0005555555555550000000
0000000000000000000000
0000000000000000000000
0000000000000000000000
0044440000000000000000
0044440000000000000000
0040000000000000000000
0000000000000000000000
0000000005555555555500
0000000000000000000000
0000000000000000000000
0000000000000000000000
0000000000000000000000
0000000003333300000000
0000000000000000000000
"""

#--------------------------------------------------------------

def kwadrat(x, y, kolor):
    fillcolor(kolor)
    pu()
    goto(SX + x * BOK, SY + y * BOK)
    pd()
    begin_fill()
    for i in range(4):
        fd(BOK)
        rt(90)
    end_fill()

#XXXXXXX     
plansza = [list(wiersz) for wiersz in plansza_startowa.split()]
plansza.reverse()

moc = [list(wiersz) for wiersz in plansza_mocy.split()]
moc.reverse()

MY = len(plansza)
MX = len(plansza[0])

for y in range(MY):
    for x in range(MX):
        moc[y][x] = int(moc[y][x])
#XXXXXXX

def rysuj_plansze(plansza):
    clear()
    for y in range(MY):
        for x in range(MX):
            if plansza[y][x] == '.': # puste pole
                kolor = 'grey'
            elif plansza[y][x] == 'K': # pole kamienia
                kolor = 'yellow'
            elif plansza[y][x] == 'P': # pole papieru
                kolor = 'red'
            elif plansza[y][x] == 'N': # pole nożyc
                kolor = 'blue'
            kwadrat(x, y, kolor)
    update()
    
def pusta_plansza():
    return [MX * ['.'] for y in range(MY)]

def pojedynek_wygrany(typ1, typ2):
    typy = ['K', 'P', 'N']
    indeks1 = 0
    indeks2 = 0
    while typ1 != typy[indeks1]:
        indeks1 += 1
    while typ2 != typy[indeks2]:
        indeks2 += 1
    if indeks1 == (indeks2 - 1) % 3:
        return False
    return True
    
#XXXXXXX
rysuj_plansze(plansza)

kierunki = [(1, 0), (0, 1), (-1, 0), (0, -1)]
#XXXXXXX

#-------------------------------------------------------------

while True:
    rysuj_plansze(plansza)
    nowa = pusta_plansza()
    
    for x in range(MX):
        for y in range(MY):
            if plansza[y][x] != '.':
                RAND = random.randint(0, 3)
                ys = y + kierunki[RAND][1]
                xs = x + kierunki[RAND][0]
                while ys < 0 or ys >= MY or xs < 0 or xs >= MX:
                    RAND = random.randint(0, 3)
                    ys = y + kierunki[RAND][1]
                    xs = x + kierunki[RAND][0]
                    
                if plansza[ys][xs] == '.':
                    if moc[y][x] > 1:
                        nowa[ys][xs] = plansza[y][x]
                        moc[ys][xs] = moc[y][x] - 1
                    nowa[y][x] = plansza[y][x]
                elif plansza[ys][xs] == plansza[y][x]:
                    nowa[y][x] = plansza[y][x]
                    continue
                else:
                    if pojedynek_wygrany(plansza[y][x], plansza[ys][xs]):
                        if moc[y][x] < 5:
                            moc[y][x] += 1
                        moc[ys][xs] -= 1
                        if moc[ys][xs] == 0:
                            nowa[ys][xs] = '.'
                        nowa[y][x] = plansza[y][x]
                    else:
                        if moc[ys][xs] < 5:
                            moc[ys][xs] += 1
                        moc[y][x] -= 1
                        if moc[y][x] == 0:
                            nowa[y][x] = '.'
                        nowa[ys][xs] = plansza[ys][xs]
                            
                    
    if nowa == pusta_plansza():
        rysuj_plansze(nowa)
        time.sleep(1)
        break
    plansza = nowa
    time.sleep(0.5)
    
print('Koniec!')
input()         