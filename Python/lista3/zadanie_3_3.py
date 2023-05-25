def usun_w_nawiasach(s):
    pocz = -1
    kon = -1
    i = 0
    s = s.split()
    preslowo = ''

    for slowo in s:
        for znak in slowo:
            if znak == '(':
                pocz = i
            elif znak == ')':
                kon = i
            elif znak == '-' and slowo != preslowo and len(slowo) != 1 and slowo[i+1] == '(':
                s.insert(i, '-')
                i += 1
                preslowo = slowo
            elif (znak == '!' or znak == '?' or znak == '.') and slowo[-2] == ')':
                if len(slowo) != 1 and znak == slowo[-1]:
                    s.insert(i+1, znak)
                    i += 1
        
        if pocz != -1 and kon != -1:
            s[pocz:kon+1] = []
            pocz = -1
            kon = -1
        
        i += 1   
    
    s = " ".join(s)
    
    return s

def testowe_wywolania():
    print("TEST 1")
    s = "Ala ma kota (perskiego)!"
    print(usun_w_nawiasach(s))
    
    print("TEST 2")
    s = "-Miecz. (Na plecach.) Dlaczego masz na plecach (miecz)?"
    print(usun_w_nawiasach(s))
    
    print("TEST 3")
    s = "-(Bo) wios³o mi ukradli."
    print(usun_w_nawiasach(s))

testowe_wywolania()    