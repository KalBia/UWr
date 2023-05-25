# Kalina Białek
# lista nr 1: zadanie 2 oraz zadanie 3
# VSCODE Python: v2023
#--------------------------------------------------
#--------------------------------------------------
#--------------------------------------------------
# [ ZADANIE 3 ]
#--------------------------------------------------

def NewTable():
    return [ [], None, None ] # tablica, min indeks, max indeks

# domyślną wartością w tablicy będzie zero
def add_to_table(position, value, T):
    # jeśli to pierwszy element
    if T[1] == None:
        T[0] = [0]
        T[1] = position
        T[2] = position
    # jeśli indeks jest poza naszym zakresem indeksów (poniżej)
    elif position < T[1]: 
        T[0] = [0 for i in range(T[1] - position)] + T[0]
        T[1] = position
    # jeśli indeks jest poza naszym zakresem indeksów (powyżej)
    elif position > T[2]:
        T[0] = T[0] + [0 for i in range(position - T[2])]
        T[2] = position
    # zapewniliśmy już, że mamy indeks 'position' w naszym zakresie, więc wstawiamy 'value' 
    # przesuwamy jedynie indeks 'position' do indeksowania od 0
    T[0][position - T[1]] = value

def get_from_table(position, T):
    # jeśli pozycja w zakresie indeksów tablicy
    if position >= T[1] and position <= T[2]:
        return T[0][position - T[1]]
    print("Nie ma takiego indeksu")
    return None

def show_table(T):
    L = T[2] - T[1] + 1
    indeks = T[1]
    
    print("TABLICA:")
    for i in range(L):
        print(indeks, ': ', T[0][i])
        indeks += 1
    
#--------------------------------------------------
# [ TESTOWANIE ZADANIA 3 ]
#--------------------------------------------------
"""
print('Testy funkcji NewTable')
T = NewTable()
print(T, '\n')

#----------------

print('Testy funkcji add_to_table')
add_to_table(3, 11, T)
print(T, '\n')
add_to_table(-2, 17, T)
print(T, '\n')
add_to_table(1, 19, T)
print(T, '\n')

#----------------

print('Testy funkcji get_from_table')
print(get_from_table(0, T))
print(get_from_table(1, T))
print(get_from_table(-2, T))
print(get_from_table(-7, T), '\n')

#----------------

print('Testy funkcji show_table')
show_table(T)
print(3*'\n')
"""
#--------------------------------------------------
# [ ZADANIE 2 ] # zakładam/dodaję do specyfikacji, że użytkownik podaje prawidłowe dane - typu int oraz 
# licznik i mianownik != 0
#--------------------------------------------------

def strukt_ulamek(p, q):
    return [int(p), int(q)]

def nwd(p, q):
    if q > 0:
        return nwd(q, p%q)
    return p

def NowyUlamek(num, denom):
    #upraszczamy ułamek
    t = -1
    if num*denom < 0:
        if num < 0:
            num *= -1
        else:
            denom *= -1
        t = 1
    if num < 0 and denom < 0:
        num *= -1
        denom *= -1
    n = nwd(num, denom)
    num /= n
    denom /= n
    #tworzymy ułamek
    return strukt_ulamek( t*(-1) * int(num), int(denom))

def show_ulamek(U):
    print(U[0], '/', U[1])
    
def add1(U, V):
    n = nwd(abs(U[1]), abs(V[1]))
    v = (U[1] * V[1]) / n # to jest NWW
    u = U[0] * (V[1]/n) + V[0] * (U[1]/n) # czyli licznik to suma rozszerzonych o brakujące czynniki mianowników
    return strukt_ulamek(u, v)

def add2(U, V):
    n = nwd(abs(U[1]), abs(V[1]))
    v = (U[1] * V[1]) / n # to jest NWW
    u = U[0] * (V[1]/n) + V[0] * (U[1]/n) # czyli licznik to suma rozszerzonych o brakujące czynniki mianowników
    m = nwd(abs(u), abs(v))
    if u < 0 and v < 0:
        u *= -1
        v *= -1
    V[0] = int(u / m)
    V[1] = int(v / m)
    return V

def sub1(U, V):
    n = nwd(abs(U[1]), abs(V[1]))
    v = (U[1] * V[1]) / n # to jest NWW
    u = U[0] * (V[1]/n) - V[0] * (U[1]/n) # czyli licznik to suma rozszerzonych o brakujące czynniki mianowników
    return strukt_ulamek(u, v)

def sub2(U, V):
    n = nwd(abs(U[1]), abs(V[1]))
    v = (U[1] * V[1]) / n # to jest NWW
    u = U[0] * (V[1]/n) - V[0] * (U[1]/n) # czyli licznik to suma rozszerzonych o brakujące czynniki mianowników
    m = nwd(abs(u), abs(v))
    if u < 0 and v < 0:
        u *= -1
        v *= -1
    V[0] = int(u / m)
    V[1] = int(v / m)
    return V

def mult1(U, V):
    u = U[0] * V[0]
    v = U[1] * V[1]
    return NowyUlamek(u, v)

def mult2(U, V):
    u = U[0] * V[0]
    v = U[1] * V[1]
    n = nwd(abs(u), abs(v))
    if u < 0 and v < 0:
        u *= -1
        v *= -1
    V[0] = int(u / n)
    V[1] = int(v / n)
    return V

def div1(U, V):
    u = U[0] * V[1]
    v = U[1] * V[0]
    return NowyUlamek(u, v)

def div2(U, V):
    u = U[0] * V[1]
    v = U[1] * V[0]
    n = nwd(abs(u), abs(v))
    if u < 0 and v < 0:
        u *= -1
        v *= -1
    V[0] = int(u / n)
    V[1] = int(v / n)
    return V

#--------------------------------------------------
# [ TESTOWANIE ZADANIA 2 ]
#--------------------------------------------------
"""
print('Testy funkcji strukt_ulamek')
print(strukt_ulamek(2, 3))
print(strukt_ulamek(2, 6), '\n')

#---------------

print('Testy funkcji NowyUlamek')
print(NowyUlamek(2, 3))
print(NowyUlamek(2, 6))
print(NowyUlamek(2, 8))
print(NowyUlamek(2, -4))
print(NowyUlamek(-2, -4))
print(NowyUlamek(-2, 4))
print(NowyUlamek(60, 150), '\n')

#---------------

print('Testy funkcji show_ulamek')
show_ulamek(NowyUlamek(2, 3))
show_ulamek(NowyUlamek(2, 8))
show_ulamek(NowyUlamek(60, 150))
print()

#---------------

print('Testy funkcji z operacjami')
print(add1(NowyUlamek(2, 3), NowyUlamek(2, 8)))
print(add2(NowyUlamek(2, 3), NowyUlamek(2, 8)))
print()
print(sub1(NowyUlamek(2, 3), NowyUlamek(2, 8)))
print(sub2(NowyUlamek(2, 3), NowyUlamek(2, 8)))
print()
print(mult1(NowyUlamek(2, 3), NowyUlamek(-2, 8)))
print(mult2(NowyUlamek(2, 3), NowyUlamek(-2, 8)))
print()
print(div1(NowyUlamek(-2, 3), NowyUlamek(2, -8)))
print(div2(NowyUlamek(-2, 3), NowyUlamek(2, -8)))
"""