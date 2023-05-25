import math

def czy_pierwsza(n):
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            return False
    return True

def stworz_siodemki(n):
    return n*"7"

def ile_hiper_z_dokladnie_tyle_siodemek(cyfry, siedem):
    ile = 0
    ciag_siodemek = stworz_siodemki(siedem)
    luzne = cyfry - siedem # pozostale poza siodemkami cyfry w liczbie 
    pre = 0 # to bedzie nasz dolny prog prefixu do ciagu siodemek
    
    #generujemy pasujace liczby i sprawdzamy czy sa pierwsze

    for i in range(luzne+1): # robimy tyle razy ile liczba miejsc na ktorych mozna dac ciag siodemek
        post = 10**(luzne-i) # gorny prog postfixu do siodemek
        
        for prefix in range(pre, max(pre*10, 1) ): # generujemy kolejne prefixy (ale dla braku ma sie wykonac min raz petla)
            for postfix in range(0, post): # generujemy kolejne postfixy (a dla braku wykona sie dokladnie raz petla)
                
                liczba = '' # zaczynamy generowac liczbe
                
                if pre != 0:
                    if prefix % 10 == 7: # pre == 0 gdy nie ma prefixu, wiec nie dodajemy nic przed ciag siodemek i jesli nie zwieksza to ciagu siodemek
                        continue
                    else:
                        liczba += str(prefix) # dodajemy prefix

                liczba += ciag_siodemek # dodajemy ciag siodemek
                
                if ( postfix//(post/10) ) % 10 == 7: #jesli nam postfix nie zwieksza ciagu siodemek
                    continue
                else:
                    liczba = int(liczba)*(10**(luzne-i)) + postfix # dodajemy postfix (dla braku nic sie nie zadzieje :D) i odrazu mamy int

                #print("Liczba:", liczba)
                if czy_pierwsza(liczba):
                    print(liczba)
                    ile += 1
        
        if pre == 0:
            pre = 1
        else:
            pre *= 10
    
    return ile

def ile_hiper_dla_min_tyle_siodemek(cyfry, siedem):
    ile = 0
    for i in range(siedem, cyfry+1):
        ile += ile_hiper_z_dokladnie_tyle_siodemek(cyfry, i)
    return ile


#**********************************
C = 10
S = 7
print("HIPERszczesliwych liczb jest:", ile_hiper_dla_min_tyle_siodemek(C, S))


                
                
