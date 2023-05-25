class Collection

  def initialize
    @lista = Array.new
    @length = 0
    @type = nil
  end

  def <<(element)
    if @length == 0
      @type = element.class
    end

    unless element.kind_of?(@type)
      puts "Invalid type of element for this collection"
      return
    end

    @lista.push(element)
    @length += 1
  end

  def swap(i, j)
    unless i < @length && j < @length
      puts "Invalid index"
      return
    end

    temp = @lista[i]
    @lista[i] = @lista[j]
    @lista[j] = temp
  end

  def length()
    @length
  end

  def get(i)
    unless i < @length
      puts "Invalid index"
      return
    end

    @lista[i]
  end

  def compare(i, j) #zwraca true, jeśli lista[i] <= lista[j], wpp false
    unless i < @length && j < @length
      puts "Invalid index"
      return
    end

    if @type == Integer || @type == Float || @type == String
      return @lista[i] <= @lista[j]

    else #obiekt jakiejś klasy własnej
      unless @lista[i].respond_to?("compare")
        puts "Can't compare elements of this class"
        return
      end

      return @lista[i].compare(@lista[j])
    end
  end

end
