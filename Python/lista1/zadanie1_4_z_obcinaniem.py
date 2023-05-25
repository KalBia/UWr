from losowanie_fragmentow import losuj_fragment


def losuj_haslo(n):
  x = n
  haslo = ""
  while x > 0:
    frag = losuj_fragment()
    x -= len(frag)
    haslo += frag
  return haslo
  
for i in range(10):
  s = losuj_haslo(8)
  print(s[0:8])

for i in range(10):
  s = losuj_haslo(12)
  print(s[0:12])
