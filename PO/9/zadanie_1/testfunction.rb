require './function'

blok = lambda {|x| x*x - 5*x + 6}
foo = Function.new(&blok)

puts "Wartosc dla 0: " + foo.value(0).to_s
puts "Wartosc dla 2: " + foo.value(2).to_s
puts "Miejsce zerowe w [1, 2.5]: " + foo.zero(1, 2.5, 0.000001).to_s
puts "Miejsce zerowe w [-3, -1]: " + foo.zero(-3, -1, 0.000001).to_s
puts "Pole pod wykresem w [0, 2]: " + foo.field(0, 2).to_s
puts "Przyblizona wartosc pochodnej dla 0: " + foo.deriv(0).to_s
