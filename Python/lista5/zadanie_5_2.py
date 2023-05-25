#rysunek: lista 4, obrazek 8
from turtle import *
from math import pi

speed('fastest')

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
    
def rosnaco(dlugosc, liczba_sekwencji, promien, rosnie):
    kolory = ['red', 'orange', 'green', 'blue']
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
    
    kolor = 'yellow'
    kolo(liczba_sekwencji, promien, szerokosc, kat, kolor)
            
#//**********************************
rosnaco(10, 9, 50, 5)

input()