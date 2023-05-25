import java.util.Map;

public class constant implements Expression
{
    int value;

    public constant(int v)
    {
        value = v;
    }

    public int evaluate(Map<String, Integer> values)
    {
        return value;
    }

    public String toString()
    {
        return Integer.toString(value);
    }
}
