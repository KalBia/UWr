require './masa.rb'
require './powierzchnia.rb'

class Cisnienie

  def initialize(masa, powierzchnia)
    if powierzchnia == 0
      puts "Wrong argument"
      @kgm2 = 0
    else
      @kgm2 = masa.kg / ((1.0)*powierzchnia.m2)
    end
  end

  def kgm2
    @kgm2
  end

  def kgm2=(temp)
    @kgm2 = temp
  end

  def pascal
    @pascal = 9.80665 * @kgm2
  end

  def pascal=(temp)
    @kgm2 = 0.101972 * temp
  end

  def bar
    @bar = 0.000098 * @kgm2
  end

  def bar=(temp)
    @kgm2 = 10197.16213 * temp
  end

  def psi
    @psi = 0.001422 * @kgm2
  end

  def psi=(temp)
    @kgm2 = 703.069856 * temp
  end

  def psieval=(masa, powierzchnia)
    @kgm2 = 703.069856 * (masa.funt / powierzchnia.cal2)
  end

end
