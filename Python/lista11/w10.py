######################################
#  drzewka.py
######################################

# Drzewo: ()
#         (n, lewe_podrzewo, prawe_podddrzewo)


def add_to_tree(e, tree):
    if tree == ():
        return (e, (), ())
    n, left, right = tree
    if e == n:
        return tree
    if e < n:
        new_left = add_to_tree(e, left)
        return (n, new_left, right)
    # e > n
    new_right = add_to_tree(e, right)
    return (n, left, new_right)    
    
def list_to_tree(L):
    t = ()
    for e in L:
        t = add_to_tree(e, t)
    return t    
    


def print_tree(tree, indent=0):
    if tree == ():
        print (indent * ' ' + '()')
        return 
    n, left, right = tree
    print (' ' * indent, n, sep='')
    print_tree(left, indent + 3)
    print_tree(right, indent + 3)
        
   
def in_tree(tree, e):
    if tree == ():
        return False
    n, left, right = tree
    if e == n:
        return True
    if e < n:
        return in_tree(left, e)
    return in_tree(right, e)
    
    
    
def tree_to_list(tree):
    if tree == ():
        return []
    n, left, right = tree
    left_list = tree_to_list(left)
    right_list = tree_to_list(right)
    #return [n] + left_list + right_list # preorder
    return left_list + [n] + right_list
 

                                    

t = list_to_tree([6,3,4,8,77,12,1,2,3,14,6])  
#for i in range(10):
#    print (i, in_tree(t, i))

print_tree(t)
    
#print (tree_to_list(list_to_tree(tree_to_list(t))))    

print (tree_to_list(t))


######################################
#  parametry.py
######################################

# przekazywanie parametrów

"""
def f1(a, b, c=13):
    print ('f1', a, b, c)
    
#f1(10)
f1(10, 20)
f1(10, 20, 30) 
f1(1,2,3,4)
"""

def f2(a, b, c=13, d=55):
    print ('f2', a, b, c, d)



def f2(a, b, c='c', *reszta):
    print ('F', a, b, c, reszta)

#f2(10)
f2(10, 20)
f2(10, 20, 30) 
f2(1,2,3,4)
f2(1,2,3,4,5)
f2(1,2,3,4,5,1,2,3,4,5)

f2(*(10 * [7]))


def f3(a=777,b=888, **c):
    print ('F3', a, b, c)
    if 'x' in c:
        print ('x=', c['x'])
    else:
        print ('x=', 777)    
    if 'z' in c:
        print ('z=', c['z'])
    else:
        print ('z=', 777)    

print()    
f3(1,2)
f3(1,2,x=3, y=5)

print ()
f3(b=10, a=12, x=333) 
#f3(x=3, 1, 2, y=5)
    
    
######################################
#  splaszcz_rekliste.py
######################################

# reklista:
#     liczba
#     [r1, ..., rk], gdzie r_i jest reklistą

# Przykładowa: [ [1,2,3], [], [[5,6], [7,8]], [[[[11]]]]]

# splaszczenie: [ [2,2,3], [3,4,[5]]] --> [2,2,3,3,4,5]

def splaszcz(RL):
    if type(RL) == int or type(RL) == float:
        return [RL]
    res = []
    for e in RL:
        res += splaszcz(e)
    return res
    
def splaszcz(RL):
    if type(RL) == int or type(RL) == float:
        return [RL]
    #return [e for e in r for r in splaszcz(RL)]
    return [e for r in RL for e in splaszcz(r)]

            
    
print (splaszcz( [ [2,2,3], [3,4,[5]], [],[],[7,7,[7,7]]]  ))  


######################################
#  suma.py
######################################

def suma(*arg):
    s = 0
    for e in arg:
        s += e
    return s
    
print (suma(1,2,3,4))

L = [1,2,3,4,10]

print (suma(*L))

