import java.util.Map;

public class sub implements Expression
{
    Expression E1;
    Expression E2;

    public sub (Expression e1, Expression e2)
    {
        E1 = e1;
        E2 = e2;
    }

    public int evaluate(Map<String, Integer> values)
    {
        return (E1.evaluate(values) - E2.evaluate(values));
    }

    public String toString()
    {
        return "( " + E1.toString() + " - " + E2.toString() + " )";
    }
}
