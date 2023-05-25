public class konsument implements Runnable
{
    bufor<String> box;
    int stop_work;

    public konsument(bufor<String> b, int sw)
    {
        box = b;
        stop_work = sw;
    }

    void consume(String product)
    {
        System.out.println(product);
    }

    public void run()
    {
        int work_counter = 0;
        while (work_counter < stop_work)
        {
            try
            {
                consume(box.remove());
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (konsument) interrupted.");
            }

            work_counter++;
        }
    }
}
