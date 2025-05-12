<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.lang.Math" %>
<%@ page import="java.lang.Integer" %>
<%@ page import="jakarta.servlet.http.HttpServletRequest" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GCD Result</title>
    <link rel="stylesheet" href="style.css"> <!-- Wskazujemy style -->
</head>
<body>
<div class="container">
    <h1>GCD Result</h1>

    <%
        String rawA = request.getParameter("a");
        String rawB = request.getParameter("b");

        if (rawA != null && rawB != null && !rawA.trim().isEmpty() && !rawB.trim().isEmpty()) {
            try {
                int a = Integer.parseInt(rawA, 10);
                int b = Integer.parseInt(rawB, 10);

                if (a > 0 && b > 0) {
                    int result = calculateGCD(a, b);
                %>
                    <div class="result-box">
                        <div class="original">
                            <div class="label">Input Numbers:</div>
                            <div class="text">A = <%= a %>, B = <%= b %></div>
                        </div>

                        <div class="original">
                            <div class="label">Greatest Common Divisor (GCD):</div>
                            <div class="text"><%= result %></div>
                        </div>
                    </div>
                <%
                }
                else {
                %>
                    <div class="result-box">
                        <p>The numbers must be positive!</p>
                    </div>
                <%
                }
            }
            catch (NumberFormatException e) {
            %>
                <div class="result-box">
                    <p>There was a problem with format of the input numbers.</p>
                </div>
            <%
            }
        }
        else {
        %>
            <div class="result-box">
                <p>You have to give two numbers as input.</p>
            </div>
        <%
        } %>
    <a href="index.html" class="button">Try Again</a>
</div>

<%!
    private int calculateGCD(int a, int b) {
        if (b == 0)
            return a;
        return calculateGCD(b, a % b);
    }
%>

</body>
</html>