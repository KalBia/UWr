require './czas.rb'
require './dlugosc.rb'

class Przyspieszenie

  def initialize(dlugosc, czas)
    @dl = dlugosc
    @cz = czas
  end

  def kms2
    if @cz.sekunda == 0
      puts "Wrong argument"
      @kms2 = 0
    else
      @kms2 = @dl.kilometr / (1.0 * @cz.sekunda * @cz.sekunda)
    end
  end

  def kms2=(temp)
    @kms2= temp
  end

  def mmh2
    if @cz.godzina == 0
      puts "Wrong argument"
      @mmh2 = 0
    else
      @mmh2 = @dl.milamorska / (1.0 * @cz.godzina * @cz.godzina)
    end
  end

end
