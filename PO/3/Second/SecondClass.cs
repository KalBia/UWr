// Kalina Białek
// lista zadań nr 2: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

//*******************************************
// jeśli wektory w operacjach będą miały różne wymiary, to wyrzucam wyjątek i zwracam pusty wektor lub zero 
// zależnie od funkcji

public class Wektor
{
    float[] store;
    int wymiar;

    public Wektor (int wymiar)
    {
        this.wymiar = wymiar;
        this.store = new float[wymiar];
    }

    public Wektor (int wymiar, float[] store)
    {
        this.store = store;
        this.wymiar = wymiar;
    }

    public void change_value (float value, int index)
    {
        this.store[index] = value;
    }

    public void show_wektor ()
    {
        Console.WriteLine("WEKTOR:");
        for (int i = 0; i < wymiar; i++)
        {
            Console.WriteLine(this.store[i]);
        }
    }

    public static Wektor operator+ (Wektor w1, Wektor w2)
    {
        if (w1.wymiar != w2.wymiar)
        {
            Console.WriteLine("Nie mozna dodac. Wektory maja rozne wymiary.");
            return new Wektor(w1.wymiar);
        }
        
        Wektor wynik = new Wektor(w1.wymiar);
        for (int i = 0; i < w1.wymiar; i++)
        {
            wynik.store[i] = w1.store[i] + w2.store[i];
        }
        return wynik;
    }

    public static float operator* (Wektor w1, Wektor w2)
    {
        if (w1.wymiar != w2.wymiar)
        {
            Console.WriteLine("Nie mozna obliczyc. Wektory maja rozne wymiary.");
            return 0;
        }

        float wynik = 0;
        for (int i = 0; i < w1.wymiar; i++)
        {
            wynik += w1.store[i] * w2.store[i];
        }
        return wynik;
    }

    public static Wektor operator* (Wektor w, float skalar)
    {
        Wektor wynik = new Wektor(w.wymiar);
        for (int i = 0; i < w.wymiar; i++)
        {
            wynik.store[i] = w.store[i] * skalar;
        }
        return wynik;
    }

    public static Wektor operator* (float skalar, Wektor w)
    {
        Wektor wynik = new Wektor(w.wymiar);
        for (int i = 0; i < w.wymiar; i++)
        {
            wynik.store[i] = w.store[i] * skalar;
        }
        return wynik;
    }

    public float norma ()
    {
        float wynik = this * this;
        return MathF.Sqrt(wynik);
    }
}