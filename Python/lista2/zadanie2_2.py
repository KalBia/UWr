def pozioma_linia_gwiazdki(n):
    N = 2*n+1
    print(N*"*")

def pion_i_przekatne(n):
    N = 2*n+1
    y = N//2-1
    #pierwsza "polowa" koperty
    for i in range(0, y):
        print("*" + (i * " ") + "*" + (N-4-2*i)*" " + "*" + (i * " ") + "*")
    #"srodek" koperty
    print("*" + (y * " ") + "*" + (y * " ") + "*")
    #druga "polowa" koperty
    for i in range(0, y):
        x = (N//2-1)-1-i
        print("*" + (x * " ") + "*" + (N-4-2*x)*" " + "*" + (x * " ") + "*")


def koperta(n):
    pozioma_linia_gwiazdki(n)
    pion_i_przekatne(n)
    pozioma_linia_gwiazdki(n)

koperta(4)
