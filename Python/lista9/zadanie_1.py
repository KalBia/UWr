from turtle import *

#---------------------------------------------

tracer(0,0)
#speed('fastest')
#speed('slowest')
color('cyan')

#---------------------------------------------

def trojkat(bok):
    begin_fill()
    for i in range(3):
        fd(bok)
        lt(120)
    end_fill()

def sierpinski(stopien, bok):
    if stopien == 0:
        trojkat(bok)
        return
    
    for i in range(3):
        sierpinski(stopien-1, bok/2)
        fd(bok)
        lt(120)
        
#--------------------------------------------

bok = 300
stopien = 5
penup()
goto(-(bok/2), -(bok/2))
pendown()
sierpinski(stopien, bok)
update()
input()