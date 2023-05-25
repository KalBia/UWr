#specyfikacja: n jest nieparzyste [moge tak zalozyc wedlug tresci zadania]
def suma_kwadratow(n, k):
    return n**2 + k**2

def policz_prog(n):
    n = n//2 + 0.5
    return n**2

def kolko(n):
    prog = policz_prog(n) #zebysmy nie musieli pierwiastkowac w obliczaniu odleglosci od "srodka"
    X = n//2 #czyli nasz "srodek kolka" ma wspolrzedne (X,X)
    for i in range(n):
        for j in range(n):
            #przechodzac kolejno po kazdym polu sprawdzamy odleglosc i decydujemy czy malujemy pole
            x = abs(i - X)
            y = abs(j - X)
            sumka = suma_kwadratow(x, y)
            if sumka <= prog:
                print("#", end="")
            else:
                print(" ", end="")
        print()

def kolko_balwanek(n, N): #gdzie n to wymiary kolka a N to wymiary najwiekszej czesci balwanka
    prog = policz_prog(n)
    X = n//2
    for i in range(n):
        przesun = (N-n)//2 #przesuwamy o tyle w prawo, by byl rowny balwanek (np - np = parz)
        print(przesun*" ", end="")
        for j in range(n):
            x = abs(i - X)
            y = abs(j - X)
            sumka = suma_kwadratow(x, y)
            if sumka <= prog:
                print("#", end="")
            else:
                print(" ", end="")
        print()

def balwanek(a, b, c): #specyfikacja: a < b < c
    kolko_balwanek(a, c)
    kolko_balwanek(b, c)
    kolko_balwanek(c, c)

balwanek(7, 9, 15)
