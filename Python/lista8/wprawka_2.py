M1, M2, M3 = 0, 0, 0
c = 0
for w in open('input.txt'):
    if w != '\n':
        c += int(w)
    else:
        if M1 < c:
            M1, M2, M3 = c, M1, M2
        elif M2 < c:
            M2, M3 = c, M2
        elif M3 < c:
            M3 = c
        c = 0

if M1 < c:
    M1, M2, M3 = c, M1, M2
elif M2 < c:
    M2, M3 = c, M2
elif M3 < c:
    M3 = c

print(M1+M2+M3)