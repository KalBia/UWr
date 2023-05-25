// Kalina Białek
// lista zadań nr 2: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

//*******************************************

class Program
{
    public static void Main()
    {
        Lista<int> L = new Lista<int>();

        Console.WriteLine("Prezentacja klasy Lista<T>, gdy T == int");
        Console.WriteLine("\nPUSTA LISTA...\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(L.is_empty());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());

        L.push_front(7);

        Console.WriteLine("\nLISTA: [ 7 ]\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(L.is_empty());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());

        L.push_back(5);
        L.push_front(8);

        Console.WriteLine("\nLISTA: [ 8 , 5 ]\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(L.is_empty());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());

        L.push_front(6);
        L.push_back(9);

        Console.WriteLine("\nLISTA: [ 6 , 9 ]\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(L.is_empty());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());

        L.push_front(6);
        L.push_back(9);
        L.push_back(17);
        L.push_front(42);

        Console.WriteLine("\nLISTA: [ 42 , 6 , 9 , 17 ]\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(L.is_empty());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(L.pop_front());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(L.pop_back());
        Console.WriteLine("\n[ .is_empty ]");
        Console.WriteLine(L.is_empty());

        Console.WriteLine("\n\nPrezentacja klasy Lista<T>, gdy T == char");
        Lista<char> C = new Lista<char>();

        Console.WriteLine("\nPUSTA LISTA...\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(C.is_empty());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(C.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(C.pop_back());

        C.push_front('a');
        C.push_back('c');
        C.push_back('G');
        C.push_front('K');

        Console.WriteLine("\nLISTA: [ K , a , c , G ]\n");
        Console.WriteLine("[ .is_empty ]");
        Console.WriteLine(C.is_empty());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(C.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(C.pop_back());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(C.pop_back());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(C.pop_front());
        Console.WriteLine("\n[ .pop_front ]");
        Console.WriteLine(C.pop_front());
        Console.WriteLine("\n[ .pop_back ]");
        Console.WriteLine(C.pop_back());
        Console.WriteLine("\n[ .is_empty ]");
        Console.WriteLine(C.is_empty());

        Console.WriteLine("\n\n KONIEC PREZENTACJI");
    }
}