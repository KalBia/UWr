import java.util.Map;

public class div implements Expression
{
    Expression E1;
    Expression E2;

    public div(Expression e1, Expression e2)
    {
        E1 = e1;
        E2 = e2;
    }

    public int evaluate(Map<String, Integer> values)
    {
        int temp = E2.evaluate(values);

        if (temp != 0)
            return (E1.evaluate(values) / temp);
        
        System.out.println("Divide by zero, returning 0.");
        return 0;
    }

    public String toString()
    {
        return "( " + E1.toString() + " / " + E2.toString() + " )";
    }
}
