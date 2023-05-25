slowa = set(open('popularne_slowa.txt').read().split())
pasujace = set()

def wspak(wyraz):
    return wyraz[::-1]

def palindrom(wyraz):
    if wyraz == wyraz[::-1]:
        return True
    return False

def pary_liczb_wzajemnie_odwrotnych():
    for wyraz in slowa:
        if wyraz not in pasujace and not palindrom(wyraz):
            if wspak(wyraz) in slowa:
                print(wyraz, wspak(wyraz))
                pasujace.update([wyraz, wspak(wyraz)])
                
#-----------------------------------------------------------------

pary_liczb_wzajemnie_odwrotnych()