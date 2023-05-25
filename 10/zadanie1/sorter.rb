require './collection'

# comparison of sort1 and sort2
# name  - best - worst - average - memory
# sort1 - n^2  - n^2   - n^2     - 1
# sort2 - n    - n^2   - n^2     - 1       FASTER

class Sorter

  def sort1(kolekcja) # selection sort
    already_sorted = -1
    while already_sorted < (kolekcja.length() - 1)
      best_pick = already_sorted + 1
      i = best_pick + 1

      while i < kolekcja.length()
        if kolekcja.compare(i, best_pick) == nil
          return false # nie można wykonać sortowania, bo elementy nie mają zdefiniowanego porównywania
        end

        if kolekcja.compare(i, best_pick)
          best_pick = i
        end

        i += 1
      end

      already_sorted += 1
      kolekcja.swap(already_sorted, best_pick)
    end

    return true
  end

  def sort2(kolekcja) # bubble sort
    sorted = false
    i = 1
    while i < kolekcja.length()
      if kolekcja.compare(i, best_pick) == nil
        return false
      end

      if kolekcja.compare(i, i-1)
        kolekcja.swap(i, i-1)
        i = 1
      end

      i += 1
    end

    return true
  end

end
