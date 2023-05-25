class Function2D

  def initialize(&block)
    @func = block
  end

  def value(x, y)
    @func.call(x, y)
  end

  def volume(a, b, c, d)
    x = (b - a) # to jest pierwszy bok prostokąta w podstawie
    y = (d - c) / 50.0 # to jest drugi bok prostokąta w podstawie, tak jak będziemy dzielić na prostokąty by liczyć objętość
    suma = 0.0
    srodek_x = a + (b - a)/2.0
    srodek_y = c + (d - c)/(2.0 * 50.0)
    i = 0.0
    while i < 50.0
      suma += self.value(srodek_x, srodek_y)
      srodek_y += y
      i += 1.0
    end
    suma *= x * y
  end

  def contourline(a, b, c, d, height)
    pary = Array.new
    i = a
    while i <= b
      j = c
      while j <= d
        if (self.value(i, j) <= (height + 0.01)) && (self.value(i, j) >= (height - 0.01))
          pary.push([i, j])
        end
        j += 0.02
        j = j.round(2)
        # dodawanie liczb niecałkowitych ma ten mankament, że umie nam zwrócić śmieci na dalszych pozycjach, jakieś małe ale psujące wynik
      end
      i += 0.02
      i = i.round(2)
    end
    return pary
  end

end
