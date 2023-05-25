require './dlugosc.rb'
require './czas.rb'

class Predkosc

  def initialize(dlugosc, czas)
    if czas.godzina == 0
      puts "Wrong argument"
      @kmh = 0
    else
      @kmh = dlugosc.kilometr / (1.0 * czas.godzina)
    end
  end

  def kmh
    @kmh
  end

  def kmh=(temp)
    @kmh = temp
  end

  def wezel
    @wezel = 1.852 * @kmh
  end

  def wezel=(temp)
    @kmh = 0.539957 * temp
  end

end
