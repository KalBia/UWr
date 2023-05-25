def podziel(s):
    czy_slowo = False
    slowo = ''
    lista_slow = []
    for znak in s:
        if znak != ' ':
            if not czy_slowo:
                czy_slowo = True
            slowo += znak
        if znak == ' ':
            if czy_slowo:
                czy_slowo = False
                lista_slow.append(slowo)
                slowo = ''
    if slowo != '':
        lista_slow.append(slowo)
    return lista_slow
    
#------------------------------------------------
print(podziel("     Ala      ma          kota      i psa"))