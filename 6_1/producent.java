public class producent implements Runnable
{
    int generator_num;
    bufor<String> box;
    int stop_work;

    public producent(bufor<String> b, int sw)
    {
        generator_num = 1;
        box = b;
        stop_work = sw;
    }

    String generate()
    {
        String gen = "";
        for (int i = 0; i < generator_num; i++)
        {
            gen += "X";
        }
        generator_num++;
        return gen;
    }

    public void run()
    {
        int work_counter = 0;
        while (work_counter < stop_work)
        {
            try
            {
                box.add(generate());
            }
            catch (InterruptedException e)
            {
                Thread.currentThread().interrupt();
                System.err.println("Thread (producent) interrupted.");
            }

            work_counter++;
        }
    }
}
