class Function

  def initialize(&block)
    @func = block
  end

  def value(x)
    @func.call(x)
  end

  def zero(a, b, e)
    if self.value(a) == 0
      return a
    elsif self.value(b) == 0
      return b
    elsif self.value(a) * self.value(b) > 0
      return nil
    else
      while b - a > e
        srodek = (a + b) / 2.0
        if self.value(srodek) == 0
          return srodek
        elsif self.value(srodek) * self.value(a) < 0
          b = srodek
        else
          a = srodek
        end
      end
      (a + b) / 2.0
    end
  end

  def field(a, b)
    x = (b - a) / 50.0
    suma = 0.0
    srodek = a + (b - a)/(2.0 * 50.0)
    i = 0.0
    while i < 50.0
      suma += self.value(srodek)
      srodek += x
      i += 1.0
    end
    suma *= x
  end

  def deriv(x)
    (self.value(x + 0.02) - self.value(x)) / 0.02
  end

end
