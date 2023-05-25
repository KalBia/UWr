// Kalina Białek
// lista zadań nr 4: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

//*******************************************

class Program
{
    public static void Main ()
    {
        // Kolekcja 2 jest zadaniem z jednej z poprzednich list,
        // więc pominę testowanie jej. ;)
        //*******************************************

        Console.WriteLine("\nKOLEKCJA 1: KLASA LISTAONE<T> dla T == int\n");
        ListaOne<int> L = new ListaOne<int>();
        Console.Write("L = []\nPOP_FRONT: ");
        Console.WriteLine(L.pop_front());
        Console.Write("L.is_empty? ");
        Console.WriteLine(L.is_empty());

        L.push_back(17);
        L.push_front(13);
        L.push_back(5);
        Console.Write("\nL = [13, 17, 5]\nPOP_FRONT: ");
        Console.WriteLine(L.pop_front());
        Console.Write("\nL = [17, 5]\nPOP_BACK: ");
        Console.WriteLine(L.pop_back());
        Console.Write("\nL = [17]\nL.is_empty? ");
        Console.WriteLine(L.is_empty());
        
        L.pop_back();
        L.push_back(42);
        L.push_back(19);
        L.push_front(3);
        Console.WriteLine("\nDO KOLEJNYCH POLECEŃ: L = [3, 17, 42, 19]\n");

        //*******************************************

        Console.WriteLine("DOSTEP INDEKSOWY\n");
        Console.Write("0: ");
        Console.WriteLine(L.front[0]);
        Console.Write("1: ");
        Console.WriteLine(L.front[1]);
        Console.Write("2: ");
        Console.WriteLine(L.front[2]);
        Console.Write("3: ");
        Console.WriteLine(L.front[3]);

        //*******************************************

        Console.WriteLine("\nTO STRING\n");
        Console.WriteLine(L.ToString());

        //*******************************************

        Console.WriteLine("\nWLASCIWOSC LENGTH\n");
        Console.WriteLine(L.Length);

        //*******************************************

        Console.WriteLine("\nENUMERATOR\n");
        foreach (int e in L)
            Console.WriteLine(e);

        //*******************************************

        Console.WriteLine("\nKONIEC\n");
    }
}