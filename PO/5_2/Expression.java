import java.util.Map;

public interface Expression 
{
    public int evaluate(Map<String, Integer> values);
    public String toString();
}
