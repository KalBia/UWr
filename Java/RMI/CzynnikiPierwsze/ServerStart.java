package CzynnikiPierwsze;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.LinkedList;

public class ServerStart {
    public static void main(String args[]) {

        try {
            Server server = new Server();
            Rozklad stub = (Rozklad) UnicastRemoteObject.exportObject(server, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("Rozklad", stub);

            System.out.println("The server is now running. Press Ctrl+C to stop.");

            // Keep the application running until manually terminated
            while (true) {
                Thread.sleep(1000);
            }
        } catch (Exception e) {
            System.err.println("Server start exception: " + e.toString());
            e.printStackTrace();
        }

    }
}

class Server implements Rozklad {
    public Server() {}

    public LinkedList<Long> naCzynnikiPierwsze (long x) throws RemoteException {
        LinkedList<Long> czynniki = new LinkedList<>();

        if (x < 0) {
            czynniki.add(-1L);
            x *= -1;
        }

        if (x == 0 || x == 1) {
            czynniki.add(x);
            return czynniki;
        }

        while (x % 2 == 0) {
            czynniki.add(2L);
            x /= 2;
        }

        for(long i = 3; i*i <= x && i*i > 0; i += 2) {

            while (x % i == 0) {
                czynniki.add(i);
                x /= i;
            }
        }

        // prime number case
        if (x > 1) {
            czynniki.add(x);
        }

        return czynniki;
    }
}
