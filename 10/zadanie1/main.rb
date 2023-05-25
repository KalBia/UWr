require './collection'
require './sorter'

kolekcja1 = Collection.new
kolekcja2 = Collection.new
sorter = Sorter.new

i = 10
while i >= 0
  kolekcja1<<i
  i -= 1
end

i = 0
puts "KOLEKCJA INT"
puts "SORT1\nKolekcja przed sortowaniem"
while i <= 10
  puts kolekcja1.get(i)
  i += 1
end

puts "Kolekcja po sortowaniu"
sorter.sort1(kolekcja1)
i = 0
while i <= 10
  puts kolekcja1.get(i)
  i += 1
end

###############################################

i = 10
while i >= 0
  kolekcja2<<i
  i -= 1
end

i = 0
puts "\nKOLEKCJA INT"
puts "SORT2\nKolekcja przed sortowaniem"
while i <= 10
  puts kolekcja2.get(i)
  i += 1
end

puts "Kolekcja po sortowaniu"
sorter.sort1(kolekcja2)
i = 0
while i <= 10
  puts kolekcja2.get(i)
  i += 1
end


###############################################

kolekcja3 = Collection.new

kolekcja3<<"k"
kolekcja3<<"j"
kolekcja3<<"i"
kolekcja3<<"h"
kolekcja3<<"g"
kolekcja3<<"f"
kolekcja3<<"e"
kolekcja3<<"d"
kolekcja3<<"c"
kolekcja3<<"b"
kolekcja3<<"a"

i = 0
puts "\nKOLEKCJA STRING"
puts "SORT1\nKolekcja przed sortowaniem"
while i <= 10
  puts kolekcja3.get(i)
  i += 1
end

puts "Kolekcja po sortowaniu"
sorter.sort1(kolekcja3)
i = 0
while i <= 10
  puts kolekcja3.get(i)
  i += 1
end
