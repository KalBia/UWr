package CzynnikiPierwsze;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ServerClean {
    public static void main(String args[]) {

        try {
            Registry registry = LocateRegistry.getRegistry();

            try {
                Rozklad stub = (Rozklad) registry.lookup("Rozklad"); // does it even exist?
                System.out.println("Found Rozklad object in registry. Proceeding with removal...");

                registry.unbind("Rozklad");
                System.out.println("Rozklad object was removed.");

            } catch (java.rmi.NotBoundException e) {
                System.out.println("No object named 'Rozklad' was found in the registry.");
            }

        } catch (Exception e) {
            System.err.println("Server removal exception: " + e.toString());
            e.printStackTrace();
        }

    }
}
