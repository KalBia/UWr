from turtle import *
from duze_cyfry import daj_cyfre
from array import array
from random import randint

tracer(0,1)

def kwadrat(bok, kolor):
    fillcolor(kolor)
    begin_fill()
    for i in range(4):
        fd(bok)
        rt(90)
    end_fill()

def drukuj(liczba):
    penup()
    x = -350
    y = 250
    liczba = str(liczba)
    kolory = []
    for i in range(len(liczba)):
        kolor = array('f', [randint(0,99)/100, randint(0,99)/100, randint(0,99)/100])
        kolory.append(kolor)
    bok = 15
    
    for i in range(5):
        goto(x, y)
        c = 0
        for cyfra in liczba:
            cyfra = daj_cyfre(int(cyfra))[i]
            for znak in cyfra:
                if znak == '#':
                    pendown()
                    kwadrat(bok, kolory[c])
                    fd(bok)
                if znak == ' ':
                    penup()
                    fd(bok)
            c += 1
            penup()
            fd(bok/2)
        y -= bok
            
        penup()
        rt(180)
        fd(bok*(len(liczba)-1))
        lt(90)
        fd(bok)
        lt(90)
            
#//**********************************
drukuj(340152)
input()