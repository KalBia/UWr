def sito_erastotenesa(n):
    sito = [1 for i in range(n+1)]
    sito[0] = 0
    sito[1] = 0

    i = 2
    while i <= n:
        k = 2
        while k*i <= n:
            sito[k*i] = 0
            k += 1
        i += 1
        while i <= n and sito[i] == 0:
            i += 1
    return sito

def czy_palindrom(n):
    n = str(n)
    answer = True
    for i in range(len(n)//2):
        if n[i] != n[-(i+1)]:
            answer = False
            break
    return answer

def palindromy(a, b):
    result = []
    sito = sito_erastotenesa(b)
    for i in range(a, b+1):
        if czy_palindrom(i) and sito[i] == 1:
            result.append(i)
    return result

#//**********************************

print(palindromy(7, 1000))