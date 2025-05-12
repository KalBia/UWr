import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class Trojkat extends HttpServlet {
    private String name;
    private String surname;
    private String email;

    @Override
    public void init() throws ServletException {
        ServletContext context = getServletContext();
        name = context.getInitParameter("name");
        surname = context.getInitParameter("surname");
        email = context.getInitParameter("email");
    }

    // -------------------------------------

    @Override
    public void doGet (HttpServletRequest request, HttpServletResponse response)
                    throws IOException, ServletException
    {
        String aRaw = getServletConfig().getInitParameter("default_a");
        String bRaw = getServletConfig().getInitParameter("default_b");
        String cRaw = getServletConfig().getInitParameter("default_c");
        try (PrintWriter out = response.getWriter()) {
            showStartPage(out, aRaw, bRaw, cRaw);
        }
        catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
                    throws IOException, ServletException
    {
        request.setCharacterEncoding("UTF-8");
        String aRaw = request.getParameter("a");
        String bRaw = request.getParameter("b");
        String cRaw = request.getParameter("c");

        response.setContentType("text/html; charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            if (aRaw != null && bRaw != null && cRaw != null) {
                try {
                    double a = Double.parseDouble(aRaw);
                    double b = Double.parseDouble(bRaw);
                    double c = Double.parseDouble(cRaw);

                    if (a > 0 && b > 0 && c > 0) {
                        if (triangleRule(a, b, c)) {
                            double Ob = a + b + c;
                            double s = Ob/2.0;
                            double P = Math.sqrt(s * (s - a) * (s - b) * (s - c));
                            printForUser(out, "The perimeter is: " + Ob + " and the surface is: " + P);
                        }
                        else {
                            printForUser(out, "It's not a proper triangle!");
                        }
                    }
                    else {
                        printForUser(out, "Can't take negative values!");
                    }
                }
                catch (NumberFormatException e) {
                    printForUser(out, "Bad data format!");
                }
            }
            else {
                printHowToUse(out);
            }
        }
        catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    // ----------------------------

    private boolean triangleRule(double a, double b, double c) {
        return (a + b > c && b + c > a && c + a > b);
    }

    // ----------------------------

    private void printHowToUse(PrintWriter out) {
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head><title>Triangle Calculator - Instructions</title></head>");
        out.println("<body>");
        out.println("<h1>Triangle Calculator</h1>");
        out.println("<p>This application calculates the perimeter and surface area of a triangle.</p>");
        out.println("<h2>How to use:</h2>");
        out.println("<p><a href='trojkat'>Back to calculator form</a></p>");
        out.println("<p>The calculation will be performed after submitting the form.</p>");
        out.println("<hr>");
        out.println("<footer>");
        out.println("        <p><a href='index.html'>Back to menu</a></p>");
        out.println("<p>Created by: " + name + " " + surname + "</p>");
        out.println("<p>Contact: " + email + "</p>");
        out.println("</footer>");
        out.println("</body>");
        out.println("</html>");
    }

    private void printForUser(PrintWriter out, String mess) {
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head><title>Triangle Calculator - Result</title></head>");
        out.println("<body>");
        out.println("<h1>Triangle Calculator</h1>");
        out.println("<div style='margin: 20px 0; padding: 10px; border: 1px solid #ccc; background-color: #f8f8f8;'>");
        out.println("  <p>" + mess + "</p>");
        out.println("</div>");
        out.println("<p><a href='trojkat'>Back to calculator form</a></p>");
        out.println("<hr>");
        out.println("<footer>");
        out.println("        <p><a href='index.html'>Back to menu</a></p>");
        out.println("<p>Created by: " + name + " " + surname + "</p>");
        out.println("<p>Contact: " + email + "</p>");
        out.println("</footer>");
        out.println("</body>");
        out.println("</html>");
    }

    private void showStartPage(PrintWriter out, String aRaw, String bRaw, String cRaw) {
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head>");
        out.println("    <title>Triangle Calculator</title>");
        out.println("    <style>");
        out.println("        body {");
        out.println("            font-family: Arial, sans-serif;");
        out.println("            margin: 20px;");
        out.println("            line-height: 1.6;");
        out.println("        }");
        out.println("        .container {");
        out.println("            max-width: 600px;");
        out.println("            margin: 0 auto;");
        out.println("            padding: 20px;");
        out.println("            border: 1px solid #ddd;");
        out.println("            border-radius: 5px;");
        out.println("            background-color: #f9f9f9;");
        out.println("        }");
        out.println("        .form-group {");
        out.println("            margin-bottom: 15px;");
        out.println("        }");
        out.println("        label {");
        out.println("            display: block;");
        out.println("            margin-bottom: 5px;");
        out.println("            font-weight: bold;");
        out.println("        }");
        out.println("        input[type=\"number\"] {");
        out.println("            width: 100%;");
        out.println("            padding: 8px;");
        out.println("            border: 1px solid #ddd;");
        out.println("            border-radius: 4px;");
        out.println("            box-sizing: border-box;");
        out.println("        }");
        out.println("        button {");
        out.println("            background-color: #4CAF50;");
        out.println("            color: white;");
        out.println("            padding: 10px 15px;");
        out.println("            border: none;");
        out.println("            border-radius: 4px;");
        out.println("            cursor: pointer;");
        out.println("        }");
        out.println("        button:hover {");
        out.println("            background-color: #45a049;");
        out.println("        }");
        out.println("        footer {");
        out.println("            margin-top: 20px;");
        out.println("            font-size: 0.9em;");
        out.println("            color: #666;");
        out.println("        }");
        out.println("    </style>");
        out.println("</head>");
        out.println("<body>");
        out.println("    <div class=\"container\">");
        out.println("        <h1>Triangle Calculator</h1>");
        out.println("        <p>Enter the sides of the triangle to calculate its perimeter and surface area.</p>");
        out.println("");
        out.println("        <form action=\"trojkat\" method=\"POST\">");
        out.println("            <div class=\"form-group\">");
        out.println("                <label for=\"side-a\">Side A:</label>");
        out.println("                <input type=\"number\" id=\"side-a\" value=\"" + aRaw + "\" step=\"0.1\" min=\"0.1\" name=\"a\" />");
        out.println("            </div>");
        out.println("            <div class=\"form-group\">");
        out.println("                <label for=\"side-b\">Side B:</label>");
        out.println("                <input type=\"number\" id=\"side-b\" value=\"" + bRaw + "\" step=\"0.1\" min=\"0.1\" name=\"b\" />");
        out.println("            </div>");
        out.println("            <div class=\"form-group\">");
        out.println("                <label for=\"side-c\">Side C:</label>");
        out.println("                <input type=\"number\" id=\"side-c\" value=\"" + cRaw + "\" step=\"0.1\" min=\"0.1\" name=\"c\" />");
        out.println("            </div>");
        out.println("            <button type=\"submit\">Calculate</button>");
        out.println("        </form>");
        out.println("    </div>");
        out.println("");
        out.println("    <footer>");
        out.println("        <p><a href='index.html'>Back to menu</a></p>");
        out.println("        <p>Created by: " + name + " " + surname + "</p>");
        out.println("        <p>Contact: " + email + "</p>");
        out.println("    </footer>");
        out.println("</body>");
        out.println("</html>");
    }
}
