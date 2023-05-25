// Kalina Białek
// lista zadań nr 2: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

class Program
{
    public static void Main ()
    {
        Console.WriteLine("Prezentacja klasy Wektor.");
        
        Wektor w0 = new Wektor(2);
        Wektor w1 = new Wektor(4);
        float[] tab = {1.2F, 4.5F, 7.3F, 3.9F};
        Wektor w2 = new Wektor(4, tab);
        float skalar = 2.0F;

        Console.WriteLine("\nSKALAR:");
        Console.WriteLine(skalar);

        Console.WriteLine("\nPUSTY WEKTOR");
        Console.WriteLine("[ .show_wektor ]");
        w1.show_wektor();

        w0.change_value(1.7F, 0);
        w0.change_value(4.2F, 1);

        w1.change_value(4.3F, 0);
        w1.change_value(5.2F, 1);
        w1.change_value(6.7F, 2);
        w1.change_value(7.1F, 3);

        Console.WriteLine("\nW0...");
        w0.show_wektor();
        Console.WriteLine("\nW1...");
        w1.show_wektor();
        Console.WriteLine("\nW2...");
        w2.show_wektor();

        Console.WriteLine("\nSUMA WEKTOROW W0 I W1");
        (w0+w1).show_wektor();
        Console.WriteLine("\nSUMA WEKTOROW W1 I W2");
        (w1+w2).show_wektor();

        Console.WriteLine("\nILOCZYN SKALARNY WEKTOROW W0 I W1");
        Console.WriteLine(w0*w1);
        Console.WriteLine("\nILOCZYN SKALARNY WEKTOROW W1 I W2");
        Console.WriteLine(w1*w2);

        Console.WriteLine("\nILOCZYN WEKTORA W1 I SKALARA");
        (w1*skalar).show_wektor();
        Console.WriteLine("\nILOCZYN SKALARA I WEKTORA W1");
        (skalar*w1).show_wektor();

        Console.WriteLine("\nMETODA NORMA DLA WEKTORA W1");
        Console.WriteLine(w1.norma());

        Console.WriteLine("\n\nKONIEC PREZENTACJI");
    }
}