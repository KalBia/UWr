import java.net.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.io.*;

public class DateServer extends Server {
    public DateServer(int port) {
        super(port);
    }

    //---------------------------------

    @Override
    protected boolean continueWork() {
        return true;
    }

    @Override
    protected void handleClient(Socket client) {
        // This way of using try (...) closes OutputStream after running this block of code
        // what automatically closes the client socket!
        try (PrintWriter out = new PrintWriter(new OutputStreamWriter(client.getOutputStream()))) {

            Date now = new Date();
            SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy HH:mm:ss");
            String formattedNow = formatter.format(now);

            out.println("Current server time and date: " + formattedNow);

        }
        catch (IOException e) {
            System.err.println("Error during talk: " + e.getMessage());
        }
    }
}
