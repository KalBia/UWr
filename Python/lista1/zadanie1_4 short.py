from losowanie_fragmentow import losuj_fragment


def losuj_haslo(n):
  haslo = ""
  while len(haslo) != n:
    frag = losuj_fragment()
    l = len(haslo) + len(frag)
    if l < n-1 or l == n:
      haslo += frag
  return haslo


for i in range(10):
  print(losuj_haslo(8))

for i in range(10):
  print(losuj_haslo(12))
