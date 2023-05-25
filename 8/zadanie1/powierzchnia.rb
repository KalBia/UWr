require './dlugosc.rb'

class Powierzchnia

  def initialize(wymiar1, wymiar2)
    @m2 = wymiar1.metr * wymiar2.metr
  end

  def m2
    @m2
  end

  def m2=(temp)
    @m2 = temp
  end

  def hektar
    @hektar = 0.0001 * @m2
  end

  def hektar=(temp)
    @m2 = 10000 * temp
  end

  def cal2
    @cal2 = 0.00064516 * @m2
  end

  def cal2=(temp)
    @m2 = 1550.0031 * temp
  end

end
