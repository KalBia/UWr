import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class OrderedList
{
    List <ListElem> array;

    public OrderedList()
    {
        this.array = new ArrayList<ListElem>();
    }

    public void add_element(ListElem elem)
    {
        array.add(elem);
        Collections.sort(array);
    }

    public ListElem get_first()
    {
        if (array.size() == 0)
        {
            System.out.println("No elements");
            return null;
        }

        ListElem ret = array.get(0);
        array.remove(0);
        return ret;
    }

    public String toString()
    {
        String result = "";
        for (ListElem e : array)
        {
            result += (e.toString() + "   ");
        }
        return result;
    }
}
