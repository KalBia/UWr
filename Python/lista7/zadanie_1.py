from turtle import *

#-----------------------------------------------------------------------------------

tracer(0, 1)
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
    
def obrazek(bok, sx, sy):
    piksele = wczytaj_wiersze()
    ssx = sx
    for wiersz in piksele:
        for piksel in wiersz:
            move(ssx, sy, bok)
            kwadrat(bok, piksel)
            ssx += 1
        sy -= 1
        ssx = sx
    input()

#-----------------------------------------------------------------------------------

obrazek(2, 0, 0)