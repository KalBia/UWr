def permutacyjna_postac_normalna(slowo):
    slownik = {}
    obecna_liczba = 1
    reprezentacja = ''
    for znak in slowo:
        if znak not in slownik:
            slownik[znak] = str(obecna_liczba)
            obecna_liczba += 1
        reprezentacja += slownik[znak] + '-'
    return reprezentacja[:-1]

#----------------------------------------------------------------

print(permutacyjna_postac_normalna('indianin'))