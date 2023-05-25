class Dlugosc

  def initialize(temp)
    @metr = temp
  end

  def metr
    @metr
  end

  def metr=(temp)
    @metr = temp
  end

  def jard
    @jard = 0.9144 * @metr
  end

  def jard=(temp)
    @metr = 1.093613 * temp
  end

  def kilometr
    @kilometr = 0.001 * @metr
  end

  def kilometr=(temp)
    @metr = 1000 * temp
  end

  def milamorska
    @milamorska =  0.53995680 * @kilometr
  end

  def milamorska=(temp)
    @metr = 1852 * temp
  end

end
