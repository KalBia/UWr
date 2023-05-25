from losowanie_fragmentow import losuj_fragment


def losuj_haslo(n):
  haslo = ""
  while n > 5:  # bo z 5 juz mozemy skoczyc odrazu na 1 i wtedy nic nie mozemy juz zrobic :c
    frag = losuj_fragment()
    n -= len(frag)
    haslo += frag
  if n == 4:
    while n > 0:
      frag = losuj_fragment()
      if len(frag) == 2:
        n -= len(frag)
        haslo += frag
      elif len(frag) == 4:
        if n > 2:
          n -= len(frag)
          haslo += frag
  elif n == 3:
    frag = losuj_fragment()
    while len(frag) != 3:
      frag = losuj_fragment()
    haslo += frag
  elif n == 2:
    frag = losuj_fragment()
    while len(frag) != 2:
      frag = losuj_fragment()
    haslo += frag
  else:  # czyli n == 5
    frag = losuj_fragment()
    while len(frag) == 4:
      frag = losuj_fragment()
    if len(frag) == 3:
      haslo += frag
      while len(frag) != 2:
        frag = losuj_fragment()
      haslo += frag
    elif len(frag) == 2:
      haslo += frag
      while len(frag) != 3:
        frag = losuj_fragment()
      haslo += frag
  return haslo


for i in range(10):
  print(losuj_haslo(8))

for i in range(10):
  print(losuj_haslo(12))
