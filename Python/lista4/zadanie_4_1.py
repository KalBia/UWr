#rysunek nr 4
import turtle
import random
from array import array

turtle.speed('fastest')

def krzyzyk(kolor, size):
    turtle.fillcolor(kolor)
    turtle.begin_fill()

    turtle.fd(size*1.5)
    turtle.rt(90)
    turtle.pd()
    for i in range(4):
        turtle.fd(size/2)
        turtle.rt(90)
        turtle.fd(size)
        turtle.lt(90)
        turtle.fd(size)
        turtle.rt(90)
        turtle.fd(size/2)

    turtle.end_fill()
    turtle.pu()

def zmien_kolor(kolor):
    kolorek = array('f', [random.randint(0, 10)/10, random.randint(0, 10)/10, random.randint(0, 10)/10])
    mieszanka = array('f', [0, 0, 0])
    for i in range(3):
        mieszanka[i] = 0.6*kolor[i] + 0.4*kolorek[i]
    return mieszanka

def wieniec(radius, amount, kolor, size):
    turtle.pu()
    for i in range(amount):
        turtle.rt( (360/amount) )
        turtle.fd(radius)
        turtle.rt( 45 + (360/amount)*i )
        krzyzyk(kolor, size)
        kolor = zmien_kolor(kolor)
        turtle.goto(0, 0)
        turtle.lt(135 + (360/amount)*i)
            

#//**********************************
kolor = array('f', [0.8, 1, 0.3])
size = 30
amount = 36
radius = 300

wieniec(radius, amount, kolor, size)

input()