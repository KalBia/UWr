// Kalina Białek
// lista zadań nr 4: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;
using System.Collections;

//*******************************************
//INTERFEJS
//*******************************************

interface ListCollection<T>
{
    public void push_front(T elem);
    public void push_back(T elem);
    public T pop_front();
    public T pop_back();
    public bool is_empty();

}

//*******************************************
// KOLEKCJA 1: LISTA JEDNOKIERUNKOWA - dla niej tworzę rzeczy z drugiej kropeczki polecenia ^^
//*******************************************

public class ListItemOne<T>
{
    public T value;
    public ListItemOne<T> next;

    public ListItemOne()
    {
        this.value = default(T);
        this.next = default(ListItemOne<T>);
    }

    public ListItemOne(T val)
    {
        this.value = val;
        this.next = default(ListItemOne<T>);
    }

//*************** DOSTĘP INDEKSOWANY
    public T this[int index]
    {
        get
        {
            if (index == 0) 
                return value;
            return this.next[index-1];
        }
    }
}

//*******************************************

public class ListaOne<T> : ListCollection<T>, IEnumerable
{
    public ListItemOne<T> front;

    public ListaOne ()
    {
        this.front = default(ListItemOne<T>);
    }

    public void push_front(T elem)
    {
        if (this.is_empty())
        {
            this.front = new ListItemOne<T>(elem);
        }

        ListItemOne<T> new_item = new ListItemOne<T>(elem);
        
        new_item.next = this.front;
        this.front = new_item;
    }

    public void push_back(T elem) 
    {
        if (this.is_empty())
        {
            this.front = new ListItemOne<T>(elem);
        }

        ListItemOne<T> cursor = this.front;
        while (cursor.next != null) cursor = cursor.next;
        
        cursor.next = new ListItemOne<T>(elem);
    }
    
    public T pop_front()
    {
        if (this.is_empty())
        {
            Console.WriteLine("ListaOne is empty.");
            return default(T);
        }

        T give = this.front.value;
        this.front = this.front.next;
        return give;
    }

    public T pop_back()
    {
        if (this.is_empty())
        {
            Console.WriteLine("ListaOne is empty.");
            return default(T);
        }

        ListItemOne<T> cursor = this.front;
        ListItemOne<T> prev = null;
        T give;
        while (cursor.next != null) 
        {
            prev = cursor;
            cursor = cursor.next;
        }
        
        if (prev == null) // lista była jednoelementowa
        {
            give = this.front.value;
            this.front = null;
            return give;
        }

        prev.next = null;
        give = cursor.value;
        return give;
    }

    public bool is_empty()
    {
        return (this.front == null);
    }

//*************** CZĘŚĆ IENUMERABLE

    public IEnumerator GetEnumerator()
    {
        return new ListEnum<T>(this.front);
    }

//*************** TO STRING

    public override string ToString()
    {
        string res = "";
        ListItemOne<T> cursor = this.front;
        while (cursor != null)
        {
            res += cursor.value.ToString() + "   ";
            cursor = cursor.next;
        }
        return res;
    }

//*************** WŁAŚCIWOŚĆ LENGTH

    public int Length
    {
        get
        {
            int count = 0;
            ListItemOne<T> cursor = this.front;
            while (cursor != null)
            {
                count += 1;
                cursor = cursor.next;
            }
            return count;
        }
    }

}

//*******************************************
// DRUGA KROPECZKA POLECENIA - ENUMERATOR
//*******************************************

class ListEnum<T> : IEnumerator
{
    ListItemOne<T> front;
    ListItemOne<T> current = null;

    public ListEnum(ListItemOne<T> front)
    {
        this.front = front;
    }

    public bool MoveNext()
    {
        if (this.current == null) 
        {
            this.current = this.front;
        }
        else
            this.current = this.current.next;
        
        return this.current != null;
    }

    public void Reset()
    {
        this.current = this.front;
    }

    object IEnumerator.Current
    {
        get
        {
            return Current;
        }
    }

    public T Current
    {
        get
        {
            return current.value;
        }
    }
}

//*******************************************
// KOLEKCJA 2: LISTA DWUKIERUNKOWA
//*******************************************

public class ListItem<T>
{
    public T value;
    public ListItem<T> next;
    public ListItem<T> prev;

    public ListItem()
    {
        this.value = default(T);
        this.next = default(ListItem<T>);
        this.prev = default(ListItem<T>);
    }

    public ListItem(T val)
    {
        this.value = val;
        this.next = default(ListItem<T>);
        this.prev = default(ListItem<T>);
    }
}

//*******************************************
// jeśli lista będzie pusta, to wartości zwracane przez funkcje pop,
// to będą wartości domyślne dla podanego typu T

public class Lista<T> : ListCollection<T>
{
    ListItem<T> first_element;
    ListItem<T> last_element;
    bool check_empty;

    public Lista()
    {
        this.first_element = new ListItem<T>();
        this.last_element = new ListItem<T>();
        this.check_empty = true;
    }

    public void push_front(T elem)
    {
        if (this.is_empty())
        {
            first_element.value = elem;
            last_element.value = elem;

            check_empty = false;
        }
        else
        {
            ListItem<T> new_element = new ListItem<T>(elem);

            new_element.next = first_element;
            first_element.prev = new_element;

            if (last_element.prev == default(ListItem<T>))
            {
                last_element.prev = new_element;
                new_element.next = last_element;
            }

            this.first_element = new_element;
        }
    }

    public void push_back(T elem)
    {
        if (this.is_empty())
        {
            first_element.value = elem;
            last_element.value = elem;

            check_empty = false;
        }
        else
        {
            ListItem<T> new_element = new ListItem<T>(elem);
            
            new_element.prev = last_element;
            last_element.next = new_element;

            if (first_element.next == default(ListItem<T>))
            {
                first_element.next = new_element;
                new_element.prev = first_element;
            }

            this.last_element = new_element;
        }
    }

    public T pop_front()
    {
        if (this.is_empty())
        {
            Console.WriteLine("Lista is empty.");
            return default(T);
        }
        else
        {
            ListItem<T> give = first_element;

            if (first_element.next == default(ListItem<T>))
            {
                check_empty = true;
                this.last_element = new ListItem<T>();
                this.first_element = new ListItem<T>();
                return give.value;
            }

            first_element.next.prev = default(ListItem<T>);
            this.first_element = first_element.next;

            return give.value;
        }
    }

    public T pop_back()
    {
        if (this.is_empty())
        {
            Console.WriteLine("Lista is empty.");
            return default(T);
        }
        else
        {
            ListItem<T> give = last_element;

            if (last_element.prev == default(ListItem<T>))
            {
                check_empty = true;
                this.last_element = new ListItem<T>();
                this.first_element = new ListItem<T>();
                return give.value;
            }

            last_element.prev.next = default(ListItem<T>);
            this.last_element = last_element.prev;

            return give.value;
        }
    }

    public bool is_empty()
    {
        return this.check_empty;
    }
}

