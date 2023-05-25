def zbior_sum_podzbiorow_listy(lista):
    if len(lista) == 0:
        return {0}
    
    temp_set = zbior_sum_podzbiorow_listy(lista[1:])
    
    return temp_set | { (lista[0] + t_s) for t_s in temp_set}

#-----------------------------------------------------------------

print(set(sorted(list(zbior_sum_podzbiorow_listy([1,2,3,100])))))

#-----------------------------------------------------------------

def ciagi_niemalejace(dlugosc, od_A, do_B):
    if dlugosc == 0:
        return [[]]
    
    temp_ciagi = ciagi_niemalejace(dlugosc-1, od_A, do_B)
    
    return [ciag + [element] for element in range(od_A, do_B) for ciag in temp_ciagi if len(ciag) == 0 or element >= ciag[-1]]

# NOTATKA: newlist = [expression for item in iterable if condition == True] --> if po for!
#-----------------------------------------------------------------

print(ciagi_niemalejace(3, 4, 12))