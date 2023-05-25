// Kalina Białek
// lista zadań nr 3: zadanie 1
// .Net 7.0.201
// projekt w VSCode
//*******************************************

using System;

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

public class Lista<T>
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