import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.LinkedList;

public class TotientServer extends Server {
    private Thread operatorThread;

    public TotientServer(int port) {
        super(port);

        // that's a seperate thread for reading from server console
        operatorThread = new Thread(() -> {
            try (BufferedReader operator = new BufferedReader(new InputStreamReader(System.in))) {
                System.out.println("Server running. Type 'quit' to stop.");
                String command;
                while ((command = operator.readLine()) != null) {
                    if ("quit".equalsIgnoreCase(command)) {
                        System.out.println("Quit command received. Stopping server");
                        running = false;

                        try {
                            if (server != null && !server.isClosed()) {
                                server.close();
                            }
                        } catch (IOException e) {
                            System.err.println("Error closing server socket: " + e.getMessage());
                        }

                        break;
                    }
                }
            }
            catch (IOException e) {
                System.err.println("Error reading from operator console: " + e.getMessage());
                running = false;
            }
        });

        operatorThread.setDaemon(true);
        operatorThread.start();
    }

    //-------------------------------------------

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

    private LinkedList<Integer> Euler(int number) {
        LinkedList<Integer> result = new LinkedList<>();

        for (int i = 1; i <= number; i++) {
            if (NWD(i, number) == 1)
                result.add(i);
        }

        return result;
    }

    //--------------------------

    @Override
    protected boolean continueWork() {
        return running;
    }

    @Override
    protected void handleClient(Socket client) {
        try (PrintWriter out = new PrintWriter(new OutputStreamWriter(client.getOutputStream()), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));) {

            out.println("Hi! Provide natural number:");

            String data;
            while ((data = in.readLine()) != null) {      // data == null when client closes connection
                if (!running) {
                    out.println("Server is shutting down. Closing connection.");
                    break;
                }

                if (data == null || data.equals("."))
                    break;

                try {
                    int number = Integer.parseInt(data);
                    if (number <= 0) {
                        out.println("Error: Parameter must be a positive integer");
                        continue;
                    }
                    LinkedList<Integer> response = Euler(number);

                    // Format the list as a space-separated string
                    StringBuilder sb = new StringBuilder();
                    for (Integer value : response) {
                        sb.append(value).append(" ");
                    }
                    out.println(sb.toString().trim());
                }
                catch (NumberFormatException e) {
                    System.out.println("Error: Parameter must be positive integer");
                    out.println("Error: Parameter must be positive integer");
                }
            }

        }
        catch (IOException e) {
            if (running)
                System.err.println("Error during talk: " + e.getMessage());
        }
    }

}
