import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

// ---------------------------------------------------

public class Client {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("Enter value for parameter a (or 'exit' to quit): ");
                String inputA = scanner.nextLine().trim();

                if ("exit".equalsIgnoreCase(inputA)) {
                    break;
                }

                System.out.println("Enter value for parameter b (or 'exit' to quit): ");
                String inputB = scanner.nextLine().trim();

                if ("exit".equalsIgnoreCase(inputB)) {
                    break;
                }

                try {
                    int a = Integer.parseInt(inputA);
                    int b = Integer.parseInt(inputB);

                    if (a <= 0 || b <= 0) {
                        throw new NumberFormatException();
                    }

                    String result = sendPostRequest(a, b);
                    System.out.println(result);
                    System.out.println();
                } catch (NumberFormatException e) {
                    System.out.println("Error: Parameters must be positive integers");
                }
            }

            scanner.close();
            System.out.println("Client ended work.");
        } catch (Exception e) {
            System.err.println("Client error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    // --------------------------------------------

    private static String sendPostRequest(int a, int b) throws Exception {
        String serverURL = "http://localhost:8080/NWD";
        URL url = new URL(serverURL);
        HttpURLConnection conn = (HttpURLConnection) url.openConnection();

        conn.setRequestMethod("POST");
        conn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");

        String postData = String.format("a=%s&b=%s",
               URLEncoder.encode(String.valueOf(a), StandardCharsets.UTF_8.toString()),
               URLEncoder.encode(String.valueOf(b), StandardCharsets.UTF_8.toString()));

        conn.setDoOutput(true);
        try (PrintWriter out = new PrintWriter(conn.getOutputStream())) {
            out.print(postData);
            out.close();
        }

        StringBuilder response = new StringBuilder();
        try (BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()))) {
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }
            in.close();
        }

        conn.disconnect();
        return response.toString();
    }
}
