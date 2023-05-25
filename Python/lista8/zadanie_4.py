from turtle import *
from random import *
import numpy as np

#-------------------------------------------------------------------------

kolory = ['green', (0.5, 1, 0) , 'yellow', 'orange', 'red', (0.5, 0,0) ]
tracer(0, 0)
#speed('fastest')

#-------------------------------------------------------------------------

def piksel(skala, kolor):
    color(kolor, kolor)
    pendown()
    begin_fill()
    
    for i in range(4):
        fd(skala)
        rt(90)
    
    penup()
    end_fill()
    
def srednia(x, y, teren):
    sas = [(-1, -1), (-1, 0), (0, -1), (0, 0), (1, 0), (0, 1), (1, 1), (-1, 1), (1, -1)]
    suma = 0.0
    waga = 0
    for para in sas:
        el = teren[x+para[0]][y+para[1]]
        if el != 0:
            waga += 1
            suma += el
    if waga == 0:
        waga = 1
    return suma/waga
    
def gen_teren():
    teren = np.array([[0.0 for i in range(103)] for j in range(103)])
    #wzgórza
    for i in range(17):
        x = randint(1, 100)
        y = randint(1, 100)
        high = random()
        teren[x][y] = high
    #pozostałe pola
    for i in range(230_000):
        x = randint(1, 100)
        y = randint(1, 100)
        teren[x][y] = srednia(x, y, teren)
    #przeskalowanie
    skalar = 5
    teren *= skalar

    return teren

def mapa(teren, skala):
    X = 100
    Y = 100
    sx = -50
    sy = 50
    i = 1
    for x in range(sx, sx+X):
        j = 1
        for y in range(sy, sy+Y):
            penup()
            goto(skala*x, skala*y)
            piksel(skala, kolory[round(teren[i][j])])
            j += 1
        i += 1
    
#-------------------------------------------------------------------------

teren = gen_teren()
mapa(teren, 2)    

update()
input()        