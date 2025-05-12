<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.lang.Math" %>
<%@ page import="java.lang.Integer" %>
<%@ page import="jakarta.servlet.http.HttpServletRequest" %>
<%@ page import="java.math.BigInteger" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pascal Triangle</title>
    <link rel="stylesheet" href="style.css"> <!-- Wskazujemy style -->
</head>
<body>

<div class="image-container">
    <img src="pascal.jpg" alt="Pascal Triangle Illustration" class="header-image">
</div>

<div class="container">
    <h1>Pascal Triangle</h1>
    <p>Enter the number below and click "Calculate" to see Pascal Triangle of this height.</p>

    <form action="pascal.jsp"> <!-- Tutaj wskazujemy plik z akcjami -->
        <label for="inputNumber">Enter Number:</label>
        <input type="number" id="inputNumber" min="1" max="100" name="h" value="<%= (request.getParameter("h") != null && !request.getParameter("h").trim().isEmpty()) ? request.getParameter("h") : "10" %>" />

        <button type="submit">Calculate</button>
    </form>
</div>

<%!
    private BigInteger binomialCoeff(int n, int k) {
        BigInteger res = BigInteger.ONE;

        // C(n, k) = C(n, n-k)
        if (k > n - k) {
            k = n - k;
        }

        // [n * (n-1) *...* (n-k+1)] / [k * (k-1) *...* 1]
        for (int i = 0; i < k; ++i) {
            res = res.multiply(BigInteger.valueOf(n - i));
            res = res.divide(BigInteger.valueOf(i + 1));
        }

        return res;
    }

    private String printPascal(int n) {
        int totalRows = n + 1;
        int totalCols = 2 * totalRows - 1;
        StringBuilder result = new StringBuilder();

        result.append("<table class=\"pascal-table\">\n");
        for (int line = 0; line < totalRows; line++) {
            result.append("  <tr>\n");
            int startPos = (totalCols - (2 * line + 1)) / 2;

            for (int i = 0; i < startPos; i++) {
                result.append("    <td></td>\n");
            }

            for (int i = 0; i <= line; i++) {
                result.append("    <td class=\"pascal-cell\">")
                        .append(binomialCoeff(line, i))
                        .append("</td>\n");

                if (i < line) {
                    result.append("    <td></td>\n");
                }
            }

            for (int i = 0; i < startPos; i++) {
                result.append("    <td></td>\n");
            }

            result.append("  </tr>\n");
        }

        result.append("</table>");

        return result.toString();
    }
%>

<%
    String rawNumber = request.getParameter("h");

    if (rawNumber != null && !rawNumber.trim().isEmpty()) {
        try {
            int h = Integer.parseInt(rawNumber, 10);

            if (h >= 0) {
            %>
                <div class="container">
                    <h1>Pascal Triangle Result</h1>
                    <div class="result-box">
                        <div style="font-family: monospace; text-align: center;">
                            <%= printPascal(h) %>
                        </div>
                    </div>
                    <a href="pascal.jsp" class="button">Try Again</a>
                </div>
            <%
            }
            else {
            %>
                <div class="result-box">
                    <p>The number must be non-negative!</p>
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
            <p>You have to give the height as input.</p>
        </div>
    <%
    }
%>

</body>
</html>