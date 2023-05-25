import time
import turtle as tr
import datetime

#tr.speed('fastest')
#//**********************************
def czesc_tarczy(radius):
    tr.pu()
    tr.fd(radius)

    tr.pd()
    tr.pensize(2)
    tr.rt(180)
    tr.fd(radius/10)
    tr.pensize(1)
    
    tr.pu()
    tr.fd( (9*radius)/10 )
    tr.rt(180)

    for i in range(5):
        tr.pu()
        tr.rt(6)
        tr.fd(radius)
        
        tr.pd()
        tr.rt(180)
        tr.fd(radius/20)

        tr.pu()
        tr.fd( (19*radius)/20 )
        tr.rt(180)

def tarcza(radius):
    for i in range(12):
        czesc_tarczy(radius)

#//**********************************
def godzinowa(godzina, minuta, sekunda, lenG):
    tr.pd()
    kat = 30*(godzina % 12) + 0.5*minuta + sekunda*(30/360)
    tr.rt(kat)
    tr.pensize(5)
    tr.fd(lenG)
    tr.rt(180)
    tr.fd(lenG)
    tr.lt(180 + kat)
    tr.pu()

def minutowa(minuta, sekunda, lenM):
    tr.pd()
    kat = 6*minuta + sekunda*(6/60)
    tr.rt(kat)
    tr.pensize(5)
    tr.fd(lenM)
    tr.rt(180)
    tr.fd(lenM)
    tr.lt(180 + kat)
    tr.pu()

def sekundowa(sekunda, lenS):
    tr.pd()
    kat = 6*sekunda
    tr.rt(kat)
    tr.pensize(3)
    tr.pencolor('aqua')
    tr.fd(lenS)
    tr.rt(180)
    tr.fd(lenS)
    tr.lt(180 + kat)
    tr.pu()
    tr.pencolor('black')

#//**********************************
def zegar(godzina, minuta, sekunda, radius):
    lenG = 2*radius/5
    lenM = 3*radius/4
    lenS = 6*radius/7

    tarcza(radius)

    godzinowa(godzina, minuta, sekunda, lenG)
    minutowa(minuta, sekunda, lenM)
    sekundowa(sekunda, lenS)

#//**********************************
def aktualny_zegar(radius):
    tr.tracer(0,0)
    current_time = datetime.datetime.now()
    godzina = current_time.hour
    minuta = current_time.minute
    sekunda = current_time.second

    zegar(godzina, minuta, sekunda, radius)

def animacja_zegara(radius):
    for i in range(10**6):
        time.sleep(0.95)
        tr.clear()
        aktualny_zegar(radius)
        tr.update()

#//**********************************
radius = 300

tr.lt(90)
animacja_zegara(radius)

input()