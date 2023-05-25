import random
from duze_cyfry import daj_cyfre
from turtle import *
import numpy as np

tracer(0, 1)

def kwadrat(wielkosc, x, y, kolor):
    penup()
    goto(wielkosc*x, wielkosc*y)
    
    pendown()
    fillcolor(kolor)
    begin_fill()
    
    for i in range(4):
        fd(wielkosc)
        rt(90)
    
    end_fill()
    penup()
    
def pola_cyfry(cyfra, sx, sy):
    x = sx
    y = sy
    nowe = set()
    for i in range(5):
        x = sx
        wiersz = daj_cyfre(cyfra)[i]
        for element in wiersz:
            if element == '#':
                nowe |= {(x, y)}
            x += 1
        y -= 1
    return nowe

def gen_kolory():
    kolory = []
    for i in range(7):
        kolory.append(np.random.rand(3)) #[random.randint(0, 100)/100, random.randint(0, 100)/100, random.randint(0, 100)/100])
    return kolory

def mozaika(liczba_cyfr, wielkosc):
    uzyte = set()
    kolory = gen_kolory()
    for i in range(liczba_cyfr):
        sx = random.randint(-20, 20)
        sy = random.randint(-20, 20)
        cyfra = random.randint(0, 9)
    
        nowe = pola_cyfry(cyfra, sx, sy)
        
        if len(nowe&uzyte) == 0:
            uzyte |= nowe
            kolor = kolory[random.randint(0, 6)]
            for element in nowe:
                x, y = element
                kwadrat(wielkosc, x, y, kolor)
                
#//**********************************
mozaika(800, 20)
input()