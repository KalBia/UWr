import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpServer;

// ----------------------------------------------------

public class Server {
    private static int NWD(int a, int b) {
        while (b != 0) {
            if (a >= b) {
                int rest = a % b;
                a = b;
                b = rest;
            }
            else {
                int swap = a;
                a = b;
                b = swap;
            }
        }
        return a;
    }

    // -----------------------------------------
    // setup and run server
    public static void main(String[] args) throws Exception {
        int port = 8080;
        HttpServer server = HttpServer.create(new InetSocketAddress(port), 0); // backlog: ile klientów może czekać na połączenie
        server.createContext("/NWD", new NWDCalc()); // gdy klient spyta o '/NWD' to odeślij go do NWDCalc
        server.setExecutor(null); // uży defaultowego reagowania na kilku klientów dzwoniących naraz

        server.start();
        System.out.println("Server started on port " + port);
        System.out.println("Send POST requests to http://localhost:" + port + "/NWD");
    }

    // -----------------------------------------

    static class NWDCalc implements HttpHandler {
        // HttpExchange to pośrednik w komunikacji - ma info o requeście i wraca z response
        @Override
        public void handle(HttpExchange exchange) throws IOException {
            try {

                // we accept only POST requests
                if ("POST".equals(exchange.getRequestMethod())) {
                    Map<String, String> params = parsePostParameters(exchange);

                    if (params.containsKey("a") && params.containsKey("b")) {
                        try {

                            // calculate response
                            int a = Integer.parseInt(params.get("a"));
                            int b = Integer.parseInt(params.get("b"));
                            int result = NWD(a, b);

                            // prepare response
                            String respondString = "The NWD of " + a + " and " + b + " is " + result;
                            exchange.getResponseHeaders().set("Content-Type", "text/plain");
                            exchange.sendResponseHeaders(200, respondString.length());

                            // send response
                            try (OutputStream os = exchange.getResponseBody()) {
                                os.write(respondString.getBytes());
                            }

                        } catch (NumberFormatException e) {
                            sendErrorResponse(exchange, "Error: Parameters must be integers", 400);
                        }
                    }
                    else {
                        sendErrorResponse(exchange, "Error: Missing parameters", 400);
                    }
                }
                else {
                    sendErrorResponse(exchange, "Error: Only POST method is supported", 405);
                }

            } catch (Exception e) {
                sendErrorResponse(exchange, "Error: " + e.getMessage(), 500);
            }
        }

        // ----------------------------------------------

        private Map<String, String> parsePostParameters(HttpExchange exchange) throws IOException {
            BufferedReader in = new BufferedReader(new InputStreamReader(exchange.getRequestBody(), StandardCharsets.UTF_8));
            String data = in.readLine();
            Map<String, String> params = new HashMap<>();

            // data jest formatu: a=wartosc&b=wartosc
            if (data != null) {
                String[] pairs = data.split("&");
                for (String pair : pairs) {
                    String[] values = pair.split("=");
                    if (values.length == 2) {
                        String key = URLDecoder.decode(values[0], StandardCharsets.UTF_8.toString());
                        String value = URLDecoder.decode(values[1], StandardCharsets.UTF_8.toString());
                        params.put(key, value);
                    }
                }
            }

            return params;
        }

        private void sendErrorResponse(HttpExchange exchange, String response, int status_code) throws IOException {
            exchange.getResponseHeaders().set("Content-Type", "text/plain");
            exchange.sendResponseHeaders(status_code, response.length());
            try (OutputStream os = exchange.getResponseBody()) {
                os.write(response.getBytes());
            }
        }
    }
}
