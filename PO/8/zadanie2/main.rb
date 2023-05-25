require './predkosc'
require './przyspieszenie'

czas = Czas.new(345)
dlugosc = Dlugosc.new(3450)
predkosc = Predkosc.new(dlugosc, czas)
przyspieszenie = Przyspieszenie.new(dlugosc, czas)

puts "\n   PREDKOSC"
puts "_______________"
puts " km/h | węzły "
puts " " + predkosc.kmh.to_s + "  | " + predkosc.wezel.to_s

print "\n\n\n"

puts "   PRZYSPIESZENIE"
puts "____________________"
puts "  km/s^2 | mm/h^2 "
puts " " + przyspieszenie.kms2.round(6).to_s + " | " + przyspieszenie.mmh2.round(5).to_s

print "\n\n"
