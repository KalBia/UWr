class Czas

  def initialize(temp)
    @sekunda = temp
  end

  def sekunda
    @sekunda
  end

  def sekunda=(temp)
    @sekunda = temp
  end

  def godzina
    @godzina = (1.0 / 60) * sekunda
  end

  def godzina=(temp)
    @godzina = 60 * temp
  end

end
