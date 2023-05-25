public class ThreeOfKind implements ListElem
{
    public int get_value()
    {
        return 20;
    }

    public String toString()
    {
        return "ThreeOfKind";
    }

    public int compareTo(ListElem other)
    {
        return Integer.compare(this.get_value(), other.get_value());
    }    
}
