// Kalina Białek
// lista zadań nr 4: zadanie 2
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;
using System.Collections;

//*******************************************

public class SlowoFib
{
    public string slowo;

    public SlowoFib(int which)
    {
        if (which == 1)
            this.slowo = "b";
        else if (which == 2)
            this.slowo = "a";
        else
        {
            string result = "";
            string help1 = "b";
            string help2 = "a";
            while (which > 2)
            {
                result = help2 + help1;
                help1 = help2;
                help2 = result;
                which -= 1;
            }
            this.slowo = result;
        }
    } 
}

//*******************************************

public class SlowaFibonacciego : IEnumerable
{
    int how_many;

    public SlowaFibonacciego (int x)
    {
        this.how_many = x;
    }

    public IEnumerator GetEnumerator ()
    {
        return new FiboEnum(how_many);
    }
}

//*******************************************

public class FiboEnum : IEnumerator
{
    int how_many;
    int which = 0;

    public FiboEnum (int x) 
    {
        this.how_many = x;
    }

    public bool MoveNext ()
    {
        which++;
        return (this.which <= this.how_many);
    }

    public void Reset ()
    {
        which = 0;
    }

    object IEnumerator.Current
    {
        get
        {
            return Current;
        }
    }

    public string Current
    {
        get
        {
            SlowoFib result = new SlowoFib(which);
            return result.slowo;
        }
    }
}

//*******************************************