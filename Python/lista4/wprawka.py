import turtle as tr

tr.speed('fastest')
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
def godzinowa(godzina, minuta, lenG):
    tr.pd()
    kat = 30*(godzina % 12) + 0.5*minuta
    tr.rt(kat)
    tr.pensize(5)
    tr.fd(lenG)
    tr.rt(180)
    tr.fd(lenG)
    tr.lt(180 + kat)
    tr.pu()

def minutowa(minuta, lenM):
    tr.pd()
    kat = 6*minuta
    tr.rt(kat)
    tr.pensize(5)
    tr.fd(lenM)
    tr.rt(180)
    tr.fd(lenM)
    tr.lt(180 + kat)
    tr.pu()

#def sekundowa(sekunda, lenS):


#//**********************************
def zegar(godzina, minuta, sekunda, radius):
    lenG = 2*radius/5
    lenM = 3*radius/4
    #lenS = 6*radius/7

    tarcza(radius)
    tr.lt(90)

    godzinowa(godzina, minuta, lenG)
    minutowa(minuta, lenM)
    #sekundowa(sekunda, lenS)

#//**********************************
radius = 300
godzina = 15
minuta = 37
sekunda = 45

zegar(godzina, minuta, sekunda, radius)

input()