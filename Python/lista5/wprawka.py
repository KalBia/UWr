from turtle import *

tracer(0,1)

colors = {
   'r' : 'red', 
   'g' : 'green', 
   'b' : 'blue',
   'y' : 'yellow',
   'o' : 'orange', 
}

def kwadrat(bok, kolor, kacik):
    rt(kacik)
    fillcolor(kolor)
    begin_fill()
    fd(bok/2)
    rt(90)
    pendown()
    
    for i in range(4):
        fd(bok/2)
        rt(90)
        fd(bok/2)

    penup()
    rt(90)
    fd(bok/2)
    rt(180)
    lt(kacik)
    end_fill()
    
def kolo_kwad(slowo, promien):
    dl = len(slowo)
    kat = 360/dl
    kacik = 5
    bok = 25
    promyczek = promien/3
    for litera in slowo:
        penup()
        fd(promyczek)
        kwadrat(bok, colors[litera], kacik)
        rt(180)
        fd(promyczek)
        rt(180)
        rt(kat)
    rt(180)
    fd(promien)
    rt(180)

def rysuj(dane):
    dlug = len(dane)
    KAT = 360/dlug
    promien = 125
    for slowo in dane:
        kolo_kwad(slowo, promien)
        rt(KAT)

#//**********************************
dane_o_rysunku = ['bobby' + 'bobby'+ 'bobby', 'rybogryby', 'grrrrrry', 'yo' * 10] * 2
rysuj(dane_o_rysunku)
input()