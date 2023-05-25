public class FourOfKind implements ListElem
{
    public int get_value()
    {
        return 40;
    }

    public String toString()
    {
        return "FourOfKind";
    }

    public int compareTo(ListElem other)
    {
        return Integer.compare(this.get_value(), other.get_value());
    }
}
