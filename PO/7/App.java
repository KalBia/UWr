import java.io.File;
import javax.swing.JFrame;

public class App {
    public static void main(String[] args) throws Exception {
        
        String file_name = args[0];
        String type_name = args[1];

        // A COZ TO JEST TO NIZEJ? 
        // Pracuje w VSCode, na plikach do javy sciagnietych szczegolnie dla niego. Z jakiegos powodu pojawiaja
        // sie problemy w wersjach javy podczas wywolywania programow przez terminal...
        // Mam nadzieje, ze u Pana bedzie dzialac normalnie. Jakby co, zostawiam ponizej reczne wpisywanie.
        //String file_name = "czasopismo.txt";
        //String type_name = "czasopismo";
        
        JFrame frame;
        File f = new File(file_name);

        if (type_name == "ksiazka")
        {
            
            ksiazka K = new ksiazka();

            if (f.isFile())
            {
                K.readFromFile(f);
                System.out.println("Ksiazka z pliku:\n" + K.toString() + "\n");
                frame = new edit_ksiazka(K, f);
            }
            else
            {
                System.out.println("Nie ma takiego pliku. Tworzę nową książkę\n");
                frame = new edit_ksiazka(K, f);
            }
        }
        else if (type_name == "poradnik")
        {
            poradnik K = new poradnik();

            if (f.isFile())
            {
                K.readFromFile(f);
                System.out.println("Poradnik z pliku:\n" + K.toString() + "\n");
                frame = new edit_poradnik(K, f);
                K.writeToFile(f);
            }
            else
            {
                System.out.println("Nie ma takiego pliku. Tworzę nowy poradnik\n");
                frame = new edit_poradnik(K, f);
                K.writeToFile(f);
            }
        }
        else if (type_name == "czasopismo")
        {
            czasopismo K = new czasopismo();

            if (f.isFile())
            {
                K.readFromFile(f);
                System.out.println("Czasopismo z pliku:\n" + K.toString() + "\n");
                frame = new edit_czasopismo(K, f);
                K.writeToFile(f);
            }
            else
            {
                System.out.println("Nie ma takiego pliku. Tworzę nowe czasopismo\n");
                frame = new edit_czasopismo(K, f);
                K.writeToFile(f);
            }
        }
        else
        {
            System.err.println("Podano błędny typ obiektu");
        }
    }
}
