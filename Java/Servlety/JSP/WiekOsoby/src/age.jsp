<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="jakarta.servlet.http.HttpServletRequest" %>
<%@ page import="java.time.LocalDate" %>
<%@ page import="java.time.Period" %>
<%@ page import="java.time.format.DateTimeParseException" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pascal Triangle</title>
    <link rel="stylesheet" href="style.css"> <!-- Wskazujemy style -->
</head>
<body>

<%!
    private String calculateDate(LocalDate bd) {
        LocalDate now = LocalDate.now();
        Period period = Period.between(bd, now);
        return period.getYears() + " years, " + period.getMonths() + " months, " + period.getDays() + " days";
    }
%>

<div class="image-container">
    <img src="cradle.jpg" alt="The Cradle" class="header-image">
</div>

<div class="audio-container">
    <audio autoplay loop>
        <source src="happy.mp3" type="audio/mpeg">
        Your browser does not support the audio element.
    </audio>
</div>

<div class="container">
    <h1>Calculate your age</h1>
    <p>Enter the number below and click "Calculate" to see how many years, months and days passed since you were born.</p>

    <form action="age.jsp" method="POST"> <!-- Tutaj wskazujemy plik z akcjami -->
        <label for="bd">Enter Date:</label>
        <input type="date" id="bd" min="1900-01-01" name="bd" value="<%= (request.getParameter("bd") != null && !request.getParameter("bd").trim().isEmpty()) ? request.getParameter("bd") : "1900-01-01" %>" />

        <button type="submit">Calculate</button>
    </form>
</div>

<%
    String rawBD = request.getParameter("bd");

    if (rawBD != null && !rawBD.trim().isEmpty()) {
        try {
            LocalDate bd = LocalDate.parse(rawBD);

            if (bd.isBefore(LocalDate.now())) {
            %>
                <div class="container">
                    <h1>Age Result</h1>
                    <div class="original">
                        <div class="label">Given Date:</div>
                        <div class="text"> <%= bd %> </div>
                    </div>

                    <div class="original">
                        <div class="label">Today's Date:</div>
                        <div class="text"> <%= LocalDate.now() %> </div>
                    </div>

                    <div class="result-box">
                        <div style="font-family: monospace; text-align: center;">
                            <%= calculateDate(bd) %>
                        </div>
                    </div>
                    <a href="age.jsp" class="button">Try Again</a>
                </div>
            <%
            }
            else {
            %>
                <div class="result-box">
                    <p>The date must be from the past!</p>
                </div>
            <%
            }
        }
        catch (DateTimeParseException e) {
        %>
            <div class="result-box">
                <p>There was a problem with format of the input date.</p>
            </div>
        <%
        }
    }
    else {
    %>
        <div class="result-box">
            <p>You have to give the date of your birth as input.</p>
        </div>
    <%
    }
%>

</body>
</html>