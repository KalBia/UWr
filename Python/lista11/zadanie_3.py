
#----------------------------------------------------------------

def nie_slowo(slowo):
    slowo = slowo.lower()
    for znak in slowo:
        if znak in 'abcdefghijklmnoprstuvwyz':
            return False
    return True        

def liczenie_dla_okregow():
    komitety = []
    ostateczne = {}
    
    for wiersz in open(r'C:\Users\ka03l\OneDrive\studia\semestr 1\Python\lista11\wyniki_wyborow.tsv', encoding='utf-8'):
        wiersz = wiersz.split()
        glosy = {}
        if len(wiersz) > 1:
            if wiersz[0] == 'NR':
                for i in range(3, len(wiersz)-1):
                    komitety.append(wiersz[i])
                    ostateczne[wiersz[i]] = 0
            else:
                i = 2
                if not nie_slowo(wiersz[i]):
                    i = 3
                
                mandaty = int(wiersz[i])
                for j in range(i+1, len(wiersz)-1):
                    if wiersz[j] != '-':
                        glosy[komitety[j-i-1]] = float(wiersz[j])
                    else:
                        glosy[komitety[j-i-1]] = 0
                
                ilorazy = tworzenie_tabeli_ilorazow(glosy, mandaty, komitety)
                wyniki = przydzial_mandatow(ilorazy, mandaty)
                
                for komitet in komitety:
                    if komitet not in wyniki:
                        wyniki[komitet] = 0
                
                for komitet in komitety:
                    ostateczne[komitet] += wyniki[komitet]
                
    return ostateczne

def tworzenie_tabeli_ilorazow(glosy, mandaty, komitety):
    tabela = [(glosy[komitet]/i, komitet) for i in range(1, mandaty) for komitet in komitety]
    return sorted(tabela, reverse=True)

def przydzial_mandatow(ilorazy, mandaty):
    wyniki = {}
    ilorazy = ilorazy[:mandaty]
    for mandat in ilorazy:
        if mandat[1] not in wyniki:
            wyniki[mandat[1]] = 0
        wyniki[mandat[1]] += 1
    return wyniki

def wypisz_wyniki(wyniki):
    for komitet in wyniki:
        print(komitet + ': ' + str(wyniki[komitet]))
        
def wybory():
    wyniki = liczenie_dla_okregow()
    wypisz_wyniki(wyniki)
            
#----------------------------------------------------------------

wybory()