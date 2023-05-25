from collections import defaultdict as dd

#------------------------------------------------

def histogram(slowo):
    hist = dd(lambda: 0)
    for litera in slowo:
        hist[litera] += 1
    return hist

def ukladalne_1_z_2(slowo1, slowo2):
    hist1 = histogram(slowo1)
    hist2 = histogram(slowo2)
    for litera in slowo1:
        if hist2[litera] < hist1[litera]:
            return False
    return True

#------------------------------------------------

print('aktyw, lokomotywa:', ukladalne_1_z_2('aktyw', 'lokomotywa'))
print('kot, lokomotywa:', ukladalne_1_z_2('kot', 'lokomotywa'))
print('kotka, lokomotywa:', ukladalne_1_z_2('kotka', 'lokomotywa'))
print('żak, lokomotywa:', ukladalne_1_z_2('żak', 'lokomotywa'))