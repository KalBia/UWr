public interface ListElem extends Comparable<ListElem>
{
    public int get_value();
    public String toString();

    public int compareTo(ListElem other);
}
