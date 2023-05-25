#pierwszy obrazek z P3.4(1)
import random
import turtle

turtle.speed('fastest')
turtle.pencolor('black')

def kwiatek_pojedynczy():
    glowna = random.randint(50, 70)
    ile = random.randint(3, 11)

    turtle.fd(glowna)
    for i in range(ile):
        mniejsze = random.randint(10, 20)
        turtle.fd(mniejsze)
        turtle.rt(180)
        turtle.fd(mniejsze)
        turtle.rt(180 + 360/ile)
    turtle.rt(180)
    turtle.fd(glowna)

def kwiatek_mnogi():
    glowna = random.randint(200, 300)
    ile = random.randint(3, 11)

    turtle.fd(glowna)
    for i in range(ile):
        kwiatek_pojedynczy()
        turtle.rt(180 + 360/ile)
    turtle.rt(180)
    turtle.fd(glowna)

def pek_kwiatkow():
    ile = random.randint(3, 11)

    for i in range(ile):
        kwiatek_mnogi()
        turtle.rt(180 + 360/ile)

#**********************************

pek_kwiatkow()
input("Koniec rysowania! [press enter to quit]")