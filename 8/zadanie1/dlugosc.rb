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

end
