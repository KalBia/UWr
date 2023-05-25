import java.util.Map;

public class variable implements Expression
{
    String name;

    public variable(String n)
    {
        name = n;
    }

    public int evaluate(Map<String, Integer> values)
    {
        return values.get(name);
    }

    public String toString()
    {
        return name;
    }
}
