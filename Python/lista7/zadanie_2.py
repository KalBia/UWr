from turtle import *
import random

#-----------------------------------------------------------------------------------

speed('fastest')
colormode(255)

#-----------------------------------------------------------------------------------

def wczytaj_wiersze():
    piksele_wiersze = open("niespodzianka.txt").readlines()
    Pwiersze = []
    for wiersz in piksele_wiersze:
        wiersz = wiersz.split()
        wiersz_roboczy = []
        for piksel in wiersz:
            wiersz_roboczy.append(eval(piksel))
        Pwiersze.append(wiersz_roboczy)
    return Pwiersze

def kwadrat(bok, kolor):
    fillcolor(kolor)
    pencolor(kolor)
    begin_fill()
    pendown()
    
    for i in range(4):
        fd(bok)
        rt(90)
    
    penup()
    end_fill()

def move(x, y, bok):
    penup()
    goto(bok*x, bok*y)
    pendown()
    
def generuj_dane(piksele, sx, sy):
    dane = []
    ssx = sx
    for wiersz in piksele:
        for piksel in wiersz:
            dane.append([ssx, sy, piksel])
            ssx += 1
        sy -= 1
        ssx = sx
    return dane

def kombinacja_danych(dane):
    n = len(dane)
    for i in range(n):
        zmiana = random.randint(0, n-1)
        dane[i], dane[zmiana] = dane[zmiana], dane[i]
    return dane
    
def obrazek(bok, sx, sy):
    piksele = wczytaj_wiersze()
    dane = generuj_dane(piksele, sx, sy)
    dane = kombinacja_danych(dane)
    for pozycja in dane:
        move(pozycja[0], pozycja[1], bok)
        kwadrat(bok, pozycja[2])
    
    input()

#-----------------------------------------------------------------------------------

obrazek(2, 0, 0)