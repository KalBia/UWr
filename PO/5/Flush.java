public class Flush implements ListElem
{
    public int get_value()
    {
        return 30;
    }

    public String toString()
    {
        return "Flush";
    }

    public int compareTo(ListElem other)
    {
        return Integer.compare(this.get_value(), other.get_value());
    }
}
