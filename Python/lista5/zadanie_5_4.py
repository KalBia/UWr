def usun_duplikaty(tablica):
    tablica = tablica[:]
    for i in range(len(tablica)):
        tablica[i] = [tablica[i]] + [i]
    tablica.sort()
    
    temp = [[tablica[0][1], tablica[0][0]]]
    for i in range(1, len(tablica)):
        if tablica[i][0] != tablica[i-1][0]:
            temp.append([tablica[i][1], tablica[i][0]])
    temp.sort()
    
    result = []
    for element in temp:
        result.append(element[1])
    
    return result

#niech n = len(tablica)
#złożoność czasowa: O(n)
#złożoność pamięciowa: O(n)
#//**********************************
tablica = [5,3,1,4,6,4,9]
print(usun_duplikaty(tablica))