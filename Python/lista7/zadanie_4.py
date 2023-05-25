from turtle import *
import numpy as np
from random import *

#-----------------------------------------------------------

ht()
kolor = np.random.rand(3)
color('black', kolor)
tracer(0,0)

#-----------------------------------------------------------

def kwadrat(bok):
    begin_fill()
    for i in range(4):
      fd(bok)
      rt(90)
    end_fill()
    
def murek(s,bok,kolor):
  G = 1
  kolory_gradientu = [np.array([1, 1, 0.5]), np.array([0.5, 1, 1]), np.array([1, 0.5, 1]), kolor]
  gradient = kolory_gradientu[0]
  i = 0
  for a in s:
     if a == 'f':
         kwadrat(bok)
         fd(bok)
     elif a == 'b':
         kwadrat(bok)
         fd(bok)         
     elif a == 'l':
         bk(bok)
         lt(90)
     elif a == 'r':
        rt(90)
        fd(bok)
     elif a == 'c':
        kolor = np.random.rand(3)
        color('black', kolor)
     elif a == 'g':
        alfa = G/15
        kolor = (1- alfa)*kolor + alfa*gradient
        color('black', kolor)
        G += 1
        if G > 15:
            G -= 14
            i = (i + 1) % 4
            gradient = kolory_gradientu[i]
            
def kwadrator(bok):
    napis = ''
    zmiana_koloru = 0
    for i in range(4):
        for j in range(bok):
            if zmiana_koloru == 1:
                napis += 'c'
            zmiana_koloru = (zmiana_koloru + 1) % 2
            napis += 'f'
        napis += 'r'
    return napis

def spirala(max_bok):
    napis = 'gfgr'
    for i in range(1, max_bok+1):
        for j in range(i):
            napis += 'fg'
        napis += 'r'
    return napis

#-----------------------------------------------------------
  
#rysunek nr 1     
murek(kwadrator(10), 10, kolor)

#move
penup()
goto(-100, 100)
pendown()

#rysunek nr 2
murek(spirala(10), 10, kolor)

#-----------------------------------------------------------

update()
input()