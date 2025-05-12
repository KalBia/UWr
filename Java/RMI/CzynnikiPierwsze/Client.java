package CzynnikiPierwsze;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.LinkedList;
import java.util.Scanner;

public class Client {
    private Client() {}

    private static void przedstawCzynniki(LinkedList<Long> response) {
        boolean isFirst = true;
        StringBuilder eq = new StringBuilder();
        for (Long factor : response) {
            if (isFirst) {
                eq.append(factor);
                isFirst = false;
            } else {
                eq.append(" * ").append(factor);
            }
        }

        System.out.println(eq.toString());
    }

    public static void main(String[] args) throws Exception {

        String host = (args.length < 1) ? null : args[0];
        try {
            Registry registry = LocateRegistry.getRegistry(host);
            Rozklad stub = (Rozklad) registry.lookup("Rozklad");

            Scanner scanner = new Scanner(System.in);

            while(true) {
                System.out.println("Provide number for factorization ('exit' to end work): ");
                String input = scanner.nextLine().trim();

                if (input.equals("exit")) {
                    break;
                }

                try {
                    long liczba = Long.parseLong(input);
                    LinkedList<Long> response = stub.naCzynnikiPierwsze(liczba);

                    System.out.println("Factorization: ");
                    przedstawCzynniki(response);
                } catch (NumberFormatException e) {
                    System.out.println("You need to provide number");
                }
            }

            scanner.close();
            System.out.println("Ending work");
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }

    }
}
