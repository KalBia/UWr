require './kolekcja'
require './wyszukiwanie'

kolekcja = Kolekcja.new
wyszukiwanie = Wyszukiwanie.new

kolekcja<<3
puts "\nPo dodaniu 3 do kolekcji"
i = 0
while i < kolekcja.length()
  puts kolekcja.get(i)
  i += 1
end

kolekcja<<5
puts "\nPo dodaniu 5 do kolekcji"
i = 0
while i < kolekcja.length()
  puts kolekcja.get(i)
  i += 1
end

kolekcja<<1
puts "\nPo dodaniu 1 do kolekcji"
i = 0
while i < kolekcja.length()
  puts kolekcja.get(i)
  i += 1
end

kolekcja<<17
puts "\nPo dodaniu 17 do kolekcji"
i = 0
while i < kolekcja.length()
  puts kolekcja.get(i)
  i += 1
end

kolekcja<<13
puts "\nPo dodaniu 13 do kolekcji"
i = 0
while i < kolekcja.length()
  puts kolekcja.get(i)
  i += 1
end

######################################

puts "\nWyszukiwanie liniowe: 3"
puts wyszukiwanie.linear(kolekcja, 3)

puts "\nWyszukiwanie binarne: 17"
puts wyszukiwanie.binary(kolekcja, 17)
