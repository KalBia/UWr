require './powierzchnia'
require './cisnienie'

masa = Masa.new(45)
dlugosc = Dlugosc.new(10)
dlugoscextra = Dlugosc.new(3)
powierzchnia = Powierzchnia.new(dlugosc, dlugoscextra)
cisnienie = Cisnienie.new(masa, powierzchnia)

puts "\n     POWIERZNIA"
puts "_________________________"
puts " m2 | hektar | cal2"
puts " " + powierzchnia.m2.to_s + " |  " + powierzchnia.hektar.to_s + " | " + powierzchnia.cal2.to_s

print "\n\n\n"

puts "              CISNIENIE"
puts "______________________________________"
puts "  pascal  | kg/m2 |   bar    | psi"
puts " " + cisnienie.pascal.to_s + "|  " + cisnienie.kgm2.to_s + "  | " + cisnienie.bar.to_s + " | " + cisnienie.psi.round(5).to_s

print "\n\n"
