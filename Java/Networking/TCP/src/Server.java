import java.net.*;
import java.time.Instant;
import java.io.*;
import java.lang.reflect.Constructor;

public abstract class Server {
    protected int port;
    protected ServerSocket server;
    protected volatile boolean running = false;
    protected Instant startTime;
    protected int clientsServed = 0;

    public Server(int port) {
        this.port = port;

        // register shutdown hook to handle Ctrl+C
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("Shutdown signal received, stopping server gracefully...");
            stop();
        }));
    }

    //----------------------------------------------

    public void run() {
        try {
            // start server
            server = new ServerSocket(port);
            running = true;
            startTime = Instant.now();

            System.out.println("Server works on port " + port);
            System.out.println("Server waiting for clients...");

            // talk with clients
            while (continueWork()) {
                try {
                    server.setSoTimeout(1000); // every 1 second check if continueWork is still true

                    try {
                        Socket client = server.accept();
                        System.out.println("Client connected!");

                        handleClient(client);
                    }
                    catch (SocketTimeoutException e) {
                        continue; // case: we want to check continueWork!
                    }
                }
                catch (IOException e) {
                    if (running)
                        System.err.println("Error during connection: " + e.getMessage());
                }
            }
        }
        catch (Exception e) {
            System.err.println("Server error: " + e.getMessage());
            e.printStackTrace();
        }
        finally {
            stop();
        }
    }

    public void stop() {
        try {
            if (running) {
                System.out.println("Server stopping...");
                running = false;

                if (server != null && !server.isClosed()) {
                    server.close();
                }
            }
        }
        catch (IOException e) {
            System.err.println("Error during closing server: " + e.getMessage());
        }
    }

    //------------------------------------

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: java Server <ServerClassName> <Port> [AdditionalArgs]");
            System.out.println("Examples:");
            System.out.println("  java Server DateServer 8080");
            System.out.println("  java Server EchoServer 8081 60000");
            System.out.println("  java Server TotientServer 8082");
            return;
        }

        String serverClassName = args[0];
        int port;

        try {
            port = Integer.parseInt(args[1]);
        } catch (NumberFormatException e) {
            System.err.println("Invalid port number: " + args[1]);
            return;
        }

        try {
            Class<?> serverClass = Class.forName(serverClassName);

            if (serverClassName.equals("EchoServer") && args.length > 2) {
                // EchoServer requires timeout parameter
                int timeout = Integer.parseInt(args[2]);
                Constructor<?> constructor = serverClass.getConstructor(int.class, int.class);
                Server server = (Server) constructor.newInstance(port, timeout);
                server.run();
            } else {
                // Other servers just need the port
                Constructor<?> constructor = serverClass.getConstructor(int.class);
                Server server = (Server) constructor.newInstance(port);
                server.run();
            }
        } catch (ClassNotFoundException e) {
            System.err.println("Server class not found: " + serverClassName);
        } catch (NumberFormatException e) {
            System.err.println("Invalid additional parameter: " + args[2]);
        } catch (Exception e) {
            System.err.println("Error during creating server: " + e.getMessage());
            e.printStackTrace();
        }
    }

    //------------------------------------

    protected abstract void handleClient(Socket client);
    protected abstract boolean continueWork();
}
