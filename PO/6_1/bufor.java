import java.util.ArrayList;

public class bufor<T>
{
    ArrayList<T> array;
    public int max_size;
    int curr_usage;

    public bufor(int ms)
    {
        array = new ArrayList<T>(ms);
        max_size = ms;
        curr_usage = 0;
    }

    public synchronized void add(T elem) throws InterruptedException
    {
        while (isFull())
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (add) interrupted.");
            }
        }

        array.add(elem);
        curr_usage++;
        notify();
    }

    public synchronized T remove() throws InterruptedException
    {
        while (curr_usage == 0)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (remove) interrupted.");
            }
        }

        curr_usage--;
        return array.remove(0);
    }

    public boolean isEmpty()
    {
        return (curr_usage == 0);
    }

    public boolean isFull()
    {
        return (curr_usage == max_size);
    }
}
