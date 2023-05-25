require './node'

class Kolekcja

  def initialize
    @first = nil
    @last = nil
    @long = 0
    @type = nil
  end

  def <<(elem)
    if @long == 0
      @first = Node.new(elem)
      @last = @first
      @long = 1
      @type = elem.class
      return
    end

    unless elem.kind_of?(@type)
      puts "Invalid type of element"
      return
    end

    prev = nil
    current = @first
    while current != nil && current.value < elem
      prev = current
      current = current.next
    end

    nowy = Node.new(elem)
    if prev != nil
      prev.next = nowy
    else
      @first = nowy
    end
    if current != nil
      current.prev = nowy
    else
      @last = nowy
    end
    nowy.prev = prev
    nowy.next = current
    @long += 1
    return
  end

  def get(i)
    unless i < @long
      puts "Invalid index"
      return
    end

    current = @first
    ind = 0
    while ind != i
      current = current.next
      ind += 1
    end

    return current.value

  end

  def length()
    @long
  end

end
