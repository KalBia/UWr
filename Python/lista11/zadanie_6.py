from array import array
import random
from turtle import *
import time
from math import floor, pi

tracer(0,0)
FRAME_RATE = 1/50

pensize(3)
tracer(0,1)
ht()

#--------------------------------------------------------------------

def prostokat(dlugosc, szerokosc, kolor):
    fillcolor(kolor)
    begin_fill()
    pendown()
    
    fd(dlugosc)
    rt(90)
    fd(szerokosc)
    rt(90)
    fd(dlugosc)
    rt(90)
    fd(szerokosc)
    lt(90)
    
    penup()
    end_fill()

def kolo(liczba_sekwencji, promien, szerokosc, kat, kolor):
    fillcolor(kolor)
    fd(promien)
    rt(90)
    pendown()  
    begin_fill() 
    
    for i in range(16*4*liczba_sekwencji):
        fd(szerokosc/16)
        rt(kat/16)
               
    end_fill()
    penup()    
    
def zmien_kolory(kolory):
    mieszanki = []
    for kolor in kolory:
        kolorek = array('f', [random.randint(5, 10)/10, random.randint(0, 10)/10, random.randint(3, 10)/10])
        mieszanka = array('f', [0, 0, 0])
        for i in range(3):
            mieszanka[i] = 0.7*kolor[i] + 0.3*kolorek[i]
        mieszanki.append(mieszanka)
    return mieszanki
    
def rosnaco(dlugosc, liczba_sekwencji, promien, rosnie, kolory):  
    liczba_sekwencji = floor(liczba_sekwencji)
    kat = 360/(4*liczba_sekwencji)
    szerokosc = (2*pi*promien)/(4*liczba_sekwencji)
    penup()
    
    lt(90)    
    for i in range(liczba_sekwencji):
        for j in range(4):
            kolor = kolory[j]
            fd(promien)
            prostokat(dlugosc, szerokosc, kolor)
            fd(promien)
            rt(180)
            rt(kat)
            dlugosc += rosnie
    
    kolor = kolory[-1]
    kolo(liczba_sekwencji, promien, szerokosc, kat, kolor)
    goto(0, 0)
            
#--------------------------------------------------------------------

D = 2
dlugosc = 10
liczba_sekwencji = 4
kolory = [array('f', [1, 0, 0]), array('f', [0, 1, 0]), array('f', [0, 0, 1]), array('f', [1, 1, 0]), array('f', [1, 0, 1])]
zmiana = 1

while True:
    t0 = time.time()
    clear()
    rosnaco(dlugosc, liczba_sekwencji, 40, 2, kolory)
    if liczba_sekwencji > 25:
        zmiana = -1
    elif liczba_sekwencji < 4:
        zmiana = 1
    liczba_sekwencji += 1*zmiana
    kolory = zmien_kolory(kolory)
    rt(D)
    update()
    delta = time.time() - t0
    if delta < FRAME_RATE:
        time.sleep(FRAME_RATE - delta)       