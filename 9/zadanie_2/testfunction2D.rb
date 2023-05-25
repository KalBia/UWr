require './function2D'

blok1 = lambda {|x, y| 3}
blok2 = lambda {|x, y| x + y}
foo1 = Function2D.new(&blok1)
foo2 = Function2D.new(&blok2)

puts "Wartosc foo1 dla (1, 3): " + foo1.value(1, 3).to_s
puts "Wartosc foo1 dla (15, 6): " + foo1.value(15, 6).to_s
puts "Wartosc foo2 dla (1, 3): " + foo2.value(1, 3).to_s
puts "Wartosc foo1 dla (15, 6): " + foo2.value(15, 6).to_s

puts "Volume foo1 dla (1, 3, 4, 5): " + foo1.volume(1, 3, 4, 5).to_s
puts "Volume foo2 dla (1, 3, 4, 5): " + foo2.volume(1, 3, 4, 5).to_s

puts "Contour line foo1 dla (1, 1.5, 1, 1, 3): " + foo1.contourline(1, 1.5, 1, 1, 3).to_s
puts "Contour line foo1 dla (1, 1.5, 1, 1, 2): " + foo1.contourline(1, 1.5, 1, 1, 2).to_s
puts "Contour line foo2 dla (1, 3, 1, 2, 3): " + foo2.contourline(1, 3, 1, 2, 3).to_s
puts "Contour line foo2 dla (1, 3, 1, 2, 15): " + foo1.contourline(1, 3, 1, 2, 15).to_s
