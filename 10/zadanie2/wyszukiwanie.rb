require './kolekcja'

# zwraca indeks szukanego elementu jeśli jest w kolekcji, nil wpp
class Wyszukiwanie

  def linear(kolekcja, elem)
    if kolekcja.length() == 0
      puts "Kolekcja jest pusta"
      return
    end

    current = kolekcja.get(0)
    i = 1
    while i < kolekcja.length() && current != elem
      current = kolekcja.get(i)
      i += 1
    end

    if current == elem
      return i-1
    end

    puts "Nie ma takiego elementu w kolekcji"
    return
  end

  def binary(kolekcja, elem)
    if kolekcja.length() == 0
      puts "Kolekcja jest pusta"
      return
    end

    left = 0
    right = kolekcja.length() - 1
    while left <= right
      mid = (left + right) / 2
      current = kolekcja.get(mid)
      if current == elem
        return mid
      elsif current > elem
        right = mid - 1
      else
        left = mid + 1
      end
    end

    puts "Nie ma takiego elementu w kolekcji"
    return
  end

end
