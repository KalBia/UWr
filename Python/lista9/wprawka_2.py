txt = """
+ Jaś 20
+ Basia 10
Jaś Małgosia 10
Małgosia Basia 7
Basia Jaś 3
# liczba na dzisiaj: 
"""

liczba = -1
for i in range(10_000_000):
    if '7777777' in str(hash(txt + str(i))):
        liczba = i
        break

if liczba == -1:
    print('NOT FOUND')
else:
    print(liczba, hash(txt + str(liczba)))