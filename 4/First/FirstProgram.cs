// Kalina Białek
// lista zadań nr 4: zadanie 2
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

//*******************************************

class Program
{
    public static void Main ()
    {
        Console.WriteLine("KLASA SLOWOFIB\n");
        Console.WriteLine("1: " + new SlowoFib(1).slowo);
        Console.WriteLine("2: " + new SlowoFib(2).slowo);
        Console.WriteLine("3: " + new SlowoFib(3).slowo);
        Console.WriteLine("4: " + new SlowoFib(4).slowo);
        Console.WriteLine("5: " + new SlowoFib(5).slowo);
        Console.WriteLine("6: " + new SlowoFib(6).slowo + "\n");

        //*******************************************

        Console.WriteLine("FOREACH PO SLOWAFIBONACCIEGO DLA 6\n");
        SlowaFibonacciego sf = new SlowaFibonacciego(6);
        foreach(string s in sf)
            Console.WriteLine(s);
        Console.WriteLine("\n");

        //*******************************************

        Console.WriteLine("FOREACH PO SLOWAFIBONACCIEGO DLA 12\n");
        SlowaFibonacciego sf2 = new SlowaFibonacciego(10);
        foreach(string s in sf2)
            Console.WriteLine(s);
        Console.WriteLine("\n");

        //*******************************************

        Console.WriteLine("\nKONIEC\n");
    }
}