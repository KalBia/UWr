def krzyzyk(n):
  for i in range(n):
    print(n * " ", end="")
    print(n * "*", end="")
    print(n * " ")
  for i in range(n):
    print((3*n) * "*")
  for i in range(n):
    print(n * " ", end="")
    print(n * "*", end="")
    print(n * " ")

krzyzyk(4)