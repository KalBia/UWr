from math import log

def silnia(n):
  result = 1
  for i in range(1, n+1):
    result *= i
  return result

def ile_cyfr(n):
  return len(str(n))
  #drugi sposob: return int(log(n)/log(10))

def odmiana(n):
  if n % 100 < 15:
    if n % 100 > 11:
      print("cyfr")
      return 
  m = n % 10
  if m < 5:
    if m > 1:
      print("cyfry")
      return
  print("cyfr")
  return
  
for i in range(4, 101):
  print(f"{i}! ma ", end="")
  x = ile_cyfr(silnia(i))
  print(x, end=" ")
  odmiana(x)