import java.io.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class Kula extends HttpServlet {
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
    public void doGet(HttpServletRequest request, HttpServletResponse response)
                    throws IOException, ServletException
    {
        String radius_str = request.getParameter("r");

        response.setContentType("text/html");
        try (PrintWriter out = response.getWriter()) {
            if (radius_str != null) {
                try {
                    double r = Double.parseDouble(radius_str);

                    if (r >= 0) {
                        double V = (4.0/3.0) * Math.PI * Math.pow(r, 3);
                        double P = 4.0 * Math.PI * Math.pow(r, 2);
                        printForUser(out, "The volume is: " + V + " and the surface is: " + P);
                    }
                    else {
                        printForUser(out, "Can't take negative value!");
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

    private void printHowToUse(PrintWriter out) {
        out.println("<!DOCTYPE html>");
        out.println("<html>");
        out.println("<head><title>Sphere Calculator - Instructions</title></head>");
        out.println("<body>");
        out.println("<h1>Sphere Calculator</h1>");
        out.println("<p>This application calculates the volume and surface area of a sphere.</p>");
        out.println("<h2>How to use:</h2>");
        out.println("<p>Add a parameter <strong>r</strong> to the URL representing the radius of the sphere.</p>");
        out.println("<p>Example: <code>http://localhost:8080/lista6/kula?r=5</code></p>");
        out.println("<p>This will calculate the volume and surface area of a sphere with radius 5 units.</p>");
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
        out.println("<head><title>Sphere Calculator - Result</title></head>");
        out.println("<body>");
        out.println("<h1>Sphere Calculator</h1>");
        out.println("<div style='margin: 20px 0; padding: 10px; border: 1px solid #ccc; background-color: #f8f8f8;'>");
        out.println("  <p>" + mess + "</p>");
        out.println("</div>");
        out.println("<p><a href='?'>Try another calculation</a></p>");
        out.println("<hr>");
        out.println("<footer>");
        out.println("        <p><a href='index.html'>Back to menu</a></p>");
        out.println("<p>Created by: " + name + " " + surname + "</p>");
        out.println("<p>Contact: " + email + "</p>");
        out.println("</footer>");
        out.println("</body>");
        out.println("</html>");
    }
}
