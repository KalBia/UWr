#----------------------------------------------------

def eval_string(expr):
    pojedyncze = expr.split()
    stopienADD = []
    arg1 = int(pojedyncze[0])
    for indeks in range(2, len(pojedyncze), 2):
        dzialanie = pojedyncze[indeks-1]
        arg2 = int(pojedyncze[indeks])
        if dzialanie == '+':
            stopienADD.append(arg1)
            arg1 = arg2
        elif dzialanie == '-':
            stopienADD.append(arg1)
            arg1 = (-1)*arg2
        elif dzialanie == '//':
            arg1 = arg1//arg2
        elif dzialanie == '*':
            arg1 = arg1*arg2
    stopienADD.append(arg1)

    wynik = 0
    for skladnik in stopienADD:
        wynik += skladnik
    
    return wynik

#---------------------------------------------------

expr = '4 // 3 + 1 - 5 * 2'
print('dobry wynik:', eval(expr))
print('mój wynik:', eval_string(expr))