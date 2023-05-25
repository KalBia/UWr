// Kalina Białek
// zadanie 2
// VSCode

import java.util.HashMap;
import java.util.Map;

public class App 
{
    public static void main(String[] args) throws Exception 
    {
        System.out.println("TEST START");

        // 2*x + (17 - y/2)
        Expression exp = new add( 
                                new mult(
                                        new constant(2), 
                                        new variable("x")), 
                                new sub(
                                        new constant(17), 
                                        new div(
                                                new variable("y"), 
                                                new constant(2))) );

        System.out.println(exp.toString());

        Map<String, Integer> values = new HashMap<String, Integer>();
        values.put("x", 1);
        values.put("y", 4);
        
        System.out.println(exp.evaluate(values));
    }
}
