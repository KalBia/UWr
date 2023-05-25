class Masa

  def initialize(temp)
    @kg = temp
  end

  def kg
    @kg
  end

  def kg=(temp)
    @kg = temp
  end

  def funt
    @funt = 0.45359237 * @kg
  end

  def funt=(temp)
    @kg = 2.20462 * temp
  end

end
