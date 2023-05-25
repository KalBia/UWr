stan_kont = {}

for wiersz in open('/home/kalina/Python/9/transakcje.txt'):
    wiersz = wiersz.split()
    if wiersz[0] == '#':
        continue
    elif len(wiersz[0]) > 1:
        kto, komu, ile = wiersz
        if kto not in stan_kont:
            stan_kont[kto] = 0
        if komu not in stan_kont:
            stan_kont[komu] = 0
        stan_kont[kto] -= int(ile)
        stan_kont[komu] += int(ile)
    else: #wiersz[0] == '+'
        znak, kto, ile = wiersz
        if kto not in stan_kont:
            stan_kont[kto] = 0
        stan_kont[kto] += int(ile)

najbogacz = sorted(stan_kont.keys(), key=stan_kont.get, reverse=True)[0]    
print(najbogacz, stan_kont[najbogacz])