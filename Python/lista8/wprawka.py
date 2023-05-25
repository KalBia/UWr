M = 0
c = 0
for w in open('input.txt'):
    if w != '\n':
        c += int(w)
    else:
        M = max(M, c)
        c = 0
M = max(M, c)
print(M)