import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.time.Duration;
import java.time.Instant;

public class EchoServer extends Server {
    private long timeout;

    public EchoServer(int port, int miliseconds) {
        super(port);
        this.timeout = miliseconds;
    }

    private long elapsedTime() {
        return Duration.between(startTime, Instant.now()).toMillis();
    }

    //-------------------------

    @Override
    protected boolean continueWork() {
        return elapsedTime() < timeout;
    }

    @Override
    protected void handleClient(Socket client) {
        try (PrintWriter out = new PrintWriter(new OutputStreamWriter(client.getOutputStream()), true);
             BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));) {

            out.println("Hi! Say somehting :)");

            String data;
            while ((data = in.readLine()) != null) {      // data == null when client closes connection
                if (data == null || data.equals("."))
                    break;

                out.println(data);
            }

        }
        catch (IOException e) {
            System.err.println("Error during talk: " + e.getMessage());
        }
    }
}
