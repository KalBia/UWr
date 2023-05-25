public class OnePair implements ListElem
{
    public int get_value()
    {
        return 10;
    }

    public String toString()
    {
        return "OnePair";
    }

    public int compareTo(ListElem other)
    {
        return Integer.compare(this.get_value(), other.get_value());
    }    
}
