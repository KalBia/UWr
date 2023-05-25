def od_bialego_pola(n, k):
    for i in range(0,k):
        print( n * ( (k*" ") + (k*"#")) )

def od_czarnego_pola(n, k):
    for i in range(0,k):
        print( n * ( (k*"#") + (k*" ")) )

def szachownica(n, k):
    for i in range(0, n):
        od_bialego_pola(n, k)
        od_czarnego_pola(n, k)

szachownica(4, 3)